//Ej13_07.cpp
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

class Persona{
protected: 
	int edad;
	char estado_civil;
	string nombre;
public:
	Persona(int e,char ec,string n);
	virtual void Mostrar();
};

Persona::Persona(int e,char ec,string n)
{edad=e;
 estado_civil=ec;
 nombre=n;
}

void Persona::Mostrar()
{cout<<"Edad= "<<edad<<"\nEstado civil= "<<estado_civil<<"\nNombre= "<<nombre;
 
}

class Alumno:public Persona {
private:
	 int curso;
	 int num_asignaturas;
public: Alumno(int e,char ec,string n,int c,int na);
		void Mostrar();
};

Alumno::Alumno(int e,char ec,string n,int c,int na):Persona(e,ec,n)
{curso=c;
 num_asignaturas=na;
}

void Alumno::Mostrar()
{Persona::Mostrar();
 cout<<"\nCurso= "<<curso<<"\nNumero de asignaturas= "<<num_asignaturas<<endl;
}

class Profesor:public Persona{
private: string departamento; // también se puede hacer con char*
		 string adscripcion;
public: Profesor(int e,char ec,string n,string d,string a);
		void Mostrar();
};

Profesor::Profesor(int e,char ec,string n,string d,string a):Persona(e,ec,n)
{departamento=d;
 adscripcion=a;
}

void Profesor::Mostrar()
{Persona::Mostrar();
 cout<<"\nDepartamento= "<<departamento<<"\nAdscripcion= "<<adscripcion<<endl;
}

void main()
{Persona *datos[50];
 int op,p=0,e,c,na,i;
 char ec;
 string n,d,a;
 do {
	 cout<<"\n1. Introduccion de un alumno \n";
	 cout<<"2. Introduccion de un profesor\n";
	 cout<<"3. Mostrar datos \n";
	 cout<<"4. Salir\n";
	 cout<<"Introduce opcion: ";
     cin>>op;
     if (op<1 || op>4) cout<<"Opcion incorrecta\n";
	 else			    
	   switch (op)
	 {case 1:if (p<50)
			{cout<<"Introduce la edad: "; cin>>e;
	         cout<<"Introduce el estado civil (C=casado, S=Soltero, O=Otros: ";cin>>ec;
	 		 cout<<"Introduce el nombre: "; cin>>n;
			 cout<<"Introduce el curso: ";cin>>c;
			 cout<<"Introduce el numero de asignaturas: ";cin>>na;
			 datos[p]=new Alumno(e,ec,n,c,na); p++;
			}
	        else cout<<"\nNo se pueden introducir mas datos\n";
			 break;
      case 2:if (p<50) 
		     {cout<<"Introduce la edad: "; cin>>e;
	          cout<<"Introduce el estado civil (C=casado, S=Soltero, O=Otros: ";cin>>ec;
	 		  cout<<"Introduce el nombre: "; cin>>n;
			  cout<<"Introduce el departamento: ";cin>>d;
			  cout<<"Introduce la adscripcion: ";cin>>a;
			  datos[p]=new Profesor(e,ec,n,d,a); p++;
			  }
	         else cout<<"\nNo se pueden introducir mas datos\n";
			 break;
	  case 3: cout<<"\nDatos\n";
		      for (i=0;i<p;i++) 
			  {datos[i]->Mostrar();
			  if ((i%3==0) && (i!=0)) {cout<<"\nPulsa una tecla para continuar";getch();cout<<endl;}
			  }
			  cout<<"\nPulsa una tecla para continuar";getch();cout<<endl;
		      break;
	  case 4:for (i=0;i<p;i++) delete datos[i]; 
	 }

 }while (op!=4);

}