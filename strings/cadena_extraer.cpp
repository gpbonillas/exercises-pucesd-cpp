#include<iostream.h>
#include<stdio.h>
char *extraer(char *c1, int ini, int num=0);
int longitud(char *c1);
void main(){
char c1[50];
char *c2;
int ini=0, num=0;

printf("Ingrese una cadena: ");gets(c1);endl;
printf("\nIngrese # caracter inicio(C): ");scanf("%d",&ini);
printf("\nIngrese # caracteres adicionales(C+A): ");scanf("%d",&num);
c2=extraer(c1,ini,num);
printf("\n\nLa cadena extraida es: %s",c2);
}

char *extraer(char *c1, int ini, int num){
char temp[50];
int i;
if(num==0)
num=longitud(c1)-ini+1;
c1+=ini-1;
for(i=0;i<num;i++){
temp[i]=*c1;
c1++;
}
temp[i]='\0';
return temp;
}

int longitud(char *c1){
int d=0;
while(*c1!='\0'){
c1++;
d++;
}
return d;
}




