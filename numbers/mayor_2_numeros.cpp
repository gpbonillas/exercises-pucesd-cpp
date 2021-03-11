/*Mayor de dos numeros */
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{
int a,b;
clrscr();
printf("Dame el numero");
scanf("%d",&a);
printf("Dame el segundo valor:");
scanf("%d",&b);
if(a>b)
printf("El numero mayor es:==>%d",a);
else
getch();
return 0;
}