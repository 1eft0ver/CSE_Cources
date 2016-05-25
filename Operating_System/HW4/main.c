#include<stdio.h>
#include "mm.h"
int main( void )
{
  int temp, size, newsize, *ptr, *array_ptr, *new_array_ptr;
  printf( "mymalloc: Input an integer to test if the memory allocation funtion works fine : " );
  scanf( "%d%*c", &temp );
  ptr = ( int * )mymalloc( sizeof( int ) );
  *ptr = temp;

  if ( ptr == NULL ) {
    printf( "mymalloc: memory allocation failed!\n" );
  }
  else {
    printf( "memory address: %p\n", ptr );
    printf( "           num: %d\n", *ptr );
  }


  printf( "mycalloc: Input the size of the array to test mycalloc:" );
  scanf( "%d%*c", &size );
  array_ptr = ( int * )mycalloc( size, sizeof( int ) );
  if ( array_ptr == NULL ) {
    printf( "mycalloc: memory allocation failed!\n" );
  }
  else {
    printf( "original array memory address: %p\n", array_ptr );
    for ( int i = 0; i < size; i++ ) {
      printf( "Input data:array[%d]:", i );
      scanf( "%d", &array_ptr[i] );
    }
    for ( int i = 0; i < size; i++ ) {
      printf( "  original array[%d]:%d\n", i, array_ptr[i] );
    }
  }


  printf( "myrealloc: Input the new size of the array to test realloc:" );
  scanf( "%d%*c", &newsize );
  new_array_ptr = ( int * )myrealloc( array_ptr, sizeof( int ) * newsize );
  if ( new_array_ptr == NULL ) {
    printf( "myrealloc: memory allocation failed!\n" );
  }
  else  {
    printf( "new array memory address: %p\n", new_array_ptr );
    for ( int i = size; i < newsize; i++ )  {
      printf( "Input data:new array[%d]:", i );
      scanf( "%d", &new_array_ptr[i] );
    }
    for ( int i = 0; i < newsize; i++ ) {
      printf( "           new array[%d]:%d\n", i, new_array_ptr[i] );
    }
  }

  printf( "myfree: Now free all of the allocated memories\n" );
  myfree( new_array_ptr );
  myfree( ptr );
  printf("All allocated memories freed.\n");
  return 0;
}
