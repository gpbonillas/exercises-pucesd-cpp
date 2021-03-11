// EJ10_13.CPP

// Criba de Eratóstenes

#include <iostream.h>

enum bool { FALSE, TRUE };

void Eratos(int n) {
  if (n >= 0) {
    bool *a= new bool[n + 1];
    a[0]= FALSE;
    int i, j;
    if (n >= 1) {
      a[1]= FALSE;
      if (n >= 2) {
        for (i= 2; i <= n; i++)
          a[i]= TRUE;
        int n2= n >> 1;       // Dividir por 2
        for (i= 2; i <= n2; i++) {
          if (a[i]) {
            int ni= n / i;
            for (j= 2; j <= ni; j++)
              a[i * j]= FALSE;
          }
        }
      }
    }
    int Cont= 0;
    for (i= 0; i < n; i++)
      if (a[i]) {
        cout << i << ' ';
        Cont++;
      }
    delete [] a;
    cout << "\nTotal primos: " << Cont;
  }
}

void main() {
  int n;

  cout << "¨Hasta que primo quieres? ";
  cin >> n;
  cout << "\n\n";
  Eratos(n);
  cout << endl;
}
