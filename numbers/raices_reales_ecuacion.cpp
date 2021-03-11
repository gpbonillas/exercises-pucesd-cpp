//Ej19_02.cpp

#include <set>
#include <iostream>
#include <algorithm>
#include <conio.h>

#include <iostream.h>
#include <math.h>
#include <conio.h>

void main()
{float a,b,c,x,discriminante,raiz_cuad,x1,x2;

/*lectura de datos*/
cout<<"Calculo de las raixes reales de una ecuacion ax^2+bx+c=0\n";
cout<<"Introducir los valores de: a, b y c:";
cin>>a>>b>>c;

/*calculo y escritura de resultados*/
if (a!=0.0)
{discriminante=pow(b,2)-4*a*c;
 if (discriminante<0) /*discriminante negativo */
	  cout<<"La ecuacion no tiene soluciones reales.\n";
 else
	 if (discriminante==0){ //discriminante nulo
		 x=-b/(2*a);
		 cout<<"La solucion es unica, x= "<<x<<endl;
	 }
	 else
	 {raiz_cuad=sqrt(discriminante);
	 x1=(-b-raiz_cuad)/(2*a);
	 x2=(-b+raiz_cuad)/(2*a);
	 cout<<"Las soluciones son x1= "<<x1<<" y x2= "<<x2;
	 }
}
else if (b!=0) cout<<"La solucion es unica, x= "<<-c/b<<endl;
     else cout<<"La solucion es indeterminada"<<endl;
	 cout<<endl;
	 getch();
}