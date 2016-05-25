#ifndef __MY_MM_H_INCLUDED__
#define __MY_MM_H_INCLUDED__
#define NALLOC 1024
#include <string.h>
#include <stddef.h>
typedef long Align; /* for alignment to long boundary */
typedef union header   /* block header */
{
  struct
  {
    union header *next; /* next block if on free list */
    unsigned size; /* size of this block */
  } s;
  Align x; /* force alignment of blocks */
} Header;

Header *morecore( size_t nu );
void *mymalloc( size_t size );
void *mycalloc( size_t nmemb, size_t size );
void *myrealloc( void *ptr, size_t size );
void myfree( void *ptr );

#endif
