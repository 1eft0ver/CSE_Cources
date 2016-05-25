#include "Lexer.h"
#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<ctype.h>
using namespace std;

Lexer::Lexer() {
  line = 1;
  reserve( Word( "if", Tag::IF ) );
  reserve( Word( "else", Tag::ELSE ) );
  reserve( Word( "while", Tag::WHILE ) );
  reserve( Word( "do", Tag::DO ) );
  reserve( Word( "break", Tag::BREAK ) );
  reserve( TRUE );
  reserve( FALSE );
  reserve( INT );
  reserve( CHAR );
  reserve( BOOL );
  reserve( FLOAT );
}

Lexer::~Lexer(){
}

void Lexer::reserve( Word w ) {
  words.insert( {w.lexeme, w} );
}

void Lexer::readch(){
  char i;
  if ( cin.get( i ) )  {
    peek = i;
  }

  else {
    cout << "End of file reached" << endl;
    this->endOfFile = true;
  }
}

bool Lexer::readch( char c ) {
  readch();
  if ( peek != c ) {
    return false;
  }
  peek = ' ';
  return true;
}

Token Lexer::scan() {
  for ( ;; readch() ) {
    if ( this->endOfFile ) {
      return Token( ' ' );
    }

    if ( peek == ' ' || peek == '\t' ) {
      continue;
    }

    else if ( peek == '\n' ) {
      line += 1;
    }

    else {
      break;
    }
  }

  switch ( peek ) {
  case '&':
    if ( readch( '&' ) ) {
      cout << "Token: " << left << setw( 10 ) << "&&";
      return AND;
    }
    else {
      cout << "Token: " << left << setw( 10 ) << "&";
      return Token( '&' );
    }
    break;

  case '|':
    if ( readch( '|' ) ) {
      cout << "Token: " << left << setw( 10 ) << "||";
      return OR;
    }
    else {
      cout << "Token: " << left << setw( 10 ) << "|";
      return Token( '|' );
    }
    break;

  case '=':
    if ( readch( '=' ) ) {
      cout << "Token: " << left << setw( 10 ) << "==";
      return EQ;
    }
    else {
      cout << "Token: " << left << setw( 10 ) << "=";
      return Token( '=' );
    }
    break;

  case '!':
    if ( readch( '=' ) ) {
      cout << "Token: " << left << setw( 10 ) << "!=";
      return NE;
    }
    else {
      cout << "Token: " << left << setw( 10 ) << "!";
      return Token( '!' );
    }
    break;

  case '<':
    if ( readch( '=' ) ) {
      cout << "Token: " << left << setw( 10 ) << "<=";
      return LE;
    }
    else {
      cout << "Token: " << left << setw( 10 ) << "<";
      return Token( '<' );
    }
    break;

  case '>':
    if ( readch( '=' ) ) {
      cout << "Token: " << left << setw( 10 ) << ">=";
      return GE;
    }
    else {
      cout << "Token: " << left << setw( 10 ) << ">";
      return Token( '>' );
    }
    break;
  }

  if ( isdigit( peek ) ) {
    int v = 0;
    do {
      v = 10 * v + ( peek - '0' );
      readch();
    }
    while ( isdigit( peek ) );
    if ( peek != '.' ) {
      cout << "Token: " << left << setw( 10 ) << v;
      return Num( v );
    }
    float x = v;
    float d = 10;
    for ( ;; ) {
      readch();
      if ( !isdigit( peek ) ) {
        break;
      }
      x = x + ( ( peek - '0' ) / d );
      d = d * 10;
    }
    cout << "Token: " << left << setw( 10 ) << x;
    return Real( x );
  }
  if ( isalpha( peek ) ) {
    string buffer = "";
    do {
      buffer += peek;
      readch();
    }
    while ( isdigit( peek ) || isalpha( peek ) );
    map<string, Word>::iterator it = words.find( buffer );
    if ( it != words.end() ) {
      cout << "Token: " << left << setw( 10 ) << buffer;
      return it->second;
    }
    Word w( buffer, Tag::ID );
    words.insert( {buffer, w} );
    cout << "Token: " << left << setw( 10 ) << buffer;
    return w;
  }

  Token tok( peek );
  cout << "Token: " << left << setw( 10 ) << peek;
  peek = ' ';
  return tok;
}
