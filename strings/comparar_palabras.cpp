/*Cadenas*/
#include<conio.h>
#include<stdio.h>
void main()
{
char S1[80],S2[80];
clrscr();
printf("\nIntroduce una palabra:");
gets(S1);
printf("\nIntroduce otra palabra:");
gets(S2);
printf("Longitudes:de %s es %d de %s es %d\n",S1,strlen(S1),(S2),strlen(S2));
if(!strcmp(S1,S2))
{
printf("Las cadenas son iguales\n");
strcat(S1,S2);
printf(S1,S2);
}
getch();
}