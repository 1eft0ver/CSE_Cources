#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#define BUFFER_SIZE 1000
#define true 1
#define false 0;

using namespace std;

static int stop = false;

void handler( int signum ) {
  stop = true;
}

int main( int argc, char *argv[] ) {
  signal( SIGINT, handler );
  if ( argc < 2 ) {
    cout << "Please type filename as the first argument." << endl;
    exit( EXIT_FAILURE );
  }
  int fd = open( argv[1], O_RDWR | O_CREAT, 0666 );
  if ( fd == -1 ) {
    cout << "Open file failed." << endl;
    exit( EXIT_FAILURE );
  }

  char *map_ptr = ( char * )mmap( 0, getpagesize(), PROT_WRITE, MAP_SHARED, fd, 0 );
  if ( map_ptr == MAP_FAILED ) {
    close( fd );
    cout << "File mapping failed" << endl;
    exit( EXIT_FAILURE );
  }

  while ( true && !stop ) {
    struct stat fileinfo = {0};
    fstat( fd, &fileinfo );
    int current_size = ( int )fileinfo.st_size;
    char buffer[BUFFER_SIZE];
    cout << "Type string that you want to append into file :'" << argv[1] << "'(Input Ctrl-c to close)" << endl;
    fgets( buffer, sizeof( buffer ), stdin );
    if(stop != true){
      cout << "File updated." << endl;
    }
    int text_len = strlen( buffer );
    lseek( fd, current_size + text_len, SEEK_SET );
    write( fd, "", 1 );
    lseek( fd, 0, SEEK_SET );
    if ( !stop ) {
      sprintf( map_ptr + current_size, "%s", buffer );
    }
  }

  if ( munmap( map_ptr, getpagesize() ) == -1 ) {
    close( fd );
    cout << "Un-mmap file failed." << endl;
    exit( EXIT_FAILURE );
  }
  close( fd );
  cout << "-------------exit--------------" << endl;
  return 0;
}
