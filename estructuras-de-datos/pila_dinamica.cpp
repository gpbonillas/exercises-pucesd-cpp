// EJ11_07.CPP

// Implementa una pila dinámica en una clase
// No funciona del todo correctamente. Esto ya se ver  en el cap¡tulo siguiente.

#include <iostream.h>	// cout

enum bool { FALSE, TRUE };

typedef int elem_t;       // Vamos a trabajar con enteros

class pila {
private:
  class nodo {
  public:
    elem_t Info;
    nodo *Ant;
  };
  nodo *p;              // Implementaci¢n con un puntero
public:
  void Construir();
  void Destruir();
  void Push(elem_t );
  void Pop();
  elem_t Top();
  bool Vacia();
  bool Llena();
};


// Implementaci¢n

#include <stddef.h>	// NULL

inline
void pila::Construir() {
  p= NULL;
}

inline
bool pila::Vacia() {
  return bool(!p);		// (p != NULL)
}

inline
bool pila::Llena() {
  return FALSE;                 // Suponemos que siempre tenemos memoria
}

inline
elem_t pila::Top() {
  if (!Vacia())
    return p->Info;
  else {
    return -1;
  }
}

inline
void pila::Push(elem_t Inf) {
  if (!Llena()) {
    nodo *Ret;

    Ret= new nodo;			// Reserva espacio
    Ret->Info= Inf;
    Ret->Ant= p;
    p= Ret;
  }
  else
    cout << "No puedo hacer un Push() sobre una pila llena";
}

inline
void pila::Pop() {
  if (Vacia())
    cout << "No se puede hacer un Pop() sobre una pila vac¡a";
  else {
    nodo *Temp= p;
    p= p->Ant;
    delete Temp;		// Ahora ya podemos destruir
  }
}

void pila::Destruir() {
  while (!Vacia())
    Pop();
}

void main() {
  pila p;
  p.Construir();                // -
  p.Push(1);                    // 1-
  p.Push(2);                    // 2-1-
  p.Push(3);                    // 3-2-1-

  cout << p.Top() << endl;      // 3
  p.Pop();                      // 2-1-
  cout << p.Top() << endl;      // 2
  p.Pop();                      // 1-
  cout << p.Top() << endl;      // 1
  p.Pop();                      // -
  p.Pop();                      // - Dar  error
  cout << p.Vacia() << endl;    // Claro, est  vac¡a
  p.Destruir();	                // Bueno, destruimos de todas formas
  cout << p.Top() << endl;      // Saldr  el -1
}