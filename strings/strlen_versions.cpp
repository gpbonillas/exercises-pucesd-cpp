// EJ10_08.CPP

// Medida de StrLen() diferentes

#include <time.h>               // clock(), clock_t, CLK_TCK
#include <iostream.h>           // cout
#include <string.h>             // strlen(), strcmp()

typedef clock_t	*reloj;

reloj Start_Timer() {
  reloj	c;

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
  return Dif / CLK_TCK;	        // Pasar a segundos
}

double Empty_Rep_StrLen(long n, double Compensate) {
  reloj c= Start_Timer();
  for(long l= 0; l < n; l++)
    ;
  return(Stop_Timer(c) / (double)n - Compensate);
}

double	Rep_StrLen(long n, int (*f)(const char *), const char *s, double Compensate) {
  reloj c= Start_Timer();
  for(long l= 0; l < n; l++) {
    (void)(*f)(s);
  }
  return(Stop_Timer(c) / (double)n - Compensate);
}

int StrLen1(const char *s) {
  const char *s0= s;
  s0--;
  while (*s++);
  return s - s0;
}

int StrLen2(const char *s) {
  return strlen(s);
}

int StrLen3(const char *s) {
  int i;
  while (*s++)
    i++;
  return i;
}

int StrLen4(const char *s) {
  int i;
  while (s[i++])
    ;
  return i;
}

void main() {
  double Comp;
  long Rep= 100000;
  const char *s;
  s= "Una cadena muy larga para que el chequeo sea m s aproximado corriente ";

  cout << StrLen1(s);
  cout << StrLen2(s);
  cout << StrLen3(s);
  cout << StrLen4(s);

  cout << "Este programa tarda unos segundos, perdone las molestias..." << endl;
  Comp= Empty_Rep_StrLen(Rep, 0.0);

  cout << "Tiempo StrLen1 (resta) con " << Rep << " repeticiones: ";
  cout << Rep_StrLen(Rep, StrLen1, s, Comp) << endl;

  cout << "Tiempo StrLen2 (librer¡a) con " << Rep << " repeticiones: ";
  cout << Rep_StrLen(Rep, StrLen2, s, Comp) << endl;

  cout << "Tiempo StrLen3 (punteros) con " << Rep << " repeticiones: ";
  cout << Rep_StrLen(Rep, StrLen3, s, Comp) << endl;

  cout << "Tiempo StrLen4 (vectores) con " << Rep << " repeticiones: ";
  cout << Rep_StrLen(Rep, StrLen4, s, Comp) << endl;

  cout << "Gracias por su estoica espera" << endl;
}
