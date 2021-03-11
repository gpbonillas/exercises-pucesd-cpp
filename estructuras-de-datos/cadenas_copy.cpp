#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
void copiar (char *dest, char *orig);

void main()
{

char orig[50], dest[50];
gotoxy(1,2);printf("Ingrese una cadena:");gets(orig);
copiar (dest, orig);
gotoxy(1,7);printf("La cadena copiada es: %s",dest);

}


void copiar (char *dest, char *orig)
{
while(*orig!='\0'){
*dest=*orig;
dest++;
orig++;}
*dest='\0';
}



