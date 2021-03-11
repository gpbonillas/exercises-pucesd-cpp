/*Indica si un triangulo es isoseles, equilatero o escaleno*/
#include<stdio.h>
#include<conio.h>
void main()
{
float l1,l2,l3;
clrscr();
printf("Ingrese lado uno del triangulo:");
scanf("%f",&l1);
printf("Ingrese lado dos del triangulo:");
scanf("%f",&l2);
printf("Ingrese lado tres del triangulo:");
scanf("%f",&l3);
if(l1==l3&&l3==l2)
{
printf("El triangulo es equilatero");
}
else
{
if(l1==l2||l2==l3||l1==l3)
{
printf("El triangulo es isoseles");
}
else
{
printf("El triangulo es escaleno");
}
}
getch();
}