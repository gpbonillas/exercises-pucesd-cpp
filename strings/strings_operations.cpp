// EJ09_05.CPP

// Define operaciones básicas sobre cadenas

// Si la versión es >= C++ 2.1 dejar, si no borrar.
// En Borland TC v. 1.0 hay que borrar la siguiente línea
#define	_cplusplus2_1

#include <string.h>
#include <iostream.h>

// Prototipos
struct cadena;

cadena Construir(const char * );
cadena Construir(int );
void Destruir(cadena & );
void Vaciar(cadena & );	                // Vacía la cadena
char * Str(cadena & );	                // Retorna una cadena normal
// Operaciones de concatenaci¢n
cadena operator += (cadena & , const cadena & );
cadena operator += (cadena & , const char * );
cadena operator + (const cadena & , const cadena & );

// Definiciones

struct cadena {
  char *s;
  int Len;
};

void Vaciar(cadena & c) {
// Vac¡a la cadena
  *(c.s)= '\0';
}

cadena Construir(const char *s) {
// Construye una cadena copiando una cadena normal
  cadena c;
  int Len= 1;
  const char *t= s;			// Puntero auxiliar

  while(*t++)
    Len++;
  c.s= new char[Len];
  c.Len= Len;
  (void)strcpy(c.s, s);
  return c;
}

cadena Construir(int n) {
// Construye una cadena vac¡a de capacidad n
  cadena c;
  c.Len= n;
  c.s= new char[c.Len];
  Vaciar(c);
  return c;
}

void Destruir(cadena & c) {
// Destruye una cadena
#ifdef _cplusplus2_1		// Versi¢n 2.1 y posteriores
  delete [] c.s;
#else				// Versi¢n 2.0 y anteriores
  delete [c.Len] c.s;
#endif
}

char * Str(cadena& c) {
// Nos permite acceder al puntero que apunta a la cadena en s¡
  return c.s;
}

cadena operator += (cadena & c1, const cadena & c2) {
// concatena una cadena s2 al final de s1
  return Construir(strcat(c1.s, c2.s));
}

cadena operator += (cadena & c1, const char *s) {
// concatena una cadena normal (string) al final de s1
  return Construir(strcat(c1.s, s));
}

cadena operator + (const cadena & c1, const cadena & c2) {
// concatena dos cadenas en otra
  cadena c= Construir(c1.Len + c2.Len - 1);
  // -1 porque s¢lo hace falta un '\0'
  c+= c1;
  c+= c2;
  return c;
}

void main() {
  cadena s= Construir(100);		// Construye una cadena con un buffer de 100 caracteres
  cadena c1= Construir("Hola "),
         c2= Construir("a "),
         c3= Construir("todos ");

  s+= c1;
  s+= c2;
  s+= c3;
  s+= "los ";
  s+= "cursillistas";

  cout << endl << endl << endl
       << Str(s) << endl;

  cadena t= Construir(" \"cursis\"\n");
  cadena u= s + t;
  cout << Str(u);

  Vaciar(s);
  cout << Str(s);

  Destruir(s);
  Destruir(t);
  Destruir(u);
  Destruir(c1);
  Destruir(c2);
  Destruir(c3);
}