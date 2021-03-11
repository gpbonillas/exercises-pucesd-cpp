//EJ05_05.CPP

#include  <iostream.h>

static long Rando= 0;

void Random(long l) {
  Rando= l;
}

double Rnd() {
  Rando= (25173L * Rando + 12849L) % 65536L;
  return double(Rando) / double(65536);
}

void main() {
  Random(100);                            // Por poner un ejemplo

  for (int i= 0; i < 100; i++) {
    cout << Rnd() << "  ";
  }
}