#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

int compararn(char *c1, char *c2, int d);

void main(){
char c1[50];
char c2[50];
int r, d;
gotoxy(1,1);cout<<"Ingrese una cadena: ";gets(c1);
gotoxy(1,3);cout<<"Ingrese otra cadena: ";gets(c2);
gotoxy(1,5);cout<<"¿Ingrese el limite de la comparacion?:";cin>>d;
int s=strncmp(c1,c2,d);
r=compararn(c1,c2,d);

if(r==0)
{gotoxy(1,9);printf("Las cadenas son iguales");}
else{
if(r>0)
{gotoxy(1,9);printf("La cadena #1 es mayor que la #2, r= %d",r);}
else
{gotoxy(1,9);printf("La cadena #1 es menor que la #2, r= %d",r);}
}
gotoxy(1,20);cout<<"STRNCMP= "<<s;
}


int compararn (char *c1, char *c2, int d){
int dif=0, n=0;

while((n<d)&&(dif==0))
	{
	if(*c1!=*c2)
	{dif=(*c1-*c2);}
	c1++;
	c2++;
	n++;
	}
return dif;
}

