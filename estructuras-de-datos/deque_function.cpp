//Ej21_04b.cpp

#include <iostream>
#include <deque>
#include <numeric>
#include <conio.h>

using namespace std;
 
template <class T> void muestra(deque <T> &l)
{   // se crea salida como iterador de salida
    // Se añadira una espacio después de la salida de cada valor
    ostream_iterator<int> salida(cout," ");
    cout<<endl;
    //copia los valores de l a salida
	copy(l.begin(),l.end(),salida);
	cout<<endl;
}

void main()
{
	deque<int> v1; //v1 es una instancia de la clase vector 
			   //que almacena enteros
	deque<int>::iterator it; // it es un iterador que recorrerá el
					 // vector
	int n;
    
	do{
	cout<<"Introduce un numero (fin=0) ";
	cin>>n;
	if (n!=0) v1.push_front(n);
	}while (n!=0);
	
	cout<<"Valores introducidos ";
	muestra(v1);
	
	getch();
}


