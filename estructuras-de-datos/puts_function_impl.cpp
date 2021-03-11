#include<iostream.h>
#include<stdio.h>
#include<conio.h>
int imprimir_cadena(char *c1);


void main(){

char c1[50];
cout<<"Ingrese una cadena:";gets(c1);
cout<<"La cadena ingresada es: ";imprimir_cadena(c1);

}

int imprimir_cadena(char *c1){
do{
printf("%c",*c1);
c1++;
}while(*c1!='\0');
}