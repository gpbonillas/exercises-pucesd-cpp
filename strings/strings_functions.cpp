#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<string.h>

int longitud1(char *c1);
int longitud2(char *c2);
void copiar (char *c3, char *c2);
void concatenar( char *c1, char *c2);
int comparar( char *c1, char *c2);

void main()
{
char opc='n';
char c1[100], c2[50], c3[50];
int l=0, l2=0, comp=0;
do
{
int s=0;
clrscr();
printf("Cadena 1: ");gets(c1);endl;
printf("Cadena 2: ");gets(c2);endl;
cout<<"\n";
l=longitud1(c1);
l2=longitud2(c2);
comp=comparar(c1, c2);
copiar(c3,c2);
concatenar(c1, c2);

printf("STRLEN-Cadena 1 tiene %d caracteres \n\n",l);
printf("STRLEN-Cadena 2 tiene %d caracteres \n\n",l2);
printf("STRCPY-Cadena 2 es: %s \n\n",c3);
if(comp==0)
{printf("STRCMP-Cadenas ingresadas son iguales \n\n");}
if(comp>0)
{printf("STRCMP-Cadena #1 > Cadena #2 , Dif= %d \n\n", comp);}
if(comp<0)
{printf("STRCMP-Cadena #1 < Cadena #2 , Dif= %d \n\n", comp);}
printf("STRCAT-Concatenacion 2 en 1: %s \n\n", c1);

gotoxy(1,21);printf("¿Desea volver a ingresar?: ");cin>>opc;
}while(opc=='s'||opc=='S');
}

int longitud1 (char *c1){
int cont=0;
while(*c1!='\0')
{
cont++;
c1++;
}
return cont;
}

int longitud2 (char *c2){
int cont1=0;
while (*c2!='\0')
{
cont1++;
c2++;
}
return cont1;
}

void copiar (char *c3, char *c2){
while(*c2!='\0')
{
*c3=*c2;
c3++;
c2++;
}
*c3='\0';
}

int comparar (char *c1, char *c2){
int r=0;
while((*c1!='\0'|| *c2!='\0')&(r==0)){
if (*c1!=*c2)
{r=(*c1-*c2);}
c1++;
c2++;
}
return r;
}

void concatenar (char *c1, char *c2){
while(*c1!='\0')
{c1++;}
while(*c2!='\0')
{*c1=*c2;
c1++;
c2++;
}
*c1='\0';
}


