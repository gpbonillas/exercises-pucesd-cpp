// EJ10_09.CPP

// Implementa un QuickSort()

#include <string.h>
#include <iostream.h>

inline
void Swap(char *Vector, int i, int j) {
  char Temp;
  Temp= Vector[i];
  Vector[i]= Vector[j];
  Vector[j]= Temp;
}

void QSort(char *Vector, int Low, int High) {
  if (Low < High) {
    char m= Vector[Low];
    int lo= Low;
    int	hi= High + 1;
    while (1) {
      while (Vector[++lo] < m);
      while (Vector[--hi] > m);
      if (lo >= hi)
        break;
      Swap(Vector, lo, hi);
    }
    Swap(Vector, Low, hi);
    QSort(Vector, Low, hi - 1);
    QSort(Vector, hi + 1, High);
  }
}

void main() {
  char *s= "Esto es una cadena desordenada";
  QSort(s, 0, (int)strlen(s) - 1);
  cout << s;
}