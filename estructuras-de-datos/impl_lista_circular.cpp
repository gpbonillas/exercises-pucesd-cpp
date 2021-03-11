// EJ09_03.CPP

// Implementa una lista circular

#include <stddef.h>     // NULL
#include <iostream.h>	// cout

// Variaciones posibles por el usuario

void Aviso(const char *s) {
  cout << "\nSe ha producido un error en la lista. El error es:\n" << s << endl;
}

typedef	int info_t;		// Vamos a probarla para enteros
const int ERROR_ELEM= -1;	// Elemento error;
const void (*F_Error)(const char *)= Aviso;

// Definiciones necesarias

enum bool { FALSE, TRUE };

struct nodo {
  info_t Info;
  nodo *Ant, *Post;			// Anterior y Posterior
};

typedef nodo *clista;

// Prototipos de la implementaci¢n

clista Crear();	                        // Crea la lista
void Destruir(clista & );               // Destruye la lista
bool Es_Vacia(clista & );               // ¿Está  vacía?
void Insertar(clista &, info_t );	// Insertar elemento antes del actual
void Borrar(clista &);  		// Borrar elemento actual
info_t & Info(clista &);                // Acceso al elemento actual
clista & Post(clista &);                // Lista posterior
clista & Ant(clista &);                 // Lista anterior

// Definiciones dependientes de la implementaci¢n

int ERROR_COP;
clista NULL_V;

clista Crear() {
  return NULL;
}

bool Es_Vacia(clista & l) {
  return bool(!l);                      // l != NULL
}

clista & Post(clista & l) {
  if (l)					// l != NULL
    return l->Post;
  else
    return NULL_V= NULL;           	// Para retornar por referencia
}

clista & Ant(clista & l) {
  if (l)
    return l->Ant;
  else
    return NULL_V= NULL;
}

info_t & Info(clista & l) {
  if (l)
    return l->Info;
  else {
    (*F_Error)("Accediendo a una lista vacía");
    return ERROR_COP= ERROR_ELEM;
    // No podemos retornar constantes por referencia
  }
}

// Definiciones independientes de la implementaci¢n

void Insertar(clista & l, info_t Inf) {
  clista Ret;

  Ret= new nodo;			// Reserva espacio
  Info(Ret)= Inf;
  if (Es_Vacia(l))
    Post(Ret)= Ant(Ret)= Ret;
  else {
    Ant(Ret)= Ant(l);
    Post(Ret)= l;
    Post(Ant(l))= Ret;
    Ant(l)= Ret;		// 4 enlaces realizados
  }
  l= Ret;
}

void Borrar(clista & l) {
  if (Es_Vacia(l))
    (*F_Error)("No se puede borrar sobre una lista vacía");
  else {
    clista Temp;
    if (Post(l) == l)		// Lista £nica;
      Temp= Crear();
    else {
      Post(Ant(l))= Post(l);	//
      Ant(Post(l))= Ant(l);	// Pasar el elemento
      Temp= Post(l);
    }
    delete l;
    l= Temp;
  }
}

void Destruir(clista & l) {
  while (!Es_Vacia(l))
    Borrar(l);
}

void main() {
  clista l= Crear();       // -
  Insertar(l, 1);          // -1-
  Insertar(l, 2);          // -2-1-
  Insertar(l, 3);          // -3-2-1-

  cout << Info(l);         // 3
  l= Ant(l);               // -1-3-2-
  cout << Info(l);         // 1
  l= Ant(l);               // -2-1-3-
  cout << Info(l);         // 2
  l= Post(l);	           // -1-3-2-
  cout << Info(l);         // 1
  Borrar(l);	           // -3-2-
  cout << Info(l);	   // 3
  cout << Info(Post(l));   // 2

  Destruir(l);
  cout << Info(l);         // Habr  aviso
  Borrar(l);	           // Habr  aviso
  cout << Es_Vacia(l);     // Claro, es que está vacía
}