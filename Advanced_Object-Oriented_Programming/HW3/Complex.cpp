#include "Complex.h"
#include <cmath>

Complex::Complex(const double re, const double im) {
    real = re;
    imag = im;
}

Complex::Complex(const Complex& c) {
  real = c.real;
  imag = c.imag;
}

Complex& Complex::operator=(const Complex &c) {
  if ( this != &c ) {
    this->real = c.real;
    this->imag = c.imag;
  }
  return *this;
}

Complex Complex::Polar(const double leng, const double arg) {
  this->real = leng * cos(arg);
  this->imag = leng * sin(arg);
  return *this;
}

double Complex::Real() {
  return real;
}

double Complex::Imag() {
  return imag;
}

double Complex::Norm() {
  return real * real + imag * imag;
}

double Complex::Abs() {
  return sqrt(real * real + imag * imag);
}

double Complex::Arg() {
  return atan2(imag, real);
}

Complex Complex::operator++() {     //prefix
  real++;
  imag++;
  return *this;
}

Complex Complex::operator++(int) {  //postfix
  Complex temp(*this);
  operator++();
  return temp;
}

Complex Complex::operator--() {
  real--;
  imag--;
  return *this;
}

Complex Complex::operator--(int) {
  Complex temp(*this);
  operator--();
  return temp;
}

Complex::~Complex() {
}

Complex Polar(const double leng, const double arg){
  return Complex( leng * cos(arg), leng * sin(arg) );
}

double Norm(const Complex& x) {
  return x.real * x.real + x.imag * x.imag;
}

double Abs(const Complex& x) {
  return sqrt( x.real * x.real + x.imag * x.imag );
}

double Arg(const Complex& x) {
  return atan2(x.imag, x.real);
  //return acos( x.real / ( sqrt( x.norm ) ) );
}

Complex operator+(const Complex& x, const Complex& y) {
  return Complex( x.real + y.real, x.imag + y.imag );
}

Complex operator-(const Complex& x, const Complex& y) {
  return Complex( x.real - y.real, x.imag - y.imag );
}

Complex operator*(const Complex& x, const Complex& y) {
  return Complex( x.real * y.real - x.imag * y.imag, x.real * y.imag + y.real * x.imag );
}

Complex operator/(const Complex& x, const Complex& y) {
  return Complex( (x.real * y.real + x.imag * y.imag) / (y.real * y.real + y.imag * y.imag), (x.imag * y.real - x.real * y.imag) / (y.real * y.real + y.imag * y.imag) );
}

Complex operator+=(Complex& x, const Complex& y) {
  return x = operator+(x, y);
}

Complex operator-=(Complex& x, const Complex& y) {
  return x = operator-(x, y);
}

Complex operator*=(Complex& x, const Complex& y) {
  return x = operator*(x, y);
}

Complex operator/=(Complex& x, const Complex& y) {
  return x = operator/(x, y);
}

bool operator==(const Complex& x, const Complex& y) {
  return (x.real == y.real && x.imag == y.imag);
}

bool operator!=(const Complex& x, const Complex& y) {
  return !( x.real == y.real && x.imag == y.imag );
}

ostream& operator<<(ostream& o, const Complex& x) {
  o << "(" << x.real << "," << x.imag << ")";
  return o;
}
