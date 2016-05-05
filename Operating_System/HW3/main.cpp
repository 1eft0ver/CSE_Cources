#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <signal.h>
#include <string>
#include <iostream>
using namespace std;

#define N 5
#define LEFT (i+N-1)%N
#define RIGHT (i+1)%N
#define THINKING 0
#define HUNGRY 1
#define EATING 2
typedef pthread_mutex_t semaphore;
string output[] = {"Thinking", "  Hungry", "  Eating"};
pthread_t phil_thread[N];
static bool stop = false;

void *philosopher_thread(void *);
void take_fork(int);
void put_fork(int);
void terminator(int);
void eat();
void think();

class monitor {
  private:
    semaphore mutex;
    int state[N];
    pthread_cond_t cond[N];
  public:
    monitor();
    void mutex_lock();
    void mutex_unlock();
    void check_CanIeat(int);
    void print();
    void set_thinking(int);
    void set_hungry(int);
    void set_eating(int);
    void send_signal(int);
} philosophers;

int main(int argc, const char *argv[]) {
  signal( SIGINT, terminator );
  int *phil_index[N];

  for (int i = 0; i < N; i++) {
    phil_index[i] = (int *)malloc( sizeof( int ) );   //In each phil_index[i] an address of an int is stored
    *phil_index[i] = i;                                 //Let the address of phil_index[i] pointing to get the value i
  }

  for ( int i = 0; i < N; i++ ) {
    pthread_create( &phil_thread[i], NULL, philosopher_thread, ( void * )phil_index[i] ); //create thread 1~5
  }
  while ( true && !stop ) {
    philosophers.print();              //Simulating philosophers dining situation and print it out
  }

  for ( int i = 0; i < N; i++ ) {
    free( phil_index[i] );                  //free threads
    pthread_join( phil_thread[i], NULL );
  }

  return 0;
}

monitor::monitor() {                      //Constructor - Initialization
  pthread_mutex_init( &mutex, NULL );     //initialize mutex
  for ( int i = 0; i < N; i++ )
  {
    pthread_cond_init( &cond[i], NULL );  //initialize condition variable
    state[i] = 0;                         //initialize state of threads
  }
}

void monitor::mutex_lock() {
  pthread_mutex_lock( &mutex );
}

void monitor::mutex_unlock() {
  pthread_mutex_unlock( &mutex );
}

void monitor::check_CanIeat(int i) {
  if ( state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING )
  {
    state[i] = EATING;
  }
  else
  {
    pthread_cond_wait( &cond[i], &mutex );
  }
}

void monitor::print() {
  this->mutex_lock();                 //while outputing, lock mutex first then do so
  for ( int i = 0; i < N; i++ ) {
    cout << output[state[i]] << "   ";
  }
  this->mutex_unlock();               //After output, unlock
  cout << endl << "----------------------------------------------------" << endl;
  sleep( 1 );
}

void monitor::set_thinking(int i) {
  state[i] = THINKING;
}

void monitor::set_hungry(int i) {
  state[i] = HUNGRY;
}

void monitor::set_eating(int i) {
  state[i] = EATING;
}

void monitor::send_signal(int i) {
  pthread_cond_signal(&cond[i]);
}

void* philosopher_thread(void* data) {
  int i = *( int* )data;
  while ( true && !stop ) {
    think();
    take_fork(i);
    eat();
    put_fork(i);
  }
  cout << "pthread: " << i << " stop" << endl;
  return NULL;
}

void take_fork(int i) {
  philosophers.mutex_lock();
  philosophers.set_hungry(i);
  philosophers.check_CanIeat(i);
  philosophers.mutex_unlock();
}

void put_fork(int i) {
  philosophers.mutex_lock();
  philosophers.set_thinking(i);
  philosophers.send_signal(LEFT);
  philosophers.send_signal(RIGHT);
  philosophers.mutex_unlock();
}

void terminator(int signum) {
  cout << endl << "Stopping threads..." << endl;
  stop = true;
}

void eat() {
  int num = rand() % 3 + 1;   //eat for at least 1 time unit, at most 3 time unit
  sleep( num );
}

void think() {
  int num = rand() % 3 + 1;   //think for at least 1 time unit, at most 3 time unit
  sleep( num );
}
