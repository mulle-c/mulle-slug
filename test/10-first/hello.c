#include <mulle-slugify/mulle-slugify.h>

#include <stdio.h>


int   main( int argc, char *argv[])
{
   char   *s;
   char   *slug;

   s    = "VfL Bochum 1848";
   slug = mulle_slugify( s);
   printf( "%s -> %s\n", s, slug);
   mulle_free( slug);

   return( 0);
}
