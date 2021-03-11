#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
int factorial (int a);
int i, j, *puntero, vector1[10], vector[20], resul[10], aux=0, a;
float aux1=1, n;

void main() {

clrscr();
gotoxy(15,1);cout <<"F A C T O R I A L    D E   N U M E R O S    D E   U N  A R R A Y S";
cout<<"\n\n";
cout <<"Ingrese el numero de digitos que desea MAXIMO 20: "; cin >> n;
cout<<"\n";

for (i=0;i<n;i++) {
gotoxy(10,i+6); cout <<"Ingrese "<<i+1<<" digito: "; cin >>vector[i];
}

for (i=0;i<n;i++) {
a=vector[i];
aux=factorial(a);
gotoxy(10,i+15); cout <<"Elemento n° "<<i+1<< " su valor es:  " <<a<< "    y su factorial es = " <<aux;
}
getche();

}

int factorial (int a){
float fact=1;
for (int i=1; i<=a; i++)  {
fact *=i;
}
return fact;
}

