#include<stdio.h>
#include<conio.h>
#include<iostream.h>
long fibonacci(long);
void main(){
long resultado, numero;
printf("Asigna un numero: ");
scanf("%ld",&numero);
cout<<&numero<<"\t";
resultado=fibonacci(numero);
printf("Fibonacci(%ld)=%ld\n",numero,resultado);
getche();
}

long fibonacci(long n){
if(n==0||n==1)
return n;
else
return fibonacci(n-1)+fibonacci(n-2);
}