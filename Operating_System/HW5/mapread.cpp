#include <cstdlib>
#include <iostream>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#define true 1
#define false 0;

using namespace std;

static int stop = false;

void handler( int signum )
{
  stop = true;
}

int main( int argc, const char *argv[] ) {
  signal( SIGINT, handler );
  if ( argc < 2 ) {
    cout << "Please type filename as the first argument." << endl;
    exit( EXIT_FAILURE );
  }

  int fd = open( argv[1], O_RDONLY );
  while ( 1 && !stop ) {
    if ( fd == -1 ) {
      cout << "Open file failed." << endl;
      exit( EXIT_FAILURE );
    }

    struct stat fileInfo = {0};
    if ( fstat( fd, &fileInfo ) == -1 ) {
      cout << "Get file information failed." << endl;
      exit( EXIT_FAILURE );
    }

    if ( fileInfo.st_size == 0 ) {
      cout << "File is empty." << endl;
      exit( EXIT_FAILURE );
    }

    char *map = (char *)mmap( NULL, getpagesize(), PROT_READ, MAP_SHARED, fd, 0 );
    if ( map == MAP_FAILED ) {
      close( fd );
      cout << "mmap failed." << endl;
      exit( EXIT_FAILURE );
    }

    cout << "file:'" << argv[1] << "':(Press Ctrl-c to close)";
    cout << "\n------File contents start------" << endl;
    for ( int i = 0; i < fileInfo.st_size; i++ ) {
      cout << map[i];
    }
    cout << "-------File contents end-------" << endl;
    cout << "Show file contents again in 3 seconds......" << endl << endl;
    if ( munmap( map, fileInfo.st_size ) == -1 ) {
      close( fd );
      cout << "munmap failed" << endl;
      exit( EXIT_FAILURE );
    }

    sleep(3);
  }
  close( fd );
  cout << "\n-------------exit--------------" << endl;
  return 0;
}
