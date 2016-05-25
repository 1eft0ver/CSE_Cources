#include "mm.h"
static Header base;           // Used to get an initial member for free list
static Header *freep = NULL;  // Free list starting point


Header *morecore(size_t nunits) {

  void *freemem;    // The address of the newly created memory
  Header *insertp;  // Header ptr for integer arithmatic and constructing header
  void *sbrk( int );

    if (nunits < NALLOC) {
    nunits = NALLOC;
  }
    freemem = sbrk(nunits * sizeof(Header));

  if (freemem == (void *) -1) {
    return NULL;
  }


  insertp = (Header *) freemem;
  insertp->s.size = nunits;

    myfree((void *) (insertp + 1));

    return freep;
}

void *mymalloc(size_t nbytes) {

  Header *currp;
  Header *prevp;
  unsigned nunits;

  nunits = ((nbytes + sizeof(Header) - 1) / sizeof(Header)) + 1;

  if (freep == NULL) {

    base.s.next = &base;
    base.s.size = 0;

    freep = &base;
  }

  prevp = freep;
  currp = prevp->s.next;

  for (; ; prevp = currp, currp = currp->s.next) {

    if (currp->s.size >= nunits) {

      if (currp->s.size == nunits) {
      prevp->s.next = currp->s.next;
      }

      else {
      currp->s.size -= nunits;
      currp += currp->s.size;
      currp->s.size = nunits;
      }

      freep = prevp;
      return (void *) (currp + 1);

    }

    if (currp == freep) {

      if ((currp = morecore(nunits)) == NULL) {
      return NULL;
      }
    }
  }
}


void *myrealloc( void *oldptr, size_t newsize )
{
  if ( oldptr == NULL ) {
    return mymalloc( newsize );
  }
  if ( newsize == 0 ) {
    myfree( oldptr );
    return NULL;
  }
  Header *p = ( Header * )oldptr - 1;
  size_t old_mem_size = ( p->s.size - 1 ) * sizeof( Header );
  void *newptr = mymalloc( newsize );
  if ( old_mem_size < newsize ) {
    memcpy( newptr, oldptr, old_mem_size );
  }
  else {
    memcpy( newptr, oldptr, newsize );
  }
  myfree( oldptr );
  return newptr;
}

void *mycalloc( size_t nmemb, size_t size ) {
  void *ptr = mymalloc( size * nmemb );
  memset( ptr, 0, size * nmemb );
  return ptr;
}

void myfree(void *ptr) {

  Header *insertp, *currp;
  insertp = ((Header *) ptr) - 1;

  for (currp = freep; !((currp < insertp) && (insertp < currp->s.next)); currp = currp->s.next) {
    if ((currp >= currp->s.next) && ((currp < insertp) || (insertp < currp->s.next))) {
      break;
    }
  }

  if ((insertp + insertp->s.size) == currp->s.next) {
    insertp->s.size += currp->s.next->s.size;
    insertp->s.next = currp->s.next->s.next;
  }
  else {
    insertp->s.next = currp->s.next;
  }


  if ((currp + currp->s.size) == insertp) {
    currp->s.size += insertp->s.size;
    currp->s.next = insertp->s.next;
  }
  else {
    currp->s.next = insertp;
  }

  freep = currp;
}
