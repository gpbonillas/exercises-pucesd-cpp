// EJ08_10.CPP

// Implementa n£meros circulares

#include <iostream.h>

typedef int num;		// Trabajemos con enteros
const num LIM= 360;		// De l¡mites 0..360

struct circ_num {
  num v;
};

circ_num Circ_Crear(num i) {
  circ_num Temp;
  while (i < 0)
    i+= LIM;			// Ajustar i positivo
  Temp.v= i % LIM;

  return Temp;
}

num Circ_Valor(circ_num c) {
  return c.v;
}

circ_num operator + (circ_num a, circ_num b) {
  return Circ_Crear(a.v + b.v);
}

circ_num operator - (circ_num a, circ_num b) {
  return Circ_Crear(a.v - b.v);
}

circ_num operator / (circ_num a, circ_num b) {
  return Circ_Crear(a.v / b.v);
}

circ_num operator * (circ_num a, circ_num b) {
  return Circ_Crear(a.v * b.v);
}

circ_num operator % (circ_num a, circ_num b) {
  return Circ_Crear(a.v % b.v);
}

void operator += (circ_num & a, circ_num b) {
  a= a + b;
}

void operator -= (circ_num & a, circ_num b) {
  a= a - b;
}

void operator *= (circ_num & a, circ_num b) {
  a= a * b;
}

void operator /= (circ_num & a, circ_num b) {
  a= a / b;
}

void operator %= (circ_num & a, circ_num b) {
  a= a % b;
}

void main() {
  circ_num a, b, c, d;

  a= Circ_Crear(180);
  b= Circ_Crear(400);		// b= 40;
  c= Circ_Crear(-10);		// c= 350;
  d= Circ_Crear(2);

  a+= c;			// a= 170
  a-= c;			// a= 180
  c*= b;			// (40 * 350) = 14000 % 360 = 320
  d*= a;			// d= 0;

  cout << Circ_Valor(a) << endl;
  cout << Circ_Valor(b) << endl;
  cout << Circ_Valor(c) << endl;
  cout << Circ_Valor(d) << endl;
}