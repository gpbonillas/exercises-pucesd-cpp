// EJ08_09.CPP

// Todas las operaciones fundamentales sobre complejos

#include		<iostream.h>
#include		<math.h>

double Sqr(double d) {
  return d * d;
}

struct complejo {
  double re, im;
};

complejo Cplx_Crear(double re, double im) {
  complejo	Temp;

  Temp.re= re;
  Temp.im= im;

  return Temp;
}

void Cplx_Print(const complejo c) {
  cout << c.re << " + " << c.im << "i";
}

complejo operator + (const complejo & a, const complejo & b) {
// Suma
  complejo Temp;

  Temp.re= a.re + b.re;
  Temp.im= a.im + b.im;

  return Temp;
}

complejo operator - (const complejo & a, const complejo & b) {
// resta
  complejo Temp;

  Temp.re= a.re - b.re;
  Temp.im= a.im - b.im;

  return Temp;
}

complejo operator * (const complejo & a, const complejo & b) {
// multiplicaci¢n
  complejo Temp;

  // (a + Ai) * (b + Bi) = (ab - AB) + (aB + Ab)i
  Temp.re= (a.re * b.re) - (a.im * b.im);
  Temp.im= (a.re * b.im) + (a.im * b.re);

  return Temp;
}

complejo operator ~ (const complejo & c) {
// conjugado
  complejo Temp;
  Temp.re = c.re;
  Temp.im = -c.im;
  return Temp;
}

complejo operator - (const complejo & c) {
// cambio de signo
  complejo	Temp;
  Temp.im = -c.im;
  Temp.re = -c.re;
  return Temp;
}

complejo operator + (const complejo & c) {
// operador unario de conservaci¢n de signo. O sea, nada.
  return c;
}

void Div_Cero() {
  cout << "Divisi¢n por cero!! ";
}

complejo operator ! (const complejo & c) {
// Inverso
  double Den= Sqr(c.re) + Sqr(c.im);
  if (!Den) {
    Div_Cero();
    return Cplx_Crear(0, 0);
  }
  complejo Temp;
  Temp.re= c.re / Den;
  Temp.im= -c.im / Den;
  return Temp;
}

complejo operator / (const complejo & a, const complejo &b) {
// Divisi¢n
  return a * !b;
}

double Cplx_Mod(const complejo & c) {
// m¢dulo
  return sqrt(Sqr(c.re) + Sqr(c.im));
}

void operator += (complejo & a, const complejo & b) {
// El par metro a es fuente y destino, por eso no puede ser constante
  a= a + b;
// Usando la operaci¢n suma anterior es m s lento que hacerlo directamente pero ahorramos c¢digo.
}

void operator -= (complejo & a, const complejo & b) {
  a= a - b;
}

void operator *= (complejo & a, const complejo & b) {
  a= a * b;
}

void operator /= (complejo & a, const complejo & b) {
  a= a / b;
}

void main() {
  complejo a, b, c, d;

  a= Cplx_Crear(1.0, 1.0);
  b= Cplx_Crear(2.0, 2.0);
  c= Cplx_Crear(1.0, 0);
  b+= a;
  c= a / c;
  d*= b + c - a;				// Qu‚ lindo
  c+= -b * d + c / d - ~a;			// Lind¡simo
  c*= Cplx_Crear(2.0, 0.0);			// Multiplicar por 2
  d= ~c;					// El conjugado
  d= -c;					// Negado
  d= +d;					// Nada;
  d= !a;					// El inverso

  cout << Cplx_Mod(d);
  a= Cplx_Crear(1.0, 0.0);			// 1
  a= !a;					// El inverso de 1 es 1

  cout << "\n\n";
  cout << "a = ";
  Cplx_Print(a);
  cout << endl;
  cout << "c = ";
  Cplx_Print(c);
  cout << endl;
  cout << "d = ";
  Cplx_Print(d);
  cout << endl;
}