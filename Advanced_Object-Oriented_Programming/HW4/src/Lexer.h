#ifndef __LEXER_H__
#define __LEXER_H__

#include "Tag.h"
#include "Word.h"
#include "Token.h"
#include "Type.h"
#include "Num.h"
#include "Real.h"
#include <map>
using namespace std;

class Lexer {
  public:
    int line;
    char peek = ' ';
    map<string, Word> words; //對應於Hashtable
    bool endOfFile = false;
    Lexer();
    ~Lexer();
    void reserve( Word w );
    void readch();
    bool readch( char c );
    Token scan();

  private:
};

#endif
