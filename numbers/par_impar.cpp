// EJ06_02.CPP

#include <iostream.h>

enum bool { FALSE, TRUE };

bool Impar(int);				// Prototipo para que desde Par se pueda llamar a Impar;

bool Par(int n) {
  return n ? Impar(n - 1) : TRUE;		// Si n = 0 es Par, sino ser  si n-1 es Impar
}

bool Impar(int n) {
  return n ? Par(n - 1) : FALSE;		// Si n= 0 no es impar, sino ser  si n-1 es Par
}

void main() {
  cout << endl << "Introduce un n£mero positivo no muy alto" << endl;
  // Si metemos un n£mero muy alto podemos desbordar la pila!!
  int n;
  cin >> n;
  if (Par(n))
    cout << n << " es un n£mero par" << endl;
  else
    cout << n << " es un n£mero impar" << endl;
}

// Nota: evidentemente: !(n & 1) nos chequear¡a si n es par mucho m s eficientemente