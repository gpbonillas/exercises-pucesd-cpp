#include <iostream.h>
#include <conio.h>

class nodo{
public:
int dato;
nodo *next;
};

nodo *cab=NULL;

void insertar(int n)
{
  nodo *nuevo, *aux;
  nuevo=new nodo();
  nuevo->dato=n;
  if(cab==NULL)
  {cab=nuevo;}
  else
  {
    aux=cab;
    while(aux->next!=cab)
      aux=aux->next;
    aux->next=nuevo;
  }
  nuevo->next=cab;
  cab=nuevo;
}

void imprimir()
{
  nodo *aux=cab;
  cout<<aux->dato<<"\n";
  aux=aux->next;
  while(aux!=cab)
  {
    cout<<aux->dato<<"\n";
    aux=aux->next;
  }
}

void main()
{
  int o, num;
  char op;
  do
  {
  clrscr();
  cout<<"OPC 1: Ingresar\n";
  cout<<"OPC 2: Imprimir\n";
  cout<<"OPC 3: Salir\n";
  cout<<"\n\nINGRESE OPCION: ";o=getche();

  switch(o)
  {
    case '1':
      do
      {
	clrscr();
	cout<<"Ingrese numero: ";cin>>num;
	insertar(num);
	cout<<"\n\nDesea volver a ingresar?: ";cin>>op;
      }while(op==83 || op==115);
    break;

    case '2':
      clrscr();
      imprimir();
      getch();
    break;

    case '3':
      clrscr();
      cout<<"fin del programa";
    break;
  }
 }while(o!='3');
}




  

