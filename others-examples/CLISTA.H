// ----------------------------------------------------------------------------
//
// Fichero			: CLISTA.H
// Tipo Componente		: Especificaci¢n
// Sistema			: Est ndar C++ 3.0
// Descripci¢n			: Clase Lista Circular
// Proyecto			: "Programaci¢n en C++"
// Autor			: JHO/EHO
// Versi¢n			: Versi¢n 2.0 Marzo 1993
//
// ----------------------------------------------------------------------------

#ifndef _CLISTA_H_
#define _CLISTA_H_

enum bool { FALSE, TRUE };

template <class info>
class clista {
  #include "EJ16_03.H1"		// MIEMBROS PRIVADOS
public:
// Constructor por defecto
  clista();

// Destructor
  ~clista();

// Constructor copia
  clista(const clista & );

// Operador de asignaci¢n
  const clista & operator = (const clista & );

// M‚todos constantes
    bool Vacia() const;
    bool Llena() const;
    info & Info() const;

// M‚todos no constantes
    void Insertar(info &);              // Insertar un elemento
    void Suprimir();                    // Suprimir un elemento
    const clista & operator ++();       // Moverse al pr¢ximo elemento. Preincremento
    const clista & operator --();       // Moverse al elemento previo. Preincremento
    clista operator ++(int );           // Moverse al pr¢ximo elemento. Postincremento
    clista operator --(int );           // Moverse al elemento previo. Postincremento
    void Super(const clista & );        // Hace una copia superficial de la lista
};

// Nota: operaciones como --l++ no funcionan del todo bien ya que una de las dos operaciones se realiza sobre un objeto temporal

#include "EJ13_04.H2"

#endif