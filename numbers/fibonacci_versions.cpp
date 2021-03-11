// EJ10_02.CPP

// Define funciones para el cálculo de los números de Fibonacci

#include <iostream.h>
#include <math.h>               // pow(), sqrt()

static long cont= 0L;
long Fibonacci1(long n) {
  cont++;
// se podr¡a haber hecho con un switch, pero se hace as¡ por eficiencia
  if (n > 1)
    return Fibonacci1(n-1) + Fibonacci1(n-2);
  else if (n)			// n= 1
    return 1;
  else
    return 0;
}

long Fibonacci2(long n) {
// M‚todo de programaci¢n din mica. No repetir llamadas
  long *Vector= new long[n];
  long Ret;
  Vector[0]= 0L;
  Vector[1]= 1L;
  for(long l= 2L; l <= n; l++)
    Vector[l]= Vector[l-1] + Vector[l-2];
  Ret= Vector[n];
  delete Vector;
  return Ret;
}

double Fibonacci3(double n) {
  static const double R5= sqrt(5.0);

  return (1/R5) * ( pow((1.0 + R5)/ 2.0, n) - pow((1.0 - R5) / 2.0, n));
}

void main() {
  cout << Fibonacci1(25L) << endl;      // O(2^n)
  cout << Fibonacci2(25L) << endl;      // O(n)
  cout << Fibonacci3(25.0) << endl;     // O(1)
}