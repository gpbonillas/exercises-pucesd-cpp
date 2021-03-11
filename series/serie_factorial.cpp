#include<iostream.h>
void main(){
long double i=1, j, x, factorial,resultado=1, potencia;
cout<<"Ingrese potencia de (e^x): ";cin>>x;
while(i<=100)
{
	 j=1;
	 factorial=1;
         potencia=1;
  while(j<=i)
  {
	 factorial=factorial*j;
	 j++;
  }
	 j=0;
  while(j<i)
  {
	 potencia=potencia*x;
         j++;
  }
  resultado=resultado+(potencia/factorial);
  i++;
}
cout<<"\n\nRESULTADO: "<<resultado;
}
