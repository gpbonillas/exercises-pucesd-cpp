// EJ10_06.CPP

// Medida de StrCmp() diferentes

#include <time.h>               // clock(), clock_t, CLK_TCK
#include <iostream.h>           // cout
#include <string.h>             // strlen(), strcmp()

typedef	clock_t	*reloj;

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

double Empty_Rep_StrCmp(long n, double Compensate) {
  reloj c= Start_Timer();
  for(long l= 0; l < n; l++)
    ;
  return(Stop_Timer(c) / (double)n - Compensate);
}

double Rep_StrCmp(long n, int (*f)(const char *, const char *, int),
                  const char *d, const char *s, int Len, double Compensate) {
  reloj c= Start_Timer();
  for(long l= 0; l < n; l++) {
    (void)(*f)(d, s, Len);
  }
  return(Stop_Timer(c) / (double)n - Compensate);
}

int StrCmp1(const char *d, const char *s, int Len) {
  int Result;
  asm {
      PUSH      ES
      PUSH	DS
      POP	ES		// ES= DS
      MOV	CX, Len
      MOV	DI, d
      MOV	SI, s
      CLD
      REPE
      CMPSB
      JE	IGUAL
      JB	MAYOR
  }
      MENOR:
  asm {
      MOV	Result, -1
      JMP	FIN
  }
      MAYOR:
  asm {
      MOV	Result, 1
      JMP	FIN
  }
      IGUAL:
  asm {
      MOV	Result, 0
  }
      FIN:
  asm {
      POP	ES
  }
  return Result;
}

int StrCmp2(const char *d, const char *s, int ) {
  return strcmp(d, s);
}

int StrCmp3(const char *d, const char *s, int ) {
  char c;
  while ((*d++ == (c= *s++)) && (c))
    ;
  if (*--d || *--s) {
    if (*d < *s)
      return -1;
    else
      return 1;
  }
  else
    return 0;
}

int StrCmp4(const char *d, const char *s, int ) {
  int i= 0;
  char c;
  while ((d[i] == (c= s[i])) && c) i++;
  if (d[i] || s[i]) {
    if (d[i] < s[i])
      return -1;
    else
      return 1;
  }
  else
    return 0;
}

int StrCmp5(const char *d, const char *s, int ) {
  int i= 0;
  while (d[i] && s[i]) {
    if (d[i] < s[i])
      return -1;
    else if (d[i] > s[i])
      return 1;
    i++;
  }
  return 0;
}

void main() {
  double Comp;
  long Rep= 100000;	// 100.000 veces
  const char *s, *d;
  s= "Una cadena muy larga para que el chequeo sea más aproximado corriente ";
  d= "Una cadena muy larga para que el chequeo sea más aproximado diferente";
  int Len= strlen(s) + 1;

  cout << StrCmp1(s, d, Len);
  cout << StrCmp2(s, d, Len);
  cout << StrCmp3(s, d, Len);
  cout << StrCmp4(s, d, Len);
  cout << StrCmp5(s, d, Len);

  cout << "Este programa tarda unos segundos, perdone las molestias..." << endl;
  Comp= Empty_Rep_StrCmp(Rep, 0.0);

  cout << "Tiempo StrCmp1 (ensamblador) con " << Rep << " repeticiones: ";
  cout << Rep_StrCmp(Rep, StrCmp1, d, s, Len, Comp) << endl;

  cout << "Tiempo StrCmp2 (librer¡a) " << Rep << " repeticiones: ";
  cout << Rep_StrCmp(Rep, StrCmp2, d, s, Len, Comp) << endl;

  cout << "Tiempo StrCmp3 (con punteros) " << Rep << " repeticiones: ";
  cout << Rep_StrCmp(Rep, StrCmp3, d, s, Len, Comp) << endl;

  cout << "Tiempo StrCmp4 (con vectores) " << Rep << " repeticiones: ";
  cout << Rep_StrCmp(Rep, StrCmp4, d, s, Len, Comp) << endl;

  cout << "Tiempo StrCmp5 (clara pero ineficiente) " << Rep << " repeticiones: ";
  cout << Rep_StrCmp(Rep, StrCmp5, d, s, Len, Comp) << endl;

  cout << "Gracias por su estoica espera" << endl;
}