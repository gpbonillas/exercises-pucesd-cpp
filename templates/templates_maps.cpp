//Ej21_06.cpp

#include <iostream>
#include <string>
#include <map>
#include <conio.h>
#include <utility>

using namespace std;


typedef multimap<string, string, less<string> > MAP;

template <class T> void muestra(multimap<T, string, less<string> > &l)
{   MAP::iterator i;

    for (i = l.begin(); i != l.end(); ++i)//Recorre y muestra el conjunto
        cout << i->first << " "<<i->second<<endl;
    cout << endl;
}

void main()
{
// 1. Create a map of ints to strings
    MAP m1;
    MAP::iterator it;

    string ape,nom;
   	// Inserta en el conjunto los siguientes pares
   do{
	cout<<"Introduce el apellido (finalizar=fin) ";
	cin>>ape;
	if (ape!="fin")
	{cout<<"Introduce el nombre ";
	cin>>nom;
	}
   	if (ape!="fin")
	{ m1.insert(MAP::value_type(ape,nom));}
   }while (ape!="fin");

	muestra(m1);

	cout<<"Introduce el apellido de los empleados a buscar: ";
	cin>>ape;

	pair<MAP::iterator,MAP::iterator> it2 =m1.equal_range(ape);
		it=it2.first;
	if (it!=m1.end())
	{cout<<"Empleados con apellido "<<ape<<" : \n";
     do{
	   cout<<(*it).first<<" " <<(*it).second<<endl;
	   it++; 
	}	while (it!=it2.second);
    } else cout<<"No hay empleados con ese apellido\n";    
	getch();
}
