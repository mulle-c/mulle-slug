#ifndef mulle_slugify_h__
#define mulle_slugify_h__

#include "include.h"

#include <stdint.h>

/*
 *  (c) 2023 nat <|ORGANIZATION|>
 *
 *  version:  major, minor, patch
 */
#define MULLE_SLUGIFY_VERSION  ((0 << 20) | (0 << 8) | 1)


static inline unsigned int   mulle_slugify_get_version_major( void)
{
   return( MULLE_SLUGIFY_VERSION >> 20);
}


static inline unsigned int   mulle_slugify_get_version_minor( void)
{
   return( (MULLE_SLUGIFY_VERSION >> 8) & 0xFFF);
}


static inline unsigned int   mulle_slugify_get_version_patch( void)
{
   return( MULLE_SLUGIFY_VERSION & 0xFF);
}

// mulle-c11 feature: MULLE_SLUGIFY__GLOBAL
uint32_t   mulle_slugify_get_version( void);


//
// you get an allocated string back, that you need to mulle_free
//
extern char   *mulle_slugify( char *s);

//
// you get a struct mulle_utf8data, whose characters you need to mulle_free
//
extern struct mulle_utf8data   mulle_slugify_utf8data( struct mulle_utf8data  data,
                                                       struct mulle_allocator *allocator);

/*
 * The versioncheck header can be generated with
 * mulle-project-dependency-versions, but it is optional.
 */
#ifdef __has_include
# if __has_include( "_mulle-slugify-versioncheck.h")
#  include "_mulle-slugify-versioncheck.h"
# endif
#endif

#endif
