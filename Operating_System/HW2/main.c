#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <signal.h>

#define DEBUG(format, args...)
#define N 5
#define LEFT (i+N-1)%N
#define RIGHT (i+1)%N
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define TRUE 1
#define FALSE 0
typedef pthread_mutex_t semaphore;
typedef int bool;   //C language does not support bool type
int state[N] = {0};
char* output[] = {"Thinking", "  Hungry", "  Eating"};
semaphore mutex;
semaphore s[N];
pthread_t phil_thread[N];
static bool stop = FALSE;

void *philosopher_thread( void *i );
void take_fork( int i );
void put_fork( int i );
void check_CanIeat( int i );
void terminator();
void eat();
void think();

int main( int argc, const char *argv[] ) {
  pthread_mutex_init( &mutex, NULL );   //If attr is NULL, the default mutex attributes are used
  signal( SIGINT, terminator );         //execute terminator func. when char "%c" (Signal TERMIANTE) is detected
  int* phil_index[N];

  for ( int i = 0; i < N; i++ ) {
    pthread_mutex_init( &s[N], NULL );        //initialises the mutex referenced
    phil_index[i] = malloc( sizeof( int ) );  //In each phil_index[i] an address of an int is stored
    *phil_index[i] = i;                       //Let the address of int the phil_index[i] pointing to get the value i
  }

  for ( int i = 0; i < N; i++ ) {
    pthread_create( &phil_thread[i], NULL, philosopher_thread, ( void* )phil_index[i] ); //create thread 1~5
  }

  while ( TRUE && !stop ) {
    pthread_mutex_lock( &mutex );         //while outputing, lock mutex and do so
    for ( int i = 0; i < N; i++ ) {
      printf( "%s   ", output[state[i]] );
    }

    pthread_mutex_unlock( &mutex );       //After output, unlock
    printf( "\n----------------------------------------------------\n" );
    sleep( 1 );
  }

  for ( int i = 0; i < N; i++ ) {
    free( phil_index[i] );
    pthread_join( phil_thread[i], NULL );
  }
  return 0;
}


void* philosopher_thread( void* data ) {
  int i = *( int* )data;
  while ( TRUE && !stop ) {
    think();
    take_fork( i );
    eat();
    put_fork( i );
  }
  printf( "pthread: %d stop\n", i );
  return NULL;
}

void take_fork( int i ) {
  pthread_mutex_lock( &mutex );
  state[i] = HUNGRY;
  check_CanIeat( i );
  pthread_mutex_unlock( &mutex );
  pthread_mutex_lock( &s[i] );
}

void put_fork( int i ) {
  pthread_mutex_lock( &mutex );
  state[i] = THINKING;
  check_CanIeat( LEFT );
  check_CanIeat( RIGHT );
  pthread_mutex_unlock( &mutex );
}

void check_CanIeat( int i ) {
  if ( state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING ) {
    state[i] = EATING;
    pthread_mutex_unlock( &s[i] );
  }
}

void terminator() {
  printf( "\nStopping threads...\n" );
  stop = TRUE;
}

void eat() {
  int num = rand() % 3 + 1;   //eat for at least 1 time unit, at most 3 time unit
  sleep( num );
}

void think() {
  int num = rand() % 3 + 1;   //think for at least 1 time unit, at most 3 time unit
  sleep( num );
}
