// EJ09_02.CPP

// Invierte una cadena

#include <iostream.h>

void Invertir(char *s) {
  char *t= s;

  while (*t)
    t++;
                                // Pongo t al final de la cadena. En el caracter '\0'
  t--;	                        // Me pongo en el anterior

  while(s < t) {                // Hasta que lleguemos al medio
    char Temp= *s;
    *s++= *t;
    *t--= Temp;	                // Intercambiar
  }
}

void main() {
  char *s= "SOLOS NABOS ES AVE Y NADA";

  Invertir(s);
  cout << s;
}