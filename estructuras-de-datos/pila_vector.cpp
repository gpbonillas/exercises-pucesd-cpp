// EJ11_06.CPP

// Implementaci¢n de una pila por medio de un vector

#include <iostream.h>

enum bool { FALSE, TRUE };

typedef int elem_t;             // Vamos a trabajar con enteros

const elem_t TAM= 1000;

class pila {
private:
  elem_t Datos[TAM];
  elem_t Indice;
public:
  void Construir();
  void Destruir();
  void Push(elem_t );
  void Pop();
  elem_t Top();
  bool Vacia();
  bool Llena();
};


void pila::Construir() {
  Indice= TAM;
}

bool pila::Vacia() {
  return bool(Indice == TAM);
}

bool pila::Llena() {
  return bool(!Indice);
}

void pila::Pop() {
  if (!Vacia())
    Indice++;
  else
    cout << "\nNo se puede hacer un Pop() sobre una pila vac¡a";
}

void pila::Destruir() {
}

void pila::Push(elem_t v) {
  if (!Llena())
    Datos[--Indice]= v;
  else  
    cout << "No puedo hacer un Push sobre una pila llena";
}

elem_t pila::Top() {
  if (!Vacia())
    return Datos[Indice];
  else
    return -1;
}

void main() {
  pila p;
  p.Construir();
  p.Push(1);
  p.Push(2);
  p.Push(3);
  cout << endl;
  cout << p.Top() << endl;
  p.Pop();
  cout << p.Top() << endl;
  p.Pop();
  cout << p.Top() << endl;
  p.Pop();
  p.Pop();                      // Saldr  error
}
