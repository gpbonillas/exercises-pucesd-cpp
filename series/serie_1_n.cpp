#include<iostream.h>

void main(){
int num, i;
float resultado=0;
cout<<"Ingrese limite de sumatoria (1/n): ";cin>>num;
i=1;
while(i<=num)
{
  resultado=resultado+(1/i);
  i++;
}

cout<<"\n\nRESULTADO: "<<resultado;
}
