#include<iostream.h>
#include<conio.h>

class nodo
{
  public:
  int dato;
  nodo *next;
};
nodo *cab=NULL, *cola=NULL;   
int acolar(int n)
{
  int x=0;
  nodo *aux=cab;
  while(aux!=NULL && x==0)
  {
    if(aux->dato==n)
      x=1;
    aux=aux->next;
  }

  if(x==0)
  {
    nodo *nuevo = new nodo();
    nuevo->dato=n;
    nuevo->next=NULL;
    if(cab==NULL)
      cab=nuevo;
    else
      cola->next=nuevo;
    cola=nuevo;
    return 0;
  }
  else  
  {return 1;}
}

void imprimir()
{
  nodo *aux=cab;
  clrscr();
  cout<<"COLA: \n\n";
  while(aux!=NULL)
  {
    cout<<aux->dato<<"\n";
    aux=aux->next;
  }
}

void main()
{
  int o, num, control;
  char opc;
  do
  {
    clrscr();
    cout<<"OPC 1: Acolar\n";
    cout<<"OPC 2: Imprimir\n";
    cout<<"OPC 3: Salir\n\n";
    cout<<"INGRESE UNA OPCION: ";o=getche();
    switch(o)
    {
      case '1':
	do
	{
	  clrscr();
	  cout<<"Ingrese un numero: ";cin>>num;
	  control=acolar(num);
	  while(control==1)
	  {
	    clrscr();
	    cout<<"NUMERO REPETIDO!.Ingrese nuevamente: ";cin>>num;
	    control=acolar(num);
          }
	  cout<< "\n\n¿Desea volver a ingresar?: ";cin>>opc;
	}while(opc==83||opc==115);
      break;

      case '2':
        clrscr();
	cout<<"COLA : ";
	imprimir();
        getch();
      break;

      case '3':
	clrscr();
	gotoxy(32,5);cout<<"FIN DEL PROGRAMA";
      break;
    }
  }while(o!=3);
}






    

     


    