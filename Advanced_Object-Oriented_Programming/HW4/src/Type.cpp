#include "Type.h"

Type::~Type(){
}

bool Type::numeric( Type &p ) {
  if ( p == CHAR || p == INT || p == FLOAT ) {
    return true;
  }

  else {
    return false;
  }
}

Type Type::max( Type &p1, Type &p2 ) {
  if ( p1 == FLOAT || p2 == FLOAT ) {
    return FLOAT;
  }

  else if ( p1 == INT || p2 == INT ) {
    return INT;
  }

  else {
    return CHAR;
  }
}

bool operator==( const Type &t1, const Type &t2 )
{
  return t1.lexeme == t2.lexeme && t1.tag == t2.tag && t1.width == t2.width;
}
