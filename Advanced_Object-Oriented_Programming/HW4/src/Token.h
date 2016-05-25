#ifndef __TOEKN_H__
#define __TOEKN_H__

#include <string>
using namespace std;

class Token {
  public:
    int tag;
    Token( int t );
    ~Token();
    string toString();

  private:
};

#endif
