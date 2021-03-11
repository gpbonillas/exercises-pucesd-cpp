// EJ11_10.CPP

// Todas las operaciones fundamentales sobre complejos

#include		<iostream.h>
#include		<math.h>

double Sqr(double d) {
  return d * d;
}

class complejo {
private:
  double re, im;
  static void Div_Cero();
public:
  const complejo & Poner(double re, double im);
  void Print();

  complejo operator + (const complejo & );
  complejo operator - (const complejo & );
  complejo operator * (const complejo & );
  complejo operator ~ ();
  complejo operator - ();
  complejo & operator + ();
  complejo operator ! ();
  complejo operator / (const complejo & );
  double Mod();
  const complejo & operator += (const complejo & );
  const complejo & operator -= (const complejo & );
  const complejo & operator *= (const complejo & );
  const complejo & operator /= (const complejo & );
};


// Implementaciones

const complejo & complejo::Poner(double r, double i) {
  re= r;
  im= i;
  return *this;
}

void complejo::Print() {
  cout << re << " + " << im << "i";
}

complejo complejo::operator + (const complejo & b) {
// Suma
  complejo Temp;

  Temp.re= re + b.re;
  Temp.im= im + b.im;

  return Temp;
}

complejo complejo::operator - (const complejo & b) {
// resta
  complejo Temp;

  Temp.re= re - b.re;
  Temp.im= im - b.im;

  return Temp;
}

complejo complejo::operator * (const complejo & b) {
// multiplicaci¢n
  complejo Temp;

  // (a + Ai) * (b + Bi) = (ab - AB) + (aB + Ab)i
  Temp.re= (re * b.re) - (im * b.im);
  Temp.im= (re * b.im) + (im * b.re);

  return Temp;
}

complejo complejo::operator ~ () {
// conjugado
  complejo Temp;
  Temp.re = re;
  Temp.im = -im;
  return Temp;
}

complejo complejo::operator - () {
// cambio de signo
  complejo	Temp;
  Temp.im = -im;
  Temp.re = -re;
  return Temp;
}

complejo & complejo::operator + () {
// operador unario de conservaci¢n de signo. O sea, nada.
  return *this;
}

void complejo::Div_Cero() {
  cout << "Divisi¢n por cero!! ";
}

complejo complejo::operator ! () {
// Inverso
  complejo Temp;
  double Den= Sqr(re) + Sqr(im);
  if (!Den) {
    Div_Cero();
    Temp.Poner(0., 0.);
  }
  else {
    Temp.re= re / Den;
    Temp.im= -im / Den;
  }
  return Temp;
}

complejo complejo::operator / (const complejo &b) {
// Divisi¢n
  return *this * !b;
}

double complejo::Mod() {
// m¢dulo
  return sqrt(Sqr(re) + Sqr(im));
}

const complejo & complejo::operator += (const complejo & b) {
  return *this= *this + b;
// Usando la operaci¢n suma anterior es m s lento que hacerlo directamente pero ahorramos c¢digo.
}

const complejo & complejo::operator -= (const complejo & b) {
  return *this= *this - b;
}

const complejo & complejo::operator *= (const complejo & b) {
  return *this= *this * b;
}

const complejo & complejo::operator /= (const complejo & b) {
  return *this= *this / b;
}

void main() {
  complejo a, b, c, d;

  (void)a.Poner(1.0, 1.0);
  (void)b.Poner(2.0, 2.0);
  (void)c.Poner(1.0, 0);
  b+= a;
  c= a / c;
  d*= b + c - a;				// Qu‚ lindo
  c+= -b * d + c / d - ~a;			// Lind¡simo
  complejo Temp;
  (void)Temp.Poner(2.0, 0.0);
  c*= Temp;           			        // Multiplicar por 2
  d= ~c;					// El conjugado
  d= -c;					// Negado
  d= +d;					// Nada;
  d= !a;					// El inverso

  cout << d.Mod();
  a.Poner(1.0, 0.0);    			// 1
  a= !a;					// El inverso de 1 es 1

  cout << "\n\n";
  cout << "a = ";
  a.Print();
  cout << endl;
  cout << "c = ";
  c.Print();
  cout << endl;
  cout << "d = ";
  d.Print();
  cout << endl;
}