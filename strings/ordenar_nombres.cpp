/*Pide dos nombres y los ordena alfabéticamente */
#include <stdio.h>
#include <conio.h>
#include <string.h>
main(){
char nombre1[40], nombre2[40];
clrscr();
fflush(stdin);
printf("dame el primer nombre: ");
gets(nombre1);
printf("\n\ndame el segundo nombre: ");
gets(nombre2);
printf("\n\nen orden alfabético es:");
if(strcmp(nombre1, nombre2)<0){
   printf("%s\n", nombre1);
   printf("%s\n", nombre2);}
else{
   printf("%s\n", nombre2);
   printf("%s\n", nombre1);}
getch();
return 0;}



