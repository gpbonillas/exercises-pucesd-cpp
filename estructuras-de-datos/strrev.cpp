#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
void invertir(char *c1);

void main(){
  char c1[50];
  gotoxy(1,1);cout<<"Ingrese una cadena: ";gets(c1);
  invertir(c1);
  gotoxy(1,5);cout<<"La cadena invertida es : ";puts(c1);
}

void invertir(char *c1){
  int cont=0;
  int cont2=0;
  char *copinv;

  while(*c1!='\0'){
  c1++;
  cont++;
  }

  while(cont>=0){
  *copinv=*c1;
  copinv++;
  c1--;
  cont--;
  cont2++;
  }

  *copinv='\0';
  c1++;
  copinv--;

  while(cont2>0){
  *c1=*copinv;
  c1++;
  copinv--;
  cont2--;
  }

  *c1='\0';
}

