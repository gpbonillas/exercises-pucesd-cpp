#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
void concatenan(char *c1, char *c2, int n);
void main(){
char c1[100], c2[50];
int lim;
gotoxy(1,1);printf("Ingrese una cadena: ");gets(c1);
gotoxy(1,2);printf("Ingrese otra cadena: ");gets(c2);
gotoxy(1,3);printf("Limite de la cadena 2: ");cin>>lim;
//strncat(c1,c2,lim);
concatenan(c1,c2,lim);
gotoxy(1,7);printf("La cadenas concatenadas son: %s",c1);
//gotoxy(1,10);printf("STRNCAT: %s",c1);
}

void concatenan(char *c1, char *c2, int n){
int r=0;
while(*c1!='\0'){
c1++;}
while(r<n){
*c1=*c2;
c1++;
c2++;
r++;
}
*c1='\0';
}
