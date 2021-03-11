// EJ18_06.CPP

// Este programa produce un volcado hexadecimal de un fichero de entrada

#include <fstream.h>
#include <iomanip.h>
#include <ctype.h>

void main (int argc, char *argv[]) {
  istream *fin = &cin;            // La entrada por defecto es cin
  ostream *fout = &cout;          // La salida por defecto es cout
  fstream fent, fsal;

  if (argc > 1) {
    // Fichero de entrada especificado
    fent.open (argv[1], ios::in | ios::binary);
    if (!fent) {
       cerr << "Error abriendo fichero de entrada" << argv[1] << '\n';
       return;
    }
    fin = &fent;
  }

   if (argc > 2) {
     // Fichero de salida especificado
     fsal.open (argv[2], ios::out);
     if (!fsal) {
       cerr << "Error abriendo fichero de salida" << argv[2] << '\n';
       return;
     }
     fout = &fsal;
   }

   const int TAM= 16;
   char Volcado_ASCII[TAM+1];   // Porci¢n ASCII del volcado
   Volcado_ASCII[TAM] = '\0';   // Termina con el car cter nulo \0
   int ProxCar = 0;
   int c;

   *fout << endl;                // l¡nea de separaci¢n
   // Prepara para salida hexadecimal may£scula (uppercase) llenando con '0'
   *fout << setiosflags(ios::uppercase) << hex << setfill(0);

   // Bucle hasta el fin de fichero
   while ((c= fin->get()) != EOF) {
     *fout << setw(2) << c << ' ';
     if (c < char(32))
       c = '.';         // Convierte los caracteres no imprimibles en '.'
     Volcado_ASCII[ProxCar++] = c;
     if (ProxCar == TAM) {
       *fout << Volcado_ASCII << '\n';
       ProxCar = 0;
     }
   }

   // Vuelca los restos
   if (ProxCar) {
     for (; ProxCar < TAM; ProxCar++) {
       *fout << "00 ";
       Volcado_ASCII[ProxCar]= '.';
     }
     *fout << Volcado_ASCII << '\n';
   }
}