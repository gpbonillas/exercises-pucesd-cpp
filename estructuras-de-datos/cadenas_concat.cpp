#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
void concatena(char *c1, char *c2);
void main(){
char c1[100], c2[50];
gotoxy(1,1);printf("Ingrese una cadena: ");gets(c1);
gotoxy(1,2);printf("Ingrese otra cadena: ");gets(c2);
concatena(c1,c2);
gotoxy(1,7);printf("La cadenas concatenadas son: %s",c1);
}

void concatena(char *c1, char *c2){
while(*c1!='\0'){
c1++;}
while(*c2!='\0'){
*c1=*c2;
c1++;
c2++;
}
*c1='\0';
}
