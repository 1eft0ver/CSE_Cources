#ifndef __TYPE_H__
#define __TYPE_H__

#include "Word.h"
#include "Tag.h"
using namespace std;

class Type: public Word { //Same meaning as "extend" in java
  public:
    Type( string s, int tag, int w ): Word( s, tag ) { //initialization list : To call the constructor of Word class
      this->width = w;
    }
    ~Type();
    static bool numeric( Type &p );
    static Type max( Type &p1, Type &p2 );
    int width;


  private:
};

bool operator==( const Type &t1, const Type &t2 );

static const Type
     INT( "int", Tag::BASIC, 4 ),
     FLOAT( "float", Tag::BASIC, 8 ),
     CHAR( "char", Tag::BASIC, 1 ),
     BOOL( "bool", Tag::BASIC, 1 );

#endif
