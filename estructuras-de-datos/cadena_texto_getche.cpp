#include<stdio.h>
#include<conio.h>

void main(){
int i;
char cadena [20];

for(i=0;i<19&& cadena[i-1]!=13;i++)
cadena[i]=getche();
if(i==19)
cadena[i]='\0';
else
cadena[i-1]='\0';
printf("\n%s",cadena);
getche();
}
