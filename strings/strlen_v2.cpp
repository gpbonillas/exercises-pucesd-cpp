#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>

int longitud( char *orig);
void main()
{
char *orig;
int tam;
orig="pontificia universidad";
tam=longitud(orig);
gotoxy(1,6);printf("El tamaño de la cadena es: %d",tam);
}

int longitud( char *orig){
int l;
l=0;
while(*orig!='\0')
{orig++;
l++;}
return l;
}

