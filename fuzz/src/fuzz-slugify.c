//
// fuzz-slugify.c — fuzz mulle_buffer_add_slugified_utf8data for crashes
//
// Feeds valid UTF-8 sequences (including edge cases like empty code points,
// all-unmapped inputs, very long inputs) into the slugifier and checks it
// does not crash, does not produce slug-unsafe characters, and the output
// is NUL-terminated.
//
// NOTE: mulle-utf asserts on malformed UTF-8 in debug builds (by design).
// This fuzzer validates UTF-8 before feeding it to the slugifier.
//
#include "mulle-slug.h"

#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>


static int   is_valid_utf8( const uint8_t *data, size_t size)
{
   const uint8_t   *end;
   uint8_t          c;
   int              extra;

   end = data + size;
   while( data < end)
   {
      c = *data++;
      if( c < 0x80)
      {
         continue;
      }
      else if( (c & 0xE0) == 0xC0)
         extra = 1;
      else if( (c & 0xF0) == 0xE0)
         extra = 2;
      else if( (c & 0xF8) == 0xF0)
         extra = 3;
      else
         return( 0); // invalid start byte

      if( data + extra > end)
         return( 0); // truncated

      while( extra--)
      {
         if( (*data & 0xC0) != 0x80)
            return( 0); // invalid continuation
         data++;
      }
   }
   return( 1);
}


int   LLVMFuzzerTestOneInput( const uint8_t *data, size_t size)
{
   struct mulle_utf8data   input;
   char                    *slug;
   char                    *p;

   if( ! size)
      return( 0);

   // skip invalid UTF-8 — mulle-utf asserts on it (by design)
   if( ! is_valid_utf8( data, size))
      return( 0);

   input = mulle_utf8data_make( (char *) data, size);

   // test the allocating path
   mulle_buffer_do( buffer)
   {
      mulle_buffer_add_slugified_utf8data( buffer, input);
      mulle_buffer_make_string( buffer);

      slug = mulle_buffer_get_string( buffer);
      if( ! slug)
         return( 0);

      // verify output properties:
      // 1. must be NUL-terminated (mulle_buffer_make_string guarantees this)
      // 2. must not contain slug-unsafe characters
      for( p = slug; *p; p++)
      {
         unsigned char c = (unsigned char) *p;

         // only allow: alnum, '-'
         // (transliterations may produce multi-letter ASCII like "AE", "oe" etc.)
         if( c >= 128)
            __builtin_trap(); // non-ASCII in output is a bug
         if( ! isalnum( c) && c != '-')
            __builtin_trap(); // slug-unsafe char in output
      }

      // 3. must not start or end with '-'
      if( slug[0] == '-')
         __builtin_trap();
      if( p > slug && p[-1] == '-')
         __builtin_trap();

      // 4. must not contain "--"
      if( strstr( slug, "--"))
         __builtin_trap();
   }

   return( 0);
}
