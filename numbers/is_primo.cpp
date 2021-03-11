/*Numero primo o no primo*/
#include<conio.h>
#include<stdio.h>
void main()
{
int x,p,num;
p=0, x=1;
clrscr();
printf("Numero:\t");
scanf("%d",&num);
do
{
if(num%x==0)
{p++;
}x++;
}while(x<=num);
if(p<=2)
printf("Es primo");
else
printf("No es primo");
getch();
}