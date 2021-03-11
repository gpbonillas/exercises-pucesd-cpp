#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
void copiar (char dest[], char orig[]);

void main()
{
char orig[50], dest[50];

gotoxy(1,2);printf("Ingrese una cadena:");gets(orig);

copiar(dest,orig);

gotoxy(1,7);printf("La cadena copiada es: %s",dest);
gotoxy(1,9);printf("La cadena original es: %s",orig);
}


void copiar (char dest[], char orig[]){
int i;
for (i=0; orig[i]!='\0'; i++){
dest[i]=orig[i];
}
dest[i]='\0';
}



