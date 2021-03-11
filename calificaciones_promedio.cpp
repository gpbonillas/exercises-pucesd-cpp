/*PRAC.No.33
programa que captura las calificaciones de grupos escolares e
imprime ios promedios por grupo. También imprime eí promedio de
todos los grupos de la escuela */
#include <stdio.h>
#include <conio.h>
main(){
char escuela[30];
int ac, cc, gc, cont=0, cont1=0, cont2=0;
float proma=0, promg=0, promg2=0, promgt=0, promgral=0, calf, sum=0, sum2=0, sumt=0;
clrscr();
printf("\n\nNombre de la escuela:");
gets(escuela);
printf("\n\nNumero de grupos: ");
scanf("%d", &gc);
while(cont<gc){
   printf("\n\nCantidad de alumnos del grupo[%d]: ", cont+1);
   scanf("%d", &ac);
   printf("\n\nCantidad de calificiones por alumno: ");
   scanf("%d", &cc);
while(cont1<ac){
  while(cont2<cc){
  printf("\n\n Calificacion[%d] del alumno [%d]:", cont2+1, cont1+1);
  scanf("%f", &calf);
  sum=sum+calf;
  cont2++;}
proma=sum/cont2;
sum2=sum2+sum;
printf("\n\nEl promedio del alumno [%d] es: %.2f", cont1+1, proma);
cont1++;
promg=promg+proma;
proma=0;
cont2=0;
sum=0;
promg2=promg2+promg;
promg=0;}
cont1=0;
promgt=promg2/ac;
promg2=0;
sumt=sumt+promgt;
printf("\n\nEl promedio general del grupo [%d] es: %.2f, cont+1, promgt");
cont++;
sum2=0;
promgt=0;}
promgral=sumt/gc;
printf("\n\nEl promedio general de la escuela %s es: %.2f", escuela, promgral);
getch(); 
return 0;}