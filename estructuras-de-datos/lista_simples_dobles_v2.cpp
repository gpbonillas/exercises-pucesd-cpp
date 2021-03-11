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
void ldoble(int n);
void imprimir_pila();
void imprimir_cola();
void eliminar(int n);

void main()
{
  int n, opc;
  char opc1, opc2;
  do
  {
    clrscr();
    cout<<"  LISTAS SIMPLES Y DOBLES\n\n";
    cout<<"Opc 1. Ingresar   \n";
    cout<<"Opc 2. Imprimir \n";
    cout<<"Opc 3. Desacolar \n";
    cout<<"Opc 4. Eliminar Doble \n";
    cout<<"Opc 5. Salir             \n";
    cout<<"\n\n Ingrese una opcion: ";cin>>opc;

    switch(opc)
    {
      case 1:
	do
	{
	  clrscr();
	  imprimir_pila();
	  gotoxy(1,1);printf("Ingrese un numero: ");cin>>n;
	  ldoble(n);
	  imprimir_pila();
	  gotoxy(1,1);printf("¿DESEA VOLVER A INGRESAR?(S/N): ");cin>>opc1;
	}while(opc1==83||opc1==115);
      break;

      case 2:
	  clrscr();
	  imprimir_pila();
          getch();
      break;

      case 3:
	do
	{
	  clrscr();
	  imprimir_pila();
	  if(cab==cola)
	  {cab=NULL;cola=NULL;}
	  else
          {
	    cola=cola->prev;
	    cola->next=NULL;
          }
          imprimir_pila();
	  gotoxy(1,1);printf("¿Desea desacolar nuevamente? ");cin>>opc2;
	}while(opc2==83||opc2==115);
      break;	  

      case 4:
	do
	{
	  clrscr();
	  imprimir_pila();
          gotoxy(1,1);printf("Ingrese valor a eliminar: ");cin>>n;
          eliminar(n);
	  imprimir_pila();
	  gotoxy(1,1);printf("¿Desea Volver a Ingresar?: ");cin>>opc2;
	}while(opc2==83||opc2==115);
      break;

      case 5:
	clrscr();
	gotoxy(32,5);printf("FIN DEL PROGRAMA");
      break;

    }
  }while(opc!=5);
}

void ldoble(int n)
{
  nodo *nuevo;
  nuevo=new nodo();
  nuevo->dato=n;
  if(cab==NULL)
  {
    cab=nuevo;
    nuevo->prev=NULL;
  }
  else
  {            
    cola->next=nuevo;
    nuevo->prev=cola;
  }
  nuevo->next=NULL;
  cola=nuevo;        

}


void imprimir_pila()
{
  nodo *aux=cab;
  int y=4;
  clrscr();
  gotoxy(30,2);printf("PILA: ");
  while(aux!=NULL)
  {
    gotoxy(30,y);printf("%d",aux->dato);
    aux=aux->next;
    y++;
  }
  //gotoxy(30,y);printf("%d",aux->dato);
}


void eliminar(int n)
{
  nodo *aux=cab->next,*aux1;

  if(cab->dato==n && cola==cab)
    {
      cab=cab->next;
      cola=NULL;
    }
  else
  {
    aux1=cab;
    while(aux!=cola && aux!=NULL)
    {
      if(aux->dato==n)
      {
	aux1->next=aux->next;
	aux=aux->next;
	aux->prev=aux1;
      }
      aux1=aux;
      aux=aux->next;
    }
    if(cola->dato==n)
    {
      aux1->next=aux->next;
      cola=aux1;
    }
  }
}
















































