/*Programa que imprime que vocal se repite mas en una cadena */
#include <stdio.h>
#include <string.h>
#include <conio.h>
char vocal(void);
void main(){
char letra;
clrscr();
letra=vocal();
printf("La vocal que mas se repite es: %c", letra);
getch();}

char vocal(void){ 
char cad[50], mayor;
int x, a=0, e=0, i=0, o=0, u=0;
clrscr();
puts("Dar cadena:");
gets(cad);
for(x=0;x<=strlen(cad);x++){
  if(cad[x]=='a')
  a++;
  if(cad[x]=='e')
  e++;
  if(cad[x]=='i')
  i++;
  if(cad[x]=='o')
  o++;
  if(cad[x]=='u')
  u++;}
if(a>e&&a>i&&a>o&&a>u)
   mayor='a';
if(e>a&&e>i&&e>o&&e>u)
   mayor='e'; 
if(i>a&&i>e&&i>o&&i>u)
   mayor='i'; 
if(o>a&&o>e&&o>i&&o>u)
   mayor='o'; 
if(u>a&&u>e&&u>i&&u>o)
   mayor='u'; 
return mayor;}