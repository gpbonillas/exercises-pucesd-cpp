#include<iostream.h>
#include<conio.h>


void main()
{
  int pasc[16][31], i, j, x, y, a, d;
  char opc;
  do
  {
    clrscr();
    x=0;y=3;d=14;

    for(i=0;i<16;i++)
    {
      for(j=0;j<31;j++)
      {
	pasc[i][j]=0;
      }
    }

    do
    {
      gotoxy(1,1);cout<<"Ingrese limite del triangulo(1-15): ";cin>>a;
      if(a<2)
      {
        clrscr();
	gotoxy(27,7);cout<<"¡¡¡INGRESE LIMITE VALIDO!!!";
      }
    }while(a<2);

    pasc[0][15]=1;  
    for(i=1;i<=a;i++)
    {
      for(j=d;j<=((i*2)+d);j+=2)
      {
        pasc[i][j]=(pasc[i-1][j-1])+(pasc[i-1][j+1]);
      }
      d--;
    }

    clrscr();
    gotoxy(32,1);cout<<"TRIANGULO PASCAL # "<<a;
    for(i=0;i<=a;i++)
    {
      for(j=0;j<31;j++)
      {
	if(pasc[i][j]!=0)
	{
	  gotoxy(x,y);cout<<pasc[i][j];
	}
        x+=3;
      }
      x=0;
      y++;
    }
    
    gotoxy(1,23);cout<<"¿Desea volver a ingresar(s/n)?: ";cin>>opc;
  }while(opc==83||opc==115);
}








