#ifndef __NUM_H__
#define __NUM_H__

#include "Token.h"
#include "Tag.h"
using namespace std;

class Num: public Token {
  public:
    int value;
    Num( int v ): Token( Tag::NUM ) {
      this->value = v;
    }
    ~Num();
    string toString();

  private:
};

#endif
