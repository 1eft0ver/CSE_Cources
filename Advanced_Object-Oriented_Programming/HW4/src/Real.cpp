#include "Real.h"

Real::~Real() {
}

string Real::toString() {
  return "" + to_string( value );
}
