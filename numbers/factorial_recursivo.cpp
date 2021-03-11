// EJ10_01.CPP

// Varias definiciones de factorial

#include <iostream.h>

double Fact1(double n) {
  return n ? (Fact1(n - 1) * n) : 1;
}

double Fact2(double n) {
  double m= 1;
  while (n)
    m*= n--;
  return m;
}

void main() {
  cout << Fact1(10.0) << endl;
  cout << Fact2(20.0) << endl;
}