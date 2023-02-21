#include <mulle-slugify/mulle-slugify.h>

#include <stdio.h>


int   main( int argc, char *argv[])
{
   char   *s;
   char   *slug;
   int    c;

   mulle_buffer_do( buffer)
   {
      while( (c = getchar()) != EOF)
      {
         if( c == '\n')
         {
            s    = mulle_buffer_extract_string( buffer);
            slug = mulle_slugify( s);
            printf( "%s\n", slug);
            mulle_free( slug);
            mulle_free( s);
            continue;
         }

         mulle_buffer_add_byte( buffer, c);
      }
   }

   return( 0);
}
