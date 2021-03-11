// EJ10_11.CPP

// Multiplicaciones rápidas

#include <time.h>               // clock(), clock_t, CLK_TCK
#include <iostream.h>           // cout

typedef	clock_t *reloj;

reloj Start_Timer() {
  reloj c;

  c= new clock_t;               // Reservar memoria
  *c= clock();                  // Guardar n£mero de ticks
  return c;
}

double Get_Timer(reloj c) {
  clock_t Dif;
  Dif= clock() - *c;            // Diferencia entre Start y Stop
  return Dif / CLK_TCK;         // Pasar a segundos
}

double Stop_Timer(reloj c) {
  clock_t Dif;
  Dif= clock() - *c;            // Diferencia entre Start y Stop
  delete c;                     // Liberar memoria;
  return Dif / CLK_TCK;         // Pasar a segundos
}

double Empty_Rep_Mult(long n, double Compensate) {
  reloj c= Start_Timer();
  for(long l= 0; l < n; l++)
    ;
  return(Stop_Timer(c) / (double)n - Compensate);
}

double Rep_Mult(long n, int (*f)(int, int ), int a, int b, double Compensate) {
  reloj c= Start_Timer();
  for(long l= 0; l < n; l++) {
    (void)(*f)(a, b);
  }
  return(Stop_Timer(c) / (double)n - Compensate);
}

int Mult1(int a, int b) {
  return a * b;
}

int Mult2(int a, int ) {
  return a << 1;
}

int Mult3(int a, int ) {
  return (a << 2) + a;
}

int Mult4(int a, int ) {
  return a << 2;
}

int Mult5(int a, int ) {
  return (a << 2) + a;
}

int Mult6(int a, int ) {
  return (a << 2) + (a << 1);
}

int Mult7(int a, int ) {
  return (a << 2) + (a << 1) + a;
}

int Mult8(int a, int ) {
  return a << 3;
}

int MultN(int a, int b) {
  int r= 0;

  while (b) {
    if ((b | 1) == b)           // bit es 1
      r+= a;
    b >>= 1;
    a <<= 1;
  }
  return r;
}

void main() {
  double Comp;
  long Rep= 2000000;            // 2.000.000 veces
  int a= 10, b= 2;

  cout << Mult1(a, b) << endl;
  cout << Mult2(a, b) << endl;
  cout << Mult3(a, b) << endl;
  cout << Mult4(a, b) << endl;
  cout << Mult5(a, b) << endl;
  cout << Mult6(a, b) << endl;
  cout << Mult7(a, b) << endl;
  cout << Mult8(a, b) << endl;
  cout << MultN(a, b) << endl;

  cout << "Este programa tarda unos segundos, perdone las molestias..." << endl;
  Comp= Empty_Rep_Mult(Rep, 0.0);

  cout << "Tiempo Mult1 (convencional) con " << Rep << " repeticiones: ";
  cout << Rep_Mult(Rep, Mult1, a, b, Comp) << endl;

  cout << "Tiempo Mult2 (truco) con " << Rep << " repeticiones: ";
  cout << Rep_Mult(Rep, Mult2, a, b, Comp) << endl;

  cout << "Tiempo Mult3 (truco) con " << Rep << " repeticiones: ";
  cout << Rep_Mult(Rep, Mult3, a, b, Comp) << endl;

  cout << "Tiempo Mult4 (truco) con " << Rep << " repeticiones: ";
  cout << Rep_Mult(Rep, Mult4, a, b, Comp) << endl;

  cout << "Tiempo Mult5 (truco) con " << Rep << " repeticiones: ";
  cout << Rep_Mult(Rep, Mult5, a, b, Comp) << endl;

  cout << "Tiempo Mult6 (truco) con " << Rep << " repeticiones: ";
  cout << Rep_Mult(Rep, Mult6, a, b, Comp) << endl;

  cout << "Tiempo Mult7 (truco) con " << Rep << " repeticiones: ";
  cout << Rep_Mult(Rep, Mult7, a, b, Comp) << endl;

  cout << "Tiempo Mult8 (truco) " << Rep << " repeticiones: ";
  cout << Rep_Mult(Rep, Mult8, a, b, Comp) << endl;

  cout << "Tiempo MultN (truco) " << Rep << " repeticiones: ";
  cout << Rep_Mult(Rep, MultN, a, b, Comp) << endl;

  cout << "Gracias por su estoica espera" << endl;
}