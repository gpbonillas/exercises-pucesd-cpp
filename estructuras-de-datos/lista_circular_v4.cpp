#include<iostream.h>
#include<stdio.h>
#include<conio.h>
class nodo{
public:
int dato;
nodo *next;
};
void enlistar ();
void imprimir ();
void imprimir_lista();
nodo *cab=NULL,*lista=NULL;
void main(){
int op;
do{
clrscr();
printf("\tMENU\n");
cout<<"Opc 1. Enlistar: \n";
cout<<"Opc 2. Imprimir: \n";
cout<<"Opc 3. Salir   : \n";
cout<<"\nOPCION(1-3): ";cin>>op;
switch(op){
case 1:
  enlistar();
break;

case 2:
  imprimir();
  getche();
break;

case 3:
  clrscr();
  gotoxy(30,3);cout<<"FIN DEL PROGRAMA";
}
}while(op!=3);}


void enlistar(){
char op1;
int n;
do{
  clrscr();
  nodo *aux, *aux1;
  aux = new nodo();
  imprimir_lista();
  gotoxy(1,1);printf("Ingrese un numero: ");cin>>n;
  aux->dato=n;
  if(cab==NULL)
     aux->next=aux;
  else
  {
     aux->next=cab;
     aux1=cab;
     while(aux1->next!=cab)
           {aux1=aux1->next;}
     aux1->next=aux;
  }
  cab=aux;
  imprimir_lista();
  gotoxy(1,1);cout<<"¿DESEA INGRESAR NUEVAMENTE?(S/N): ";cin>>op1;
}while((op1==83)||(op1==115));
}


void imprimir(){
clrscr();
cout<<"LA PILA ES: \n";
nodo *aux=cab;
if(aux==NULL)
{
  clrscr();
  cout<<" \n   LA PILA ESTA VACIA ";
}
else
{
  cout<<"\n"<<aux->dato;
  aux=aux->next;
  while(aux!=cab)
  {
    cout<<"\n"<<aux->dato;
    aux=aux->next;
  }
}
}


void imprimir_lista()
{
  nodo *aux=cab;
  int i=5;
  clrscr();
  if(cab==NULL)
  {gotoxy(47,2);cout<<"LA PILA ES: ";}
  else
  {
     gotoxy(47,2);cout<<"LISTA CIRCULAR ES: ";
     gotoxy(47,4);cout<<aux->dato;
     aux=aux->next;
     while(aux!=cab)
     {
       gotoxy(47,i);cout<<aux->dato;
       aux=aux->next;
       i++;
     }
  }
}








