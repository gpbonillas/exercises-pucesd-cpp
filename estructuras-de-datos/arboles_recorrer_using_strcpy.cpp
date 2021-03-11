#include "conio.h"
#include "stdio.h"
#include "iostream.h"
#include <string.h>

class nodo{
public :
   char dato[100];
   nodo *izq;
   nodo *der;
} *raiz=NULL;

class nodoCola{
public:
  nodo *narbol;
  nodoCola *next;
};

nodoCola *cab=NULL, *cola=NULL;

void insertar (nodo **aux, char elem[]){
  if (*aux== NULL){
     nodo * nuevo;
     nuevo = new nodo();
     strcpy(nuevo->dato,elem);
     nuevo->izq = NULL;
     nuevo->der = NULL;
     *aux = nuevo;

  }
  else if (strcmp((*aux)->dato,elem) < 0)
      insertar(&(*aux)->der, elem);
  else
     if (strcmp((*aux)->dato,elem) > 0)
      insertar(&(*aux)->izq, elem);
}

void preorden(nodo *aux){
  if (aux!=NULL){
	  puts(aux->dato);cout<< endl;
	  preorden(aux->izq);
	  preorden(aux->der);
  }
}

void inorden(nodo *aux){
  if (aux!=NULL){
	  inorden(aux->izq);
	  puts(aux->dato);cout<< endl;
	  inorden(aux->der);
  }
}

void postorden(nodo *aux){
  if (aux!=NULL){
	  postorden(aux->izq);
	  postorden(aux->der);
	  puts(aux->dato);cout<< endl;
  }
}

void encolar(nodo *aux1)
{
  nodoCola *nuevo;
  nuevo = new nodoCola();
  nuevo->narbol =aux1;
  nuevo->next=NULL;
  if (cab == NULL)
    cab=nuevo;
  else
    cola->next =nuevo;
  cola = nuevo;
}

nodo *desencolar()
{

  nodo *aux;
  aux=cab->narbol;
  cab=cab->next;
  if(cab==NULL)
    cola=NULL;
  return aux;
}


void amplitud(nodo *arbol)
{
  nodo *rec;
    encolar(arbol);
    while (cab!=NULL)
    {
      rec=desencolar();
      printf("%s \n",rec->dato);
      if (rec->izq != NULL) encolar(rec->izq);
      if (rec->der != NULL) encolar(rec->der);
    }
}


void main()
{
  int i;
  char num[100];
   //v[17]={20,15,21,19,8,50,75,46,31,13,16,18,26,28,0,2,1};
  int o;
  char opc;
do
{
  clrscr();
  cout<<"\t\tMENU \n\n";
  cout<<"Opc 1: Cargar Arbol \n";
  cout<<"Opc 2: Imprimir Pre-Orden \n";
  cout<<"Opc 3: Imprimir Post-Orden \n";
  cout<<"Opc 4: Imprimir In-Orden \n";
  cout<<"Opc 5: Imprimir por Niveles \n";
  cout<<"Opc 6: Salir \n\n";
  cout<<"INGRESE UNA OPCION: ";o=getche();
  switch(o)
  {
    case '1':
      do
      {
        clrscr();
        gotoxy(1,1);cout<<"Ingresar Palabra: ";gets(num);
	insertar(&raiz,num);
	gotoxy(1,3);cout<<"¿Desea Ingresar nuevamente?: ";opc=getche();
      }while(opc==83||opc==115);
      getch();
    break;

    case '2':
      clrscr();
      gotoxy(10,1);cout<<"PRE-ORDEN\n";
      preorden(raiz);
      getch();
    break;

    case '3':
      clrscr();
      gotoxy(10,1);cout<<"POST-ORDEN\n";
      postorden(raiz);
      getch();
    break;

    case '4':
      clrscr();
      gotoxy(10,1);cout<<"IN-ORDEN\n";
      inorden(raiz);
      getch();
    break;

    case '5':
      clrscr();
      gotoxy(10,1);cout<<"POR NIVELES\n";
      amplitud(raiz);
      getch();
    break;

    case '6':
      clrscr();
      gotoxy(30,5);cout<<"FIN DEL PROGRAMA";
    break;
  }
}while(o!='6');
}

