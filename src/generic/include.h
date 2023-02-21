#ifndef mulle_slugify_include_h__
#define mulle_slugify_include_h__

/* DO:    #include this files in public headers.

   DONT:  #include this files in private headers.
          #include this file directly in sources.
          #import this file anywhere (except in import.h)
 */


/* This is a central include file to keep dependencies out of the library
   C files. It is usually included by .h files only.

   As the name "include.h" is standardized across mulle-sde projects,
   .c and .h files are now  motile. They can be moved to other projects and
   don't need to be edited.

   If you delete it, it will not be regenerated.
*/

/*
 * Include the header file generated by mulle-sde reflect.
 */

#include "_mulle-slugify-include.h"

// mulle-c11::feature...
// #ifdef MULLE_SLUGIFY_BUILD
// # define MULLE_SLUGIFY_EXTERN_GLOBAL  MULLE_C_GLOBAL
// #else
// # define MULLE_SLUGIFY_EXTERN_GLOBAL  MULLE_C_EXTERN_GLOBAL
// #endif

/* You can add some more include statements here */

#endif
