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
  nodo *aux, *cola;
  aux = new nodo();
  printf("Ingrese un numero: ");cin>>n;
  aux->dato=n;
  if(cab==NULL)
   cab=aux;
  else
  cola->next=aux;
  aux->next=cab;
  cola=aux;

  cout<<"\n\nDesea ingresar otro numero(s/n): ";cin>>op1;
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











