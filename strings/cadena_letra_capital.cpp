#include<iostream.h>
#include<stdio.h>

void capital(char *c1);

void main(){
char c1[50];
printf("Ingrese una cadena: ");gets(c1);

capital(c1);

printf("\n\nLa cadena es: %s", c1);

}


void capital(char *c1){
if(*c1>=97)
{*c1=*c1-32;}

c1++;
while(*c1!='\0')
{
if(*c1==64)
{*c1=*c1-32;}
if((*c1<=90)&&(*c1>=65))
{*c1=*c1+32;}
c1++;
}
}