//Ej21_05.cpp

#include <iostream>
#include <set>
#include <numeric>
#include <conio.h>

using namespace std;
 
template <class T> void muestra(set <T> &l)
{   // se crea salida como iterador de salida
    // Se a�adira una espacio despu�s de la salida de cada valor
    ostream_iterator<int> salida(cout," ");
    cout<<endl;
    //copia los valores de l a salida
	copy(l.begin(),l.end(),salida);
	cout<<endl;
}

void main()
{
	set<int> v1; //v1 es una instancia de la clase vector 
			   //que almacena enteros
	set<int>::iterator it; // it es un iterador que recorrer� el
					 // vector
	int n;
    
	do{
	cout<<"Introduce un numero (fin=0) ";
	cin>>n;
	if (n!=0) v1.insert(n);
	}while (n!=0);
	
	cout<<"Valores introducidos ";
	muestra(v1);
	
	getch();
}


