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
    cout<<"Opc 2. Imprimir pila\n";
    cout<<"Opc 3. Imprimir cola\n";
    cout<<"Opc 4. Salir             \n";
    cout<<"\n\n Ingrese una opcion: ";cin>>opc;

    switch(opc)
    {
      case 1:
	do
	{
	  clrscr();
	  gotoxy(1,1);printf("Ingrese un numero: ");cin>>n;
	  ldcircular(n);
	  imprimir_cola();
	  gotoxy(1,1);printf("¿DESEA VOLVER A INGRESAR?(S/N): ");cin>>opc1;
	}while(opc1==83||opc1==115);
      break;

      case 2:
	  clrscr();
	  imprimir_pila();
          getch();
      break;

      case 3:
	  clrscr();
	  imprimir_cola();
	  getch();
      break;
       
      case 4:
	clrscr();
	gotoxy(32,5);printf("FIN DEL PROGRAMA");
      break;

    }
  }while(opc!=4);
}

void ldcircular(int n)
{
  nodo *nuevo;
  nuevo=new nodo();
  nuevo->dato=n;
  if(cab==NULL)
     cab=nuevo;
  else
  {
    cola->next=nuevo;
    nuevo->prev=cola;
  }
  nuevo->next=cab;
  cab->prev=nuevo;
  cola=nuevo;
}


void imprimir_cola()
{
  nodo *aux=cab;
  int y=4;
  clrscr();
  gotoxy(46,2);printf("COLA: ");
  gotoxy(46,3);cout<<aux->dato;
  aux=aux->next;
  while(aux!=cab)
  {
    gotoxy(46,y);printf("%d",aux->dato);
    aux=aux->next;
    y++;
  }
}


void imprimir_pila()
{
  nodo *aux=cola;
  int y=4;
  clrscr();
  gotoxy(10,2),cout<<"PILA: ";
  gotoxy(10,3);cout<<aux->dato;
  aux=aux->prev;
  while(aux!=cola)
  {
    gotoxy(10,y);cout<<aux->dato;
    aux=aux->prev;
    y++;
  }
}



















































