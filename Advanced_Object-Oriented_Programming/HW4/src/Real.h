#ifndef __REAL_H__
#define __REAL_H__

#include "Token.h"
#include "Tag.h"
using namespace std;

class Real: public Token {
  public:
    Real( float v ): Token( Tag::REAL ) {
      this->value = v;
    }
    ~Real();
    string toString();
    float value;

  private:
};

#endif
