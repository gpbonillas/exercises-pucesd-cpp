#include<iostream.h>
#include<conio.h>
void main()
{
  char palabra[25],ingreso;
  int i=0, j;
  do
  {
    clrscr();
    cout<<"Ingrese un caracter: ";cin>>palabra[i];
    i++;
    cout<<"\n\n¿DESEA INGRESAR NUEVAMENTE(S/N)?: ";cin>>ingreso;
  }while(ingreso==83||ingreso==115);
  clrscr();
  cout<<"LA PALABRA ORIGINAL ES: ";
  for(j=0;j<i;j++)
  {
    cout<<palabra[j];
  }
  cout<<"\n\nAL REVES ES: ";
  for(j=i-1;j>=0;j--)
  {
    cout<<palabra[j];
  }
}