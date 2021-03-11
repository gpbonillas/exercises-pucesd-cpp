#include<iostream.h>
#include<conio.h>
#include<stdio.h>

class nodo{
public:
char letra;
nodo *next;
};
nodo *cab=NULL;
void pilac(char c);
void imprimir();

void main()
{
  int c;
  cout<<"INGRESE UNA PALABRA: ";
  do
  {
    c=getche();
    if(c!=13)
    {
      pilac(c);
    }
  }while(c!=13);
  gotoxy(1,5);cout<<"LA PALABRA AL REVES ES: ";imprimir();
}

void pilac(char c)
{
  nodo *nuevo;
  nuevo=new nodo();
  nuevo->letra=c;
  nuevo->next=cab;
  cab=nuevo;
}

void imprimir()
{
  nodo *aux=cab;
  while(aux!=NULL)
  {
    cout<<aux->letra;
    aux=aux->next;
  }
}
  