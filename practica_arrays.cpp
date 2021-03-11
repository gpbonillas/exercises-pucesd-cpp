#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
void main() {
int i, j, *puntero, vector1[10], vector[10], resul[10], aux=0, opcion, aux1=1;
clrscr();
gotoxy(15,1);cout <<"P R A C T I C A   D E   A R R A Y S";
cout<<"\n";
gotoxy(7,4);cout <<"INGRESADO";
gotoxy(22,4);cout <<"DIRECCION";
gotoxy(38,4);cout <<"VALOR";

for (i=0;i<10;i++) {
gotoxy(10,i+6); cin >>vector[i];
}

for (i=0;i<10;i++) {
puntero=&vector[i];
gotoxy(25,i+6);cout<< puntero;

*puntero=vector[i];
gotoxy(40,i+6);cout<< *puntero;
}
getche();

}