#include<iostream.h>
#include<stdio.h>
#include<conio.h>

char *obtener_cadena(char *c1);


void main(){
char c1[50];

cout<<"Ingrese una cadena: ";obtener_cadena(c1);
printf("\n\nLa cadena ingresada es: %s", c1);
}

char *obtener_cadena(char *c1){
do{
scanf("%c",&c1);
c1++;
}while(*c1!='\0');
return c1;
}