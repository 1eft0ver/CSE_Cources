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
  real = c.real;
  imag = c.imag;
}

Complex Complex::Polar(const double leng, const double arg) {

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
  return sqrt(Norm());
}

double Complex::Arg() {

}

Complex Complex::operator++() {
  
}

Complex Complex::operator++(int) {

}

Complex Complex::operator--() {

}

Complex Complex::operator--(int) {

}

Complex::~Complex() {

}
