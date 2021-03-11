//Ej10_04.cpp
#include <time.h>       // clock(), clock_t, CLK_TCK
#include <iostream.h>   // cout

typedef clock_t	*reloj;

reloj Start_Timer() {
  reloj c;

  c= new clock_t;               // Reservar memoria
  *c= clock();                  // Guardar n£mero de ticks
  return c;
}

double Get_Timer(reloj c) {
  clock_t Dif;
  Dif= clock() - *c;            // Diferencia entre Start y Stop
  return Dif / CLK_TCK;	        // Pasar a segundos
}

double Stop_Timer(reloj c) {
  clock_t Dif;
  Dif= clock() - *c;            // Diferencia entre Start y Stop
  delete c;                     // Liberar memoria;
  return Dif / CLK_TCK;	        // Pasar a segundos
}

long double Fact1(long double n) {
  return n ? (Fact1(n - 1) * n) : 1;
}

long double Fact2(long double n) {
  long double m= 1;
  while (n) {
    m*= n--;
  }
  return m;
}

long double Fact3(long double n) {
  if (n == 0)
    return 1;
  else
    return Fact3(n - 1) * n;
}

double Empty_Rep_Fact(long n, double Compensate) {
  reloj c= Start_Timer();
  for(long l= 0; l < n; l++)
		;
  return(Stop_Timer(c) / (double)n - Compensate);
}

double Rep_Fact(long n, long double (*f)(long double), 
                long double Val, double Compensate) {
  reloj c= Start_Timer();
  for(long l= 0; l < n; l++) {
    (void)(*f)(Val);
  }
  return(Stop_Timer(c) / (double)n - Compensate);
}

void main() {
  double Comp;
  long Rep= 100;
  long double v= 400.0;

  cout << "Este programa tarda unos segundos, perdone las molestias..." << endl;
  Comp= Empty_Rep_Fact(Rep, 0.0);
  cout << "Tiempo factorial recursiva para n= "
       << v << " con " << Rep << " repeticiones: ";
  cout << Rep_Fact(Rep, Fact1, v, Comp) << endl;
  cout << "Ya queda menos,  nimo!" << endl;
  cout << "Tiempo factorial iterativa para n= "
       << v << " con " << Rep << " repeticiones: ";
  cout << Rep_Fact(Rep, Fact2, v, Comp) << endl;
  cout << "Ya queda poco,  nimo!" << endl;
  cout << "Tiempo factorial recursiva larga para n= "
       << v << " con " << Rep << " repeticiones: ";
  cout << Rep_Fact(Rep, Fact3, v, Comp) << endl;
  cout << "Gracias por su estoica espera" << endl;
}

// En muchas m quinas saldr  Fact3() la m s r pida y Fact2() la m s lenta, completamente inverso a nuestras previsiones.

