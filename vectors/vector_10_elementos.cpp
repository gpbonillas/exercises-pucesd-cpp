//Ej20_01.cpp

#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

void main()
{	//crea un vector de 10 elementos de tipo entero
	int c1[]={1,2,3,4,5,6,7,8,9,10},t1;

    //determina la longitud del vector c1
	t1=sizeof(c1)/sizeof(int);	
	//crea un vector v1 con los elementos de c1
    vector <int> v1(c1,c1+t1);

	//crea un iterator para recorrer el vector
	vector<int>::iterator it;
	//it apunta al primer elemento del vector
	it=v1.begin();
	cout<<"Utilizando un iterador de acceso aleatorio hacia adelante, los elementos de c1 son: "<<endl;
	//se recorre el vector de izquierda a derecha
	while (it!=v1.end())
	{cout<<*it;
	 it+=2;
	 if (it!=v1.end()) cout<<", ";
	}
	cout<<endl<<"Utilizando un iterador de acceso aleatorio hacia detras, los elementos de c1 son: "<<endl;
	//se recorre el vector de derecha a izquierda
	do
	{it-=2;
	 cout<<*it;
	 if (it!=v1.begin()) cout<<", ";
	} while  (it!=v1.begin());


	getch();


}