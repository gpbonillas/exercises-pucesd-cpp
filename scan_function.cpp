// EJ08_05.CPP

#include <stdio.h>

// La funci¢n scanf requiere un puntero, por eso ponemos &

void Scan(char & c) {
  scanf("%c", &c);
}
 
void Scan(int & i) {
  scanf("%i", &i);
}
 
void Scan(long & l) {
  scanf("%li", &l);
}
 
void Scan(float & f) {
  scanf("%f", &f);
}

void Scan(void * & p) {
  scanf("%p", &p);
}
 
void Scan(char *s) {
  scanf("%s", s);
}

void main() {
  int     i;
  char    c;
  long    l;
  float   f;
  void *  p;
  char    s[100];

  printf("Introduce un entero, un caracter, un long,");
  printf(" un real, un puntero y una cadena (separados por INTRO)\n");
  Scan(i);
  Scan(c);
  Scan(c);
  // Se pone dos veces porque el primero lee el '\n' del Scan anterior.
  Scan(l);
  Scan(f);
  Scan(p);
  Scan(s);
}