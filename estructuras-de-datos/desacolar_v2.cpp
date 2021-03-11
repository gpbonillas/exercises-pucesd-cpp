#include<iostream.h>
#include<stdio.h>
#include<conio.h>

class nodo {
public:
int dato;
nodo *next;
nodo *prev;
};

nodo *cab=NULL, *cab1=NULL, *cola=NULL, *cola1=NULL;
void listscola(int n);
void listspila(int n);
void listdpila(int n);
void listdcola(int n);
void imprimir_simple();
void imprimir_dobles();
void desacolar();

void main()
{
  int n, opc;
  char opc1,opc2;
  do
  {
    clrscr();
    cout<<"   LISTAS\n\n";
    cout<<"Opc 1. Lista simple pila: \n";
    cout<<"Opc 2. Lista simple cola: \n";
    cout<<"Opc 3. Lista doble pila : \n";
    cout<<"Opc 4. Lista doble cola : \n";
    cout<<"Opc 5. Desacolar: \n";
    cout<<"Opc 6. Salir            : \n";
    cout<<"\n\n Ingrese una opcion: ";cin>>opc;

    switch(opc)
    {
      case 1:
	do
	{
          clrscr();
	  printf("Ingrese un numero: ");cin>>n;
          imprimir_simple();
	  listspila(n);
          imprimir_simple();
	  gotoxy(2,15);printf("¿DESEA VOLVER A INGRESAR?(S/N): ");cin>>opc1;
	}while(opc1==83||opc1==115);
        getche();
      break;

      case 2:
	do
        {
	  clrscr();
	  printf("Ingrese un numero: ");cin>>n;
          imprimir_simple();
	  listscola(n);
	  imprimir_simple();
	  gotoxy(2,15);printf("¿DESEA VOLVER A INGRESAR?(S/N): ");cin>>opc1;
	}while(opc1==83||opc1==115);
	getche();
      break;


      case 3:
	do
	{
	  clrscr();
	  printf("Ingrese un numero: ");cin>>n;
          imprimir_dobles();
	  listdpila(n);
	  imprimir_dobles();
	  gotoxy(2,15);printf("¿DESEA VOLVER A INGRESAR?(S/N): ");cin>>opc1;
	}while(opc1==83||opc1==115);
	getche();
      break;

      case 4:
	do
        {
	  clrscr();
	  printf("Ingrese un numero: ");cin>>n;
          imprimir_dobles();
	  listdcola(n);
	  imprimir_dobles();
	  gotoxy(2,15);printf("¿DESEA VOLVER A INGRESAR?(S/N): ");cin>>opc1;
        }while(opc1==83||opc1==115);
        getche();
      break;

      case 5:
	do
	{
	  clrscr();
	  desacolar();
          imprimir_simple();
	  printf("Desea desacolar nuevamente? ");cin>>opc2;
	}while(opc2==83 || opc2==115);
	getche();
      break;  

      case 6:
	clrscr();
	gotoxy(23,5);printf("FIN DEL PROGRAMA");
      break;

    }
  }while(opc!=6);
}

void desacolar()
{
  nodo *aux=cab, *aux1;
  if(cab->next==NULL)
    cab==NULL;
  else
  {
    aux1=aux;
    while(aux->next!=NULL)
    {
      aux1=aux;
      aux=aux->next;
    }
    aux1->next=NULL;
  }
}      

void listspila(int n)
{
  nodo *nuevo;
  nuevo=new nodo();
  nuevo->dato=n;
  nuevo->next=cab;
  cab=nuevo;
}

void listscola(int n)
{
  nodo *nuevo;
  nuevo=new nodo();
  nuevo->dato=n;
  nuevo->next=NULL;
  if(cab==NULL)
     cab=nuevo;
  else
     cola->next=nuevo;
  cola=nuevo;
}

void listdpila(int n)
{
  nodo *nuevo;
  nuevo=new nodo();
  nuevo->dato=n;
  nuevo->next=cab1;
  if(cab1==NULL)
     cola1=nuevo;
  else
     cab1->prev=nuevo;
  nuevo->prev=NULL;
  cab1=nuevo;
}

void listdcola(int n)
{
  nodo *nuevo;
  nuevo=new nodo();
  nuevo->dato=n;
  nuevo->next=NULL;
  if(cab1==NULL)
     cab1=nuevo;
  else
     cola1->next=nuevo;
  nuevo->prev=cola1;
  cola1=nuevo;
}

void imprimir_simple()
{
  nodo *aux=cab;
  int y=3;
  clrscr();
  gotoxy(40,2);printf("LISTA SIMPLE ES: ");
  while(aux!=NULL)
  {
    gotoxy(40,y);printf("%d",aux->dato);
    aux=aux->next;
    y++;
  }
}


void imprimir_dobles()
{
  nodo *aux=cola1;
  int y=3;
  clrscr();
  gotoxy(40,2);printf("LISTA DOBLE ES: ");
  while(aux!=NULL)
  {
    gotoxy(40,y);printf("%d",aux->dato);
    aux=aux->prev;
    y++;
  }
}




















































