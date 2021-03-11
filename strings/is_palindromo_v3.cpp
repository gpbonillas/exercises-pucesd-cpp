#include<iostream.h>
#include<conio.h>

void main()
{
  int i=0, j, activador=1, temp;
  char palin[25],auxiliar[25], ingreso;
  do
  {
    clrscr();
    cout<<"Ingrese caracter o numero: ";cin>>palin[i];
    i++;
    cout<<"\n\n\n¿DESEA INGRESAR OTRO CARACTER(S/N)?: ";cin>>ingreso;
  }while(ingreso==83||ingreso==115);
  temp=i;
  for(j=0;j<i;j++)
  {
    auxiliar[j]=palin[j];
  }
  j=i-1;
  i=0;
  while((i<temp)&&(activador==1))
  {
    if(auxiliar[j]==palin[i])
    {
      activador=1;
    }
    else
    {
      activador=0;
    }
    j--;
    i++;
  }
  clrscr();
  cout<<"La palabra : ";
  for(j=0;j<temp;j++)
  {
  cout<<palin[j];
  }

  if(activador==1)
  {
    cout<<"\n\nES UN PALINDROMO";
  }
  else
  {
    cout<<"\n\nNO ES UN PALINDROMO";
  }
}      

    
