#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int verificar (char cad );
char opc[10][15]={"argentina", "ecuador", "canada", "mexico", "portugal", "venezuela", "colombia", "dinamarca", "australia", "inglaterra"};
char ahpal[15];

void main(){

char tur, opcion, gano;
int aciertos, errores, lim, o, e, n, c;

aciertos=0; errores=0; lim=0; o=0;
tur=0; opcion='n'; gano='n'; n=0;

e=random(10-1)+1;
gets(opc[e]);
n=strlen(opc[e]);
c=0;
for(int i=0; i<n; i++){
ahpal[i]=opc[1][c];
c++;
}

for(i=0; i<n; i++){
cout<<ahpal[i]<<"\n";
}
}


