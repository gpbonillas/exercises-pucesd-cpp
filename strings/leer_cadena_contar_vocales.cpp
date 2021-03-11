// EJ04_02.CPP

#include <iostream.h>                   // cin, cout, ios
#include <iomanip.h>                   // resetiosflags

void Leer_Cadena(char * s) {
  cin >> resetiosflags(ios::skipws);
					// No pasar los caracteres blancos
  for(int i= 0; cin >> s[i]; i++)       // Leer hasta '\0'
    if  (s[i] == '\n')                  // Se ha pulsado INTRO
      break;

  s[i]= '\0';                           // Poner caracter nulo de terminaci¢n de cadena
}

void main() {
  int  a= 0, e= 0, i= 0, o= 0, u= 0;
  char s[100];    		// Capacidad de hasta 99 caracteres y '\0'

  Leer_Cadena(s);               // Leer una cadena del teclado
  for (int c= 0; s[c]; c++)     // Si s[i] es distinto de '\0'
    switch(s[c]) {
      case 'a':
      case 'A': a++;
		break;
      case 'e':
      case 'E': e++;
		break;
      case 'i':
      case 'I': i++;
		break;
      case 'o':
      case 'O': o++;
		break;
      case 'u':
      case 'U': u++;
		break;
      default  : ;
    }
  cout << endl << "La cadena introducida tiene: "
       << c << " caracteres, de los cuales hay: "
       << a << " as, "
       << e << " es, "
       << i << " ¡es, "
       << o << " os y "
       << u << " £es. "
       << endl;
}
