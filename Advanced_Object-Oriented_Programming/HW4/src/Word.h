#ifndef __WORD__H__
#define __WORD__H__

#include "Token.h"
#include "Tag.h"
using namespace std;

class Word: public Token {  //Same meaning as "extend" in java
  public:
    string lexeme = "";
    Word( string s, int tag ): Token( tag ) {  //initialization list : To call the constructor of Token class
      this->lexeme = s;
    }
    ~Word();
    string toString();
    
  private:
};

static const Word
     AND( "&&", Tag::AND ),
     OR( "||", Tag::OR ),
     EQ( "==", Tag::EQ ),
     NE( "!=", Tag::NE ),
     LE( "<=", Tag::LE ),
     GE( ">=", Tag::GE ),
     MINUS( "minus", Tag::MINUS ),
     TRUE( "true", Tag::TRUE ),
     FALSE( "false", Tag::FALSE ),
     temp( "t", Tag::TEMP );


#endif
