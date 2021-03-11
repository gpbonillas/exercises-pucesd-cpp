#include<iostream.h>
#include<stdio.h>
#include<conio.h>

class nodo{
public:
int dato;
nodo *next;
};

nodo *cab=NULL;
nodo *cola=NULL;

void ingreso(int n);
void imprimir_pila();
void desapilar();
void eliminar(int n);

void main()
{
  int n;
  char o, opc;
  do
  {
    clrscr();
    gotoxy(15,1);cout<<"MENU";
    gotoxy(1,3);cout<<"Opc 1. Ingresar lista circular.";
    gotoxy(1,4);cout<<"Opc 2. Imprimir PILA.";
    gotoxy(1,5);cout<<"Opc 3. Desapilar. ";
    gotoxy(1,6);cout<<"Opc 4. Eliminar numero. ";
    gotoxy(1,7);cout<<"Opc 5. Salir. ";
    gotoxy(1,9);cout<<"Ingrese una opcion(1-5): ";opc=getche();

    switch(opc)
    {
      case '1':
	do
        {
	  clrscr();
          imprimir_pila();
	  gotoxy(1,1);cout<<"Ingrese numero: ";cin>>n;
	  ingreso(n);
	  imprimir_pila();
	  gotoxy(1,1);cout<<"¿DESEA VOLVER A INGRESAR(S/N)?: ";cin>>o;
	}while(o==83||o==115);
      break;

      case '2':
	clrscr();
	imprimir_pila();
	getch();
      break; 

      case '3':
	do
	{
	  clrscr();
          if(cab==NULL)
	  {
	    cout<<"PILA VACIA";
	  }
	  else
          {
	    desapilar();
	    gotoxy(1,1);cout<<"SE DESAPILO EXITOSAMENTE.";
          }
	    gotoxy(1,2);cout<<"DESEA DESAPILAR NUEVAMENTE(S/N)?:";cin>>o;
	}while(o==83||o==115);
      break;

      case '4':
	do
	{
	  clrscr();
	  imprimir_pila();
          gotoxy(1,1);cout<<"Ingrese numero a eliminar: ";cin>>n;
	  eliminar(n);
	  imprimir_pila();
	  gotoxy(1,1);cout<<"¿DESEA VOLVER A ELIMINAR(S/N)?: ";cin>>o;
	}while(o==83||o==115);
      break;

      case '5':
	clrscr();
	gotoxy(15,5);cout<<"FIN DEL PROGRAMA";
      break;

    }
  }while(opc!='5');
}


void ingreso(int n)
{
  nodo *nuevo;
  nuevo=new nodo();
  nuevo->dato=n;
  if(cab==NULL)
    cola=nuevo;
  else
    nuevo->next=cab;
  cola->next=nuevo;
  cab=nuevo;
}

void imprimir_pila()
{
  nodo *aux=cab;
  if(cab==NULL)
    {gotoxy(50,2);cout<<"PILA VACIA";}
  else
  {
    clrscr();
    gotoxy(50,2);cout<<"PILA: ";
    int y=4;
    gotoxy(50,y);cout<<aux->dato;
    aux=aux->next;
    y++;
    while(aux!=cab)
    {
      gotoxy(50,y);cout<<aux->dato;
      aux=aux->next;
      y++;
    }
  }
}

void desapilar()
{
  cab=cab->next;
  cola->next=cab;
}

void eliminar(int n)
{
  int temp=0;
  nodo *aux=cab, *aux1;
  if(cab->dato==n)
  {
    if(cab->next==cab)
      cab=NULL;
    cab=cab->next;
    cola->next=cab;
    temp=1;
  }
  aux1=cab->next;
  while(aux1!=cab && temp==0)
  {
    if(n==aux1->dato)
    {
      aux->next=aux1->next;
      temp=1;
    }
    aux=aux->next;
    aux1=aux1->next;
  }
}
    















          















      


































