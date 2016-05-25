#include <iostream>
#include "Lexer.h"
#include <cstdio>
using namespace std;

int main(int argc, const char *argv[]) {
  Lexer lexer;
  while ( true ) {
    Token t = lexer.scan();
    if ( lexer.endOfFile ) {
      break;
    }
    cout << t.toString() << endl;
  }
  return 0;
}
