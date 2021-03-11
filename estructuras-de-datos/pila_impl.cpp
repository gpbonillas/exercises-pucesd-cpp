// EJ09_04.CPP

// Implementa una pila

#include <stddef.h>	// NULL
#include <iostream.h>	// cout

// Variaciones posibles por el usuario

void Aviso(const char *s) {
  cout << "\nSe ha producido un error en la pila. El error es:\n" << s << endl;
}

typedef int info_t;		// Vamos a probarla para enteros
const int ERROR_ELEM= -1;	// Elemento error;
const void (*F_Error)(const char *)= Aviso;

// Definiciones necesarias

enum bool { FALSE, TRUE };

struct nodo {
  info_t Info;
  nodo *Ant;
};

typedef nodo *pila;

// Prototipos

pila Crear();			// Construir
void Destruir(pila &);		// Destruir
bool Es_Vacia(pila &);		// ¿Está vacía?
void Push(pila&, info_t);	// Apilar
void Pop(pila& );			// Desapilar
info_t&	Top(pila& );	// Tope de la pila

// Definiciones dependientes de la implementaci¢n

int ERROR_COP;

pila Crear() {
  return NULL;
}

bool Es_Vacia(pila & p) {
  return bool(!p);		// (p != NULL)
}

info_t & Top(pila & p) {
  if (p)
    return p->Info;
  else {
    (*F_Error)("No se puede acceder a un elemento de una pila vacía");
    return ERROR_COP= ERROR_ELEM;
  }
}

void Push(pila & p, info_t Inf) {
  pila Ret;

  Ret= new nodo;			// Reserva espacio
  Ret->Info= Inf;
  Ret->Ant= p;
  p= Ret;
}

void Pop(pila & p) {
  if (Es_Vacia(p))
    (*F_Error)("No se puede borrar sobre una pila vacía");
  else {
    pila Temp= p;
    p= p->Ant;
    delete Temp;		// Ahora ya podemos destruir
  }
}

// Definiciones independientes de la implementación

void Destruir(pila & p) {
  while (!Es_Vacia(p))
    Pop(p);
}

void main() {
  pila p= Crear();              // -
  Push(p, 1);                   // 1-
  Push(p, 2);                   // 2-1-
  Push(p, 3);                   // 3-2-1-

  cout << Top(p);               // 3
  Pop(p);                       // 2-1-
  cout << Top(p);               // 2
  Pop(p);                       // 1-
  cout << Top(p);               // 1
  Pop(p);                       // -
  Pop(p);                       // - Dar  error
  cout << Es_Vacia(p);	        // Claro, está vacía
  Destruir(p);	              // Bueno, destruimos de todas formas
  cout << Top(p);               // Habrá aviso
}