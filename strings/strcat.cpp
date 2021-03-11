#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

int comparar(char *c1, char *c2);

void main(){
char c1[50];
char c2[50];
int r;
gotoxy(1,1);cout<<"Ingrese una cadena: ";gets(c1);
gotoxy(1,3);cout<<"Ingrese otra cadena: ";gets(c2);

r=comparar(c1,c2);

if(r==0)
{gotoxy(1,7);printf("Las cadenas son iguales");}
else{
if(r>0)
{gotoxy(1,7);printf("La cadena #1 es mayor que la #2, r= %d",r);}
else
{gotoxy(1,7);printf("La cadena #1 es menor que la #2, r= %d",r);}
}

}


int comparar (char *c1, char *c2){
int dif=0;

while((*c1!='\0' || *c2!='\0') && (dif==0))
	{
	if(*c1!=*c2)
	{dif=(*c1-*c2);}
	c1++;
	c2++;
	}
return dif;
}

