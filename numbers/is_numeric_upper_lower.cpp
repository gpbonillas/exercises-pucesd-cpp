/*Programa que identifica car�cter num�rico, letra may�scula o min�scula */
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
main(){
int caracter;
clrscr();
printf("introduce un caracter:\n");
caracter=getchar();
if(isdigit(caracter)>0)
   printf("El caracter que introduciste es un numero\n");
if(islower(caracter)>0)
   printf("El caracter que introduciste es letra minuscula\n");
if(isupper(caracter)>0)
   printf("El caracter que introduciste es letra mayuscula\n");
getch(); 
return 0;}