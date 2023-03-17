#include <iostream>
#ifndef CONTEST
#include "fullratio.hpp"
#endif

using namespace std;

rational::rational (int n, int d) {
  nom = n;
  den = d;
};

rational operator + (const rational &x, const rational &y) {
  int a = x.nom*y.den + y.nom*x.den, b = x.den*y.den;
  if (a * b > 0) {
    return rational(abs(a), abs(b));
  }
  else {
    return rational(-abs(a), abs(b));
  }
};

rational operator - (const rational &x, const rational &y) {
  int a = x.nom*y.den - y.nom*x.den, b = x.den*y.den;
  if (a * b > 0) {
    return rational(abs(a), abs(b));
  }
  else {
    return rational(-abs(a), abs(b));
  }
};

rational operator * (const rational &x, const rational &y) {
  if (x.nom*y.den*y.nom*x.den > 0) {
    return rational(abs(x.nom*y.nom), abs(x.den*y.den));
  }
  else {
    return rational(-abs(x.nom*y.nom), abs(x.den*y.den));
  }
};

rational operator / (const rational &x, const rational &y) {
  if (x.nom*x.den*y.nom*y.den > 0) {
    return rational(abs(x.nom*y.den), abs(x.den*y.nom));
  }
  else {
    return rational(-abs(x.nom*y.den), abs(x.den*y.nom));
  }
};

int rational::gcd (int a, int b) {
  a = abs(a); b = abs(b);
  if (b == 0) return a;
  return rational::gcd(b, a % b);
};

ostream& operator << (ostream &out, const rational &x) {
  int c = rational::gcd(x.nom, x.den);
  if (x.nom * x.den > 0) {
    out << abs(x.nom)/c << "/" << abs(x.den)/c;
  }
  else {
    out << -abs(x.nom)/c << "/" << abs(x.den)/c;
  }
  return out;
};

