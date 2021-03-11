#include<iostream.h>
#include<stdio.h>
#include<conio.h>

class nodo {
public:
int dato;
nodo *next;
nodo *prev;
};

nodo *cab=NULL, *cola=NULL, *cab1=NULL, *cola1=NULL;
void ldpila(int n);
void ldcola(int n);
void ldcircular(int n);
void imprimir_pila();
void imprimir_cola();
void imprimir_circular_pila();
void imprimir_circular_cola();

void main()
{
  int n, opc;
  char opc1;
  do
  {
    clrscr();
    cout<<"  LISTAS SIMPLES Y DOBLES\n\n";
    cout<<"Opc 1. Lista doble pila   \n";
    cout<<"Opc 2. Lista doble cola \n";
    cout<<"Opc 3. Lista doble circular \n";
    cout<<"Opc 4. Imprimir pila\n";
    cout<<"Opc 5. Imprimir cola\n";
    cout<<"Opc 6. Imprimir circular pila\n";
    cout<<"Opc 7. Imprimir circular cola\n";
    cout<<"Opc 8. Salir             \n";
    cout<<"\n\n Ingrese una opcion: ";cin>>opc;

    switch(opc)
    {
      case 1:
	do
	{
	  clrscr();
	  gotoxy(1,1);printf("Ingrese un numero: ");cin>>n;
	  ldpila(n);
	  imprimir_pila();
	  gotoxy(1,1);printf("¿DESEA VOLVER A INGRESAR?(S/N): ");cin>>opc1;
	}while(opc1==83||opc1==115);
      break;

      case 2:
        do
        {
	  clrscr();
          gotoxy(1,1);cout<<"Ingrese un numero: ";cin>>n;
	  ldcola(n);
	  imprimir_pila();
	  gotoxy(1,1);cout<<"¿DESEA VOVER A INGRESAR?(S/N): ";cin>>opc1;
	}while(opc1==83||opc1==115);
      break;

      case 3:
        do
	{
	  clrscr();
	  gotoxy(1,1);cout<<"Ingree un numero: ";cin>>n;
	  ldcircular(n);
	  imprimir_circular_pila();
	  gotoxy(1,1),cout<<"¿DESEA INGRESAR NUEVAMENTE?(S/N): ",cin>>opc1;
	}while(opc1==83||opc1==115);
      break;

      case 4:
	  clrscr();
	  imprimir_pila();
          getch();
      break;

      case 5:
	  clrscr();
	  imprimir_cola();
	  getch();
      break;

      case 6:
	  clrscr();
	  imprimir_circular_pila();
	  getch();
      break;

      case 7:
	  clrscr();
	  imprimir_circular_cola();
	  getch();
      break;

      case 8:
	clrscr();
	gotoxy(32,5);printf("FIN DEL PROGRAMA");
      break;

    }
  }while(opc!=8);
}
void ldpila(int n)
{
  nodo *nuevo;
  nuevo=new nodo();
  nuevo->dato=n;
  nuevo->next=cab;
  if(cab==NULL)
    cola=nuevo;
  else
    cab->prev=nuevo;
  nuevo->prev=NULL;
  cab=nuevo;
}
void ldcola(int n)
{
  nodo *nuevo;
  nuevo=new nodo();
  nuevo->dato=n;
  nuevo->next=NULL;
  if(cab==NULL)
     cab=nuevo;
  else
    cola->next=nuevo;
    nuevo->prev=cola;
  cola=nuevo;
}

void ldcircular(int n)
{
  nodo *nuevo;
  nuevo= new nodo();
  nuevo->dato=n;
  if(cab1==NULL)
     cola1=nuevo;
  else
   {
     nuevo->next=cab1;
     cab1->prev=nuevo;
   }
   nuevo->prev=cola1;
   cola1->next=nuevo;
   cab1=nuevo;
}

void imprimir_cola()
{
  nodo *aux=cola;
  int y=4;
  clrscr();
  gotoxy(46,2);printf("COLA: ");
  while(aux!=NULL)
  {
    gotoxy(46,y);printf("%d",aux->dato);
    aux=aux->prev;
    y++;
  }
}


void imprimir_pila()
{
  nodo *aux=cab;
  int y=4;
  clrscr();
  gotoxy(45,2),cout<<"PILA: ";
  while(aux!=NULL)
  {
    gotoxy(45,y);cout<<aux->dato;
    aux=aux->next;
    y++;
  }
}


void imprimir_circular_pila()
{
   nodo *aux=cab1;
   int y=4;
   clrscr();
   gotoxy(45,2);cout<<"DOBLE CIRCULAR PILA: ";
   gotoxy(45,3);cout<<aux->dato;
   aux=aux->next;
   while(aux!=cab1)
   {
      gotoxy(45,y);cout<<aux->dato;
      aux=aux->next;
      y++;
   }
}


void imprimir_circular_cola()
{
   nodo *aux=cola1;
   int y=4;
   clrscr();
   gotoxy(45,2),cout<<"DOBLE CIRCULAR COLA: ";
   gotoxy(45,3);cout<<aux->dato;
   aux=aux->prev;
   while(aux!=cola1)
   {
      gotoxy(45,y);cout<<aux->dato;
      aux=aux->prev;
      y++;
   }
}













































