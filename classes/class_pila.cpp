//Ej12_08.cpp

#include <iostream.h>

enum bool { FALSE, TRUE };

typedef char elem_t;		// Vamos a usar caracteres

class pila {
private:
  static elem_t	Error;

  class nodo {
  public:
    elem_t Dato;
    nodo *Ant;
    nodo(elem_t i, nodo *p) {
      Dato= i, Ant= p;
    }
    ~nodo() {
    }
  };

  nodo *Tope;

  // Métodos privados para uso propio
  void Copiar(pila & p);
  void Construir();
  void Destruir();
public:
  static void Pon_Error(elem_t i) { Error= i; }

  pila();                                       // Constructor
  ~pila();	                                	// Destructor
  pila(const pila & );                          // Constructor copia
  const pila & operator = (const pila & );	// Operador de asignaci¢n
  bool Vacia() const;                           // ¿Está vacía?
  bool Llena() const;                           // ¿Está llena?
  void Pop();                                   // Desapilar
  void Push(elem_t );                           // Apilar
  elem_t Top() const;                          	// Consultar la cima
};

elem_t		pila::Error;


// Implementaci¢n

#include <stddef.h>	// NULL

inline
void pila::Construir() {
  Tope= NULL;
}

inline
void pila::pila() {
  Construir();
}

inline
void pila::~pila() {
  Destruir();
}

inline
bool pila::Vacia() const {
  return bool(Tope == NULL);
}

inline
bool pila::Llena() const {
  return FALSE;	                // Suponemos que siempre hay memoria
}

inline
void pila::Pop() {
  if (!Vacia()) {
    nodo *Temp;
    Temp= Tope->Ant;
    delete Tope;
    Tope= Temp;
  }
  else
    cout << "No puedo hacer un Pop() sobre una pila vacía";
}

inline
void pila::Push(elem_t v) {
  if (!Llena()) {
    nodo *Temp;
    Temp= new nodo(v, Tope);              // Llamamos al constructor de nodo
    Tope= Temp;
  }
  else
    cout << "No puedo hacer un Push() sobre una pila llena";
}

inline
elem_t pila::Top() const {
  if (!Vacia())
    return Tope->Dato;
  else
    return Error;
}

void pila::Copiar(pila & p) {
// Muy ineficiente pero es simple
// Una implementaci¢n mejor sería tener un puntero a la cabeza adem s de a la cola
  pila Temp;
  elem_t i;
  while (!p.Vacia()) {
    i= p.Top();
    p.Pop();
    Temp.Push(i);
  }              // Tenemos una copia inversa de p en Temp y hemos borrado p

  while (!Temp.Vacia()) {
    i= Temp.Top();
    Temp.Pop();
    Push(i);
    p.Push(i);
  }             // Hemos copiado la pila y hemos reconstruido p
}

void pila::Destruir() {
  while (!Vacia())
    Pop();
}

inline
pila::pila(const pila & p) {
  Construir();
  Copiar((pila &)p);		// Conversi¢n de const a no const
}

inline
const pila & pila::operator = (const pila & p) {
  if (&p != this) {             // si no es autoasignaci¢n
    Destruir();
    Construir();
    Copiar((pila &)p);          // Conversi¢n de const a no const
  }
  return *this;
}

void main() {
  pila::Pon_Error(char(-1));

  pila p1;
  char *s= "seroloc ed odnum ocigam lE";

  cout << "\n¨Qu‚ puede salir de esto?\n";
  cout << s << endl;

  int i= 0;
  char c;
  while(c= s[i++])
    p1.Push(c);

  i= 0;
  pila p2= p1;		// Constructor copia
  pila p3, p4;
  p4= p3= p2;			// Operador de asignación

  while(!p4.Vacia()) {
    s[i++]= p4.Top();
    p4.Pop();
  }

  cout << "Esto: \n" << s << endl;
}


