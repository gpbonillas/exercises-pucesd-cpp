//Ej14_03.cpp

// Programa que realiza un vector seguro de cualquier tipo

#include <iostream.h>

template <class tipo>
class vector {
private:
  static tipo ERROR;
  static tipo Seguro;	// Reservamos esta posici¢n por seguridad
                        // para el método []

  tipo * v;
  int Tam;

  void Construir(int  t) {
    Tam= t;
    if (Tam)
      v= new tipo[Tam];
    else
      v= NULL;
  }

  void Construir_Copia(const vector & Origen) {
    Construir(Origen.Tam);
    for(int i= 0; i < Tam; i++)
      v[i]= Origen.v[i];
  }

  void Destruir() {
    if (v != NULL) delete []v;
  }

public:
  static void Poner_Error(tipo i) {
    ERROR= i;
  }

  vector(int t= 0) {
    Construir(t);
  }

  vector(const tipo * p, int t) {
    Construir(t);
    for(int i= 0; i < Tam; i++)
      v[i]= p[i];
  }

  vector(const vector & s) {
    Construir_Copia(s);
  }

  ~vector() {
    Destruir();
  }

  tipo & operator [] (int );

  const vector & operator = (const vector & Origen) {
    Destruir();
    Construir_Copia(Origen);
    return *this;
  }

  operator const tipo * () const {	// Convierte a puntero
    return v;
  }
};

template <class tipo>
tipo vector<tipo>::ERROR;
template <class tipo>
tipo vector<tipo>::Seguro;

template <class tipo>
inline tipo &  vector<tipo>::operator [] (int  i) {
  if ((i < Tam) && (i >= 0))
    return v[i];
  else {
    cout << endl << "Exceso de los límites del vector al "
         "acceder al elemento " << i
	 << " de un vector de longitud " << Tam << endl;
    return Seguro= ERROR;
  }
}

void main() {
  vector<int>::Poner_Error(-1);
  vector<int> v(10);
  int i, Elem;

  i= 1;
  v[i]= 2;
  Elem= v[i];
  cout << Elem;			// 2, lógicamente
  v[1000]= 3;
}