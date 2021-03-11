#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>

float x0=1.45, x1, func, der;
double tolerancia=0.00000000001, error=0.1;
int a, b, c;

void main(){
gotoxy(30,1);cout<<"METODO DE NEWTON-RAPHSON";
gotoxy(1,3);cout<<"Ingrese coeficientes: ";
gotoxy(12,5);cout<<"f(x)=(   )x^2+(    )x+(   )";
gotoxy(19,5);cin>>a;
gotoxy(28,5);cin>>b;
gotoxy(36,5);cin>>c;
if((b*b-4*a*c)<0)
{cout<<"No existe solucion";}
else
{
while (error>tolerancia){
func=(a*x0*x0)+(b*x0)+c;
der=(2*a*x0)+(b);
x1=x0-(func/der);
error=fabs((x1-x0)/x1);
x0=x1;
}
gotoxy(1,15);printf("La solucion aproximada es: %.12f",x1);
gotoxy(1,16);printf("El error aproximado es: %.12f",error);
}
}
