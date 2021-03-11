//EJ02_03.CPP
#include <iostream.h>				// Usamos: ios, cin, cout
#include <iomanip.h>				// Usamos: resetiosflags

void Leer_Cadena(char * s) {
  cin >> resetiosflags(ios::skipws);			// Para que no pase los caracteres blancos.
  for (int i= 0; cin >> s[i]; i++)			// Leer caracteres hasta el caracter nulo.
    if (s[i] == '\n') break;
  s[i]= '\0';						// Pone el caracter de fin de cadena.
}

void main() {
  char	s[100];					// Buffer de capacidad de hasta 99 caracteres y '\0'. Si metemos m s caracteres hay posibilidad de 'cuelgue'

  cout << endl << "Introduce una cadena (termina con CTRL-Z o INTRO)" << endl;
  Leer_Cadena(s);
  cout << endl << "La cadena es: " << s << endl;
}