// EJ04_04.CPP
#include	<iostream.h>		// cin, cout

int StrCmp(char *s1, char *s2) {
  int  i= 0;
  while (s1[i] || s2[i]) {	  	// Hasta terminar las dos
    if (s1[i] < s2[i])
      return -1;           		// La cadena 1 es menor que la 2
    else if (s1[i] > s2[i])
      return 1;            		// La cadena 1 es mayor que la 2
    i++;
  }
  return 0;                        	// Las cadenas son iguales
}

void main() {
  char s1[100], s2[100];

  cin >> s1 >> s2;			// Lee las dos primeras PALABRAS
  int r= StrCmp(s1, s2);
  if (r == 0)
    cout << "Las dos primeras palabras son iguales";
  else if (r == 1)
    cout << "La primera palabra es mayor alfab‚ticamente";
  else
    cout << "La segunda palabra es mayor alfab‚ticamente";
}