//Ej22_03.cpp

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

int primos()
{static int numero=0;
 int divisor=2;
 numero++;
 if (numero == 1) return numero;
  else {numero--;
	  do{numero++;
	  while (numero % divisor != 0) divisor++;
	  
	  }while (divisor!= numero); 
      }
   return numero;
}

void main()				   
{
	int n;

	cout<<"Cuantos numeros primos quieres introducir: ";
	cin>>n;
   	
	vector <int> v1(n);
	
	generate(v1.begin(),v1.begin()+n,primos);
 	cout<<"Valores del vector generados por la funcion primos ";
	muestra(v1);

	getch();
}

