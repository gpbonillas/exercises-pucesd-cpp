#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
void main() {
int i, j, *puntero, vector1[10], vector[10], resul[10], aux=0, opcion, aux1=1;
clrscr();
gotoxy(15,1);cout <<"S U M A     D E    A R R A Y S";
cout<<"\n";
gotoxy(7,4);cout <<"ARRAY 1";
gotoxy(22,4);cout <<"ARRAY 2";
gotoxy(38,4);cout <<"RESULTADO";
gotoxy(18,9);cout <<"+";
gotoxy(32,9);cout <<"=";

for (i=0;i<10;i++) {
gotoxy(10,i+6); cin >>vector[i];
gotoxy(25,i+6); cin >>vector1[i];
resul[i]=vector1[i]+vector[i];
}

for (i=0;i<10;i++) {
*puntero=resul[i];
gotoxy(40,i+6);cout<< *puntero;
}
getche();

}