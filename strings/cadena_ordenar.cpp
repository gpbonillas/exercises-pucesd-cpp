#include<iostream.h>
#include<stdio.h>
int longitud(char *c1);
int ordenar_cadena(char c1[]);
void main(){
char c1[100];
int vec;
printf("Ingrese una cadena: ");gets(c1);
vec=ordenar_cadena(c1);
printf("\n\nLa cadena ordenada alfabeticamente: %s",c1);
printf("\n\nEl bucle se repitio %d veces.",vec);
}
int ordenar_cadena(char c1[]){
char temp;
int i=0, j, l,flag=1;
l=longitud(c1);
while((i<l)&&(flag==1))
	 {
	 flag=0;
	 for(j=i+1;j<l;j++)
		  {
		  if(c1[j]<c1[i])
				{
				temp=c1[i];
				c1[i]=c1[j];
				c1[j]=temp;
				flag=1;
				}
		  }
	 i++;
	 }
return i;
}


int longitud(char *c1){
int d=0;
while(*c1!='\0')
{
c1++;
d++;
}
return d;
}
