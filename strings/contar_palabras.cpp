#include<stdio.h>

int contar_palabras(char *c1);

void main(){
char c1[100];
int numpalabras;
printf("Ingrese una cadena: ");gets(c1);
numpalabras=contar_palabras(c1);
printf("\n\n\nLa cadena ingresada tiene %d palabras",numpalabras);
}

int contar_palabras(char *c1){
int cont=0, flag=1;
while(*c1!='\0')
{
	while(*c1==32)
	{flag=1;
	c1++;}

	while(flag==1)
	{

	   if( ((*c1>='a')&&(*c1<='z')) ||  ((*c1>='A')&&(*c1<='Z'))  )
	   { cont++;
		flag=0; }
	}

	c1++;
	while(*c1==32)
	{flag=1;
	c1++;}

}
return cont;
}



