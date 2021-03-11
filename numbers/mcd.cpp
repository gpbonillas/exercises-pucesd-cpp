// EJ04_03.CPP
#include <iostream.h>		// cout, cin

int Mcd(int a, int b) {
  if (a <= 0 || b <= 0)
    return -1;                  // C¢digo de error
  while (a != b)
    if (a < b)
      b= b - a;
      //    b-= a;     		// Igual que la anterior. Ya se ver 
    else
      a= a - b;
      //    a-= b;              // Igual que la anterior
  return a;          		// Al final el mcd est  en a y en b (a == b)
}

void main() {
  int a, b;
  cin >> a >> b;
  cout << "MCD. = " << Mcd(a, b);
}