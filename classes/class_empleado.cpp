//Ej11_16.cpp

#include <iostream.h>
#include <conio.h>

class Empleado{
private:
	 long DNI;
	 int antiguedad;
	 int num_hijos;
	 int* edad_hijos;
public:
	Empleado(long d,int a,int nh,int* eh);
	~Empleado();
	long Obtener_DNI() {return DNI;}
	int Obtener_Antiguedad() {return antiguedad;}
	int Obtener_num_hijos() {return num_hijos;}
	void Obtener_edad_hijos(int *e){e=edad_hijos;}
	void Modificar_DNI(long d) {DNI=d;}
	void Modificar_Antiguedad(int a) {antiguedad=a;}
	void Modificar_num_hijos(int nh,int* eh);
	void Mostrar();
};

Empleado::Empleado(long d,int a,int nh,int* eh)
{DNI=d;
 antiguedad=a;
 num_hijos=nh;
 edad_hijos=eh;
}

Empleado::~Empleado()
{delete []edad_hijos;
}

void Empleado::Modificar_num_hijos(int nh,int* eh)
{num_hijos=nh;
 delete [] edad_hijos; 
 edad_hijos=eh;
}


void Empleado::Mostrar()
{int i;
 cout<<"DNI: "<<DNI;
 cout<<"\nAntiguedad: "<<antiguedad;
 cout<<"\nNumero de hijos: "<<num_hijos<<endl;
 for (i=0;i<num_hijos;i++)
	 cout<<"Edad del hijo "<<i+1<<": "<<edad_hijos[i]<<"  ";
}

void main()
{}
