//Ej21_09.cpp

#include <iostream>
#include <string>
#include <map>
#include <conio.h>

using namespace std;

class CEmpleado{
private: long dni;
		 int ant;
		 long sueldo;
		 string nombre;
		 string primer_ap;
		 string segundo_ap;
public: CEmpleado(long d,int a,long s,string n,string pa,string sa);
		string Obtener_nombre() {return nombre+" "+primer_ap+" "+segundo_ap;}
		int Obtener_ant(){return ant;}
		long Obtener_sueldo(){return sueldo;}
};

CEmpleado::CEmpleado(long d=0,int a=0,long s=0,string n="",string pa="",string sa="")
{dni=d;ant=a;sueldo=s;nombre=n;primer_ap=pa;segundo_ap=sa;
}


typedef multimap<long, CEmpleado, less<long> > MAP;

template <class T> void muestra(const multimap<T, CEmpleado, less<long> > &l)
{   MAP::iterator i;

     
    for (i = l.begin(); i != l.end(); ++i)//Recorre y muestra el conjunto
	{cout <<"DNI: "<< i->first <<" Nombre: "<<i->second.Obtener_nombre();
	 cout<<" Antiguedad: "<<i->second.Obtener_ant();
	 cout<<" Sueldo: "<<i->second.Obtener_sueldo()<<endl;
	}
    cout << endl;
} 

void main()
{
    MAP m1;
    MAP::iterator it;
    string nom,pa,sa;
    long dni,ant,sdo;
    do{
 	cout<<"Introduce el nombre, para finalizar fin ";
	cin>>nom;
	if (nom!="fin")
	{
   	 cout<<"Introduce el primer apellido ";
	 cin>>pa;
 	 
	 cout<<"Introduce el segundo apellido ";
	 cin>>sa;

	 cout<<"Introduce el dni ";
	 cin>>dni;

	 cout<<"Introduce la antiguedad ";
	 cin>>ant;

 	 cout<<"Introduce el sueldo ";
	 cin>>sdo;
	}
   	if (nom!="fin")
	{m1.insert(MAP::value_type(dni,CEmpleado(dni,ant,sdo,nom,pa,sa)));
  	 }
   }while (nom!="fin");

    cout<<"Datos ordenados por DNI: \n";	
	muestra(m1);
	getch();
}
