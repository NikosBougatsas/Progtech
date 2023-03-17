#ifndef CONTEST
#include "babyratio.hpp"
#endif
#include <iostream>

using namespace std;

rational::rational (int n, int d) {
  nom = n; den = d;
};

rational rational::add (rational r) {
  int a = nom*r.den + r.nom*den, b = den*r.den;
  if (a * b > 0) {
    return rational(abs(a), abs(b));
  }
  else {
    return rational(-abs(a), abs(b));
  }
};

rational rational::sub (rational r) {
  int a = nom*r.den - r.nom*den, b = den*r.den;
  if (a * b > 0) {
    return rational(abs(a), abs(b));
  }
  else {
    return rational(-abs(a), abs(b));
  }
};

rational rational::mul (rational r) {
  int a = nom*r.nom, b = den*r.den;
  if (a * b > 0) {
    return rational(abs(a), abs(b));
  }
  else {
    return rational(-abs(a), abs(b));
  }
};

rational rational::div (rational r) {
  int a = nom*r.den, b = den*r.nom;
  if (a * b > 0) {
    return rational(abs(a), abs(b));
  }
  else {
    return rational(-abs(a), abs(b));
  }
};

int rational::gcd(int a, int b) {
  a = abs(a); b = abs(b);
  if (b == 0) return a;
  return rational::gcd(b, a % b);
};

void rational::print () {
  int c = gcd(nom, den);
  if (nom * den > 0) {
    cout << abs(nom)/c << "/" << abs(den)/c;
  }
  else {
    cout << -abs(nom)/c << "/" << abs(den)/c;
  }
};

