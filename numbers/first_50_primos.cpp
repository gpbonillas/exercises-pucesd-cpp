#include<iostream.h>
#include<conio.h>
void main()
{
  int primos[50],num=2, div=1, i=0, x=0, y1=1, y2=1;

  while(i<50)
  {
    while(div<=num)
    {
      if((num%div)==0)
      {
	x++;
      }
      div++;
    }
    if(x==2)
    {
      primos[i]=num;
      i++;
    }
    num++;
    div=1;
    x=0;
  }
  cout<<"LOS 50 PRIMEROS NUMEROS PRIMOS SON: ";
  for(i=0;i<50;i++)
  {
    if(i<25)
    {
      gotoxy(40,y1);cout<<primos[i];
      y1++;
    }
    else
    {
      gotoxy(50,y2);cout<<primos[i];
      y2++;
    }
  }
}
   