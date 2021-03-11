//Ej10_14.cpp

#include <cmath>  // función log
#include <iostream>  // cout

const unsigned int MaxTaulaLog2=20;
double TaulaLog2[MaxTaulaLog2];

void InitLog() {
  TaulaLog2[0] = 0; // en realidad es -inf.
  for(unsigned int i=1; i<MaxTaulaLog2; i++) {
    TaulaLog2[i]= log(double(i))/log(2.0);     
  }
}

inline double Log2(unsigned int n) {
  if (n < 20) return TaulaLog2[n];
  else return log(double(n))/log(2.0);
}

void main() {
  InitLog();

  cout << "El logaritmo base 2 de 3 es:" << endl;
  cout << Log2(3) << endl;
  cout << "El logaritmo base 2 de 7 es:" << endl;
  cout << Log2(7) << endl;
  cout << "El logaritmo base 2 de 8 es:" << endl;
  cout << Log2(8) << endl;
}
