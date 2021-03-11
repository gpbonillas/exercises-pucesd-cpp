// EJ11_05.CPP

// Implementa números circulares usando clases

#include <iostream.h>

typedef int num;		// Trabajemos con enteros

class circ_num {
private:
  static num LIM;
  num v;

public:
  static void Poner_LIM(num i) {
    LIM= i;
  }

  circ_num Crear(num i) {
    if (i < 0) {
      v= i % LIM;
      if (v > 0)          // NO DEBE SER POSITIVO
        v= -v;
      if (v != 0)
        v+= LIM;
    }
    else {
      v= i % LIM;
    }
    return *this;
  }

  num Valor() {
    return v;
  }

  circ_num operator + (circ_num b) {
    return Crear(v + b.v);
  }

  circ_num operator - (circ_num b) {
    return Crear(v - b.v);
  }

  circ_num operator / (circ_num b) {
    return Crear(v / b.v);
  }

  circ_num operator * (circ_num b) {
    return Crear(v * b.v);
  }

  circ_num operator % (circ_num b) {
    return Crear(v % b.v);
  }

  circ_num operator += (circ_num b) {
    *this= *this + b;
    return *this;
  }

  circ_num operator -= (circ_num b) {
    *this= *this - b;
    return *this;
  }

  circ_num operator *= (circ_num b) {
    *this= *this * b;
    return *this;
  }

  circ_num operator /= (circ_num b) {
    *this= *this / b;
    return *this;
  }

  circ_num operator %= (circ_num b) {
    *this= *this % b;
    return *this;
  }
};

num circ_num::LIM;		// De l¡mites 0..360

void main() {
  circ_num::Poner_LIM(360);

  circ_num a, b, c, d;

  (void)a.Crear(180);
  (void)b.Crear(400);		        // b= 40;
  (void)c.Crear(-10);           	// c= 350;
  (void)d.Crear(2);

  a+= c;                		// a= 170
  a-= c;		                // a= 180
  c*= b;			        // (40 * 350) = 14000 % 360 = 320
  d*= a;	                        // d= 0;

  cout << a.Valor() << endl;
  cout << b.Valor() << endl;
  cout << c.Valor() << endl;
  cout << d.Valor() << endl;
}