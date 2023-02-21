#include "include-private.h"

#include "mulle-slugify.h"

#include <ctype.h>


int   __MULLE_SLUGIFY_ranlib__;


uint32_t   mulle_slugify_get_version( void)
{
   return( MULLE_SLUGIFY_VERSION);
}


static struct map_entry
{
   uint32_t   utf32;
   char       *ascii;
} map[] =
{
#include "map.inc"
};



struct mulle_utf8data   mulle_slugify_utf8data( struct mulle_utf8data  data,
                                                struct mulle_allocator *allocator)
{
   mulle_utf32_t          c;
   mulle_utf32_t          prev;
   mulle_utf8_t           *walk;
   mulle_utf8_t           *sentinel;
   struct mulle_utf8data  slug;
   struct map_entry       *p;
   int                    first;
   int                    last;
   int                    middle;

   if( ! data.characters)
      return( mulle_utf8data_make( NULL, 0));

   //
   // tries to avoid output of -- and trailing or leading -
   // tries to avoid output of leading '#'
   //
   mulle_buffer_do_allocator( buffer, allocator)
   {
      prev     = 0;
      walk     = data.characters;
      sentinel = &data.characters[ data.length];

      while( walk < sentinel)
      {
         c = mulle_utf8_next_utf32character( &walk);
         if( c < 127)
         {
            switch( c)
            {
            case '\0' : continue;
            case ' '  :
            case '\f' :
            case '\n' :
            case '\r' :
            case '\t' :
            case '\v' :
            case '-'  : if( prev && prev != '-')
                        {
                           mulle_buffer_add_byte( buffer, '-');
                           prev = '-';
                        }
                        continue;

//            case '&'  : mulle_buffer_add_string( buffer, "and"); prev = c; continue;
            case '<'  : mulle_buffer_add_string( buffer, "less"); prev = c; continue;
            case '>'  : mulle_buffer_add_string( buffer, "greater"); prev = c; continue;
//            case '|'  : mulle_buffer_add_string( buffer, "or"); prev = c; continue;
            case '$'  : mulle_buffer_add_string( buffer, "dollar"); prev = c; continue;
            case '#'  : mulle_buffer_add_string( buffer, "hash"); prev = c; continue;
            }

            if( ! isprint( c))
               continue;

            if( ispunct( c))
            {
               if( prev && prev != '-')
               {
                  mulle_buffer_add_byte( buffer, '-');
                  prev = '-';
               }
               continue;
            }

            mulle_buffer_add_byte( buffer, c);
            prev = c;
            continue;
         }

         // binary search UTF32 code
         {
            first  = 0;
            last   = (int) ((sizeof( map) / sizeof( map[ 0])) - 1);
            middle = (first + last) / 2;

            while( first <= last)
            {
               p = &map[ middle];
               if( p->utf32 <= c)
               {
                  if( p->utf32 == c)
                  {
                     mulle_buffer_add_string( buffer, p->ascii);
                     prev = c;
                     break;
                  }

                  first = middle + 1;
               }
               else
                  last = middle - 1;

               middle = (first + last) / 2;
            }
         }
      }

      mulle_buffer_add_byte( buffer, 0);
      slug = mulle_data_as_utf8data( mulle_buffer_extract_data( buffer));
   }

   // pretty up slug (last char is zero) at start
   while( slug.length > 1)
   {
      if( slug.characters[ slug.length - 2] != '-')
         break;

      slug.characters[ slug.length - 2] = 0;
      --slug.length;
   }

   return( slug);
}



char   *mulle_slugify( char *s)
{
   struct mulle_utf8data   data;
   struct mulle_utf8data   slug;

   data = mulle_utf8data_make( s, -1);
   slug = mulle_slugify_utf8data( data, NULL);
   return( slug.characters);
}

