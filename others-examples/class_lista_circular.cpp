#include <iostream.h>
#include "EJ16_03.H"

void main() {
  clista<int> l1, l2;

  int i;

  for(i= 1; i <= 10; i++) {
    l1.Insertar(i);
    l2.Insertar(i * i);         // Cuadrado de i
                                // Se crea un objeto temporal ya que se pasa por referencia
  }

  cout << "Num\tCuadrado" << endl;
  for(i= 1; i <= 10; i++) {		// Salen en orden inverso
    cout << (l1++).Info() << '\t'
         << (l2++).Info() << endl;
  }
  for(i= 1; i <= 10; i++) {		// Salen en orden correcto
    cout << (--l1).Info() << '\t'
         << (--l2).Info() << endl;
  }
}