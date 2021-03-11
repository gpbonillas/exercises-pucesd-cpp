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
{Empleado *empleados[50];	 
 int e=0,i,op,*eh,nh,a,em,op2;
 long d;
do {
	cout<<"\n1. Introduccion de un empleado\n";
	cout<<"2. Modificacion de un empleado\n";
	cout<<"3. Mostrar los datos de los empleados\n";
	cout<<"4. Salir\n";
	cout<<"Introduce opcion: ";
    cin>>op;
    if (op<1 || op>4) cout<<"Opcion incorrecta\n";
	 else			    
	  switch (op)
	 {
      case 1: if (e<50)
			  {cout<<"Introduce DNI: ";cin>>d;
		      cout<<"Introduce antiguedad: ";cin>>a;
			  cout<<"Introduce numero de hijos ";cin>>nh;
			  eh=new int[nh];
			  for (i=0;i<nh;i++)
			  {cout<<"Edad del hijo "<<i+1<<": "; cin>>eh[i];
			  }
		      empleados[e]=new Empleado(d,a,nh,eh); e++;
			  } else
			  {cout<<"\nNo se pueden introducir mas empleados\n";}
			  break;
      case 2:if (e==0) cout<<"\nNo se han introducido empleados\n"; 
		     else
			 { 
			   do{
				 cout<<"Introduce el empleado a modificar"; cin>>em;
			     if (em<0 || em>=e) cout<<"\nEmpleado erroneo\n";
			   }while (em<0 || em>=e);
			   do{
				 cout<<"Introduce el dato a modificar\n";
				 cout<<"1. DNI\n";
				 cout<<"2. Antiguedad\n";
				 cout<<"3. Número de hijos\n";
				 cout<<"Selecciona una opcion: ";
				 cin>>op2;
			   } while (op2<1 || op2>3);
			   switch (op2)
			   {case 1: cout<<"\nIntroduce DNI: ";cin>>d;
			            empleados[em]->Modificar_DNI(d);
						break;
	            case 2: cout<<"Introduce antiguedad: ";cin>>a;
					    empleados[em]->Modificar_Antiguedad(a);
						break;
				case 3:	cout<<"Introduce numero de hijos ";cin>>nh;
					    eh=new int[nh];
						for (i=0;i<nh;i++)
						{cout<<"Edad del hijo "<<i+1<<": "; cin>>eh[i];}
						empleados[em]->Modificar_num_hijos(nh,eh); 						
			   }
			 }
		      break;
	  case 3: for (i=0;i<e;i++) 
			  {cout<<"\nDatos empleado "<<i+1<<endl;    
			   empleados[i]->Mostrar();
			   cout<<endl;
			   if ((i%3==0) && (i!=0)) {cout<<"\nPulsa una tecla para continuar"<<endl;getch();cout<<endl;}
			  }
			  cout<<"\nPulsa una tecla para continuar"<<endl;getch();cout<<endl;
		      break;
	  case 4:for (i=0;i<e;i++) delete empleados[i]; 
	 }}while (op!=4);
}