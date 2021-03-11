//Ej22_02.cpp

#include <vector>
#include <conio.h>
#include <iostream>
#include <algorithm>

using namespace std ;


template <class T> void muestra(const vector <T> &l)
{   ostream_iterator<int> salida(cout," ");
    cout<<endl;
	copy(l.begin(),l.end(),salida);
	cout<<endl;
}

void potencia(int &v)
{int p=1;
 while (v>p) 
 {
	p*=2;
 }
 v=p; 
}

void main()				   
{
	vector <int> v1;
	int n;

	cout<<"Intoduce numeros. Finalizar=0 ";
	do{
	cin>>n;
	if (n!=0) v1.push_back(n);
	}while (n!=0);
   	
	for_each(v1.begin(),v1.end(),potencia);
 	cout<<"Valores del vector modificados ";
	muestra(v1);

	getch();
}

