#include<iostream.h>
#include<stdio.h>
#include<conio.h>

class nodo {
public:
int dato;
nodo *next;
nodo *prev;
};

nodo *cab=NULL, *cola=NULL;
void ldcircular(int n);
void imprimir_pila();
void imprimir_cola();


void main()
{
  int n, opc;
  char opc1;
  do
  {
    clrscr();
    cout<<"  LISTAS SIMPLES Y DOBLES\n\n";
    cout<<"Opc 1. Ingresar   \n";
    cout<<"Opc 2. Imprimir \n";
    cout<<"Opc 3. Salir             \n";
    cout<<"\n\n Ingrese una opcion: ";cin>>opc;

    switch(opc)
    {
      case 1:
	do
	{
	  clrscr();
	  imprimir_pila();
          imprimir_cola();
	  gotoxy(1,1);printf("Ingrese un numero: ");cin>>n;
	  ldcircular(n);
	  imprimir_pila();
          imprimir_cola();
	  gotoxy(1,1);printf("¿DESEA VOLVER A INGRESAR?(S/N): ");cin>>opc1;
	}while(opc1==83||opc1==115);
      break;

      case 2:
	  clrscr();
	  imprimir_pila();
          imprimir_cola();
          getch();
      break;

      case 3:
	clrscr();
	gotoxy(32,5);printf("FIN DEL PROGRAMA");
      break;

    }
  }while(opc!=3);
}

void ldcircular(int n)
{
  nodo *nuevo;
  nuevo=new nodo();
  nuevo->dato=n;
  if(cab==NULL)
     cola=nuevo;
  else
  {
    nuevo->next=cab;
    cab->prev=nuevo;
    nuevo->prev=cola;
  }
  cab=nuevo;
  cola->next=nuevo;
}


void imprimir_pila()
{
  nodo *aux=cab;
  int y=4;
  clrscr();
  gotoxy(30,2);printf("PILA: ");
  gotoxy(30,3);cout<<aux->dato;
  aux=aux->next;
  while(aux!=cab)
  {
    gotoxy(30,y);printf("%d",aux->dato);
    aux=aux->next;
    y++;
  }
}


void imprimir_cola()
{
  nodo *aux=cola;
  int y=4;
  clrscr();
  gotoxy(45,2),cout<<"COLA: ";
  gotoxy(45,3);cout<<aux->dato;
  aux=aux->prev;
  while(aux!=cola)
  {
    gotoxy(45,y);cout<<aux->dato;
    aux=aux->prev;
    y++;
  }
}



















































