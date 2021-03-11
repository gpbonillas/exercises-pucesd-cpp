#include<stdio.h>
#include<conio.h>

 int factorial(int num)
     {
      int i,fact=1;
      for(i=1;i<=num;i++)
	 {fact=fact*i;}
      return fact;
     }


 void main()
 {
  int x;
  printf("Ingrese el #..");scanf("%d",&x);
  printf("\n\nEl fact de %d es: %d",x,factorial(x));
 }