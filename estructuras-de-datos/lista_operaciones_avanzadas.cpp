#include<iostream.h>
#include<stdio.h>
#include<conio.h>
class nodo{
public:
int dato;
nodo *next;
nodo *prev;
};
nodo *cab1=NULL, *cab=NULL, *cola=NULL, *cola1=NULL,*cab2;
void pila();
void incola();
void piladoble();
void coladoble();
void imprimir_insertar();
void imprimir_insertar_cola();
void circular_pila();
void imprimir_circular();
void main(){
int opcion;
do
{
clrscr();
printf("\tMENU: \n");
cout<<"Opc 1. Insertar_lista_pila: \n";
cout<<"Opc 2. Insertar_lista_cola: \n";
cout<<"Opc 3. Insertar_lista_doblepila: \n";
cout<<"Opc 4. Insertar_lista_doblecola: \n";
cout<<"opc 5. insertar_circular_doble: \n";
cout<<"Opc 6. Salir ";
printf("\n\nELIJA UNA OPCION(1/6): ");cin>>opcion;

switch(opcion)
{
 case 1:
	clrscr();
	pila();
	getch();
	break;

 case 2:
  incola();
  break;

  case 3:
  piladoble();
  break;
case 4:
  coladoble();
  break;
case 5:
  clrscr();
  circular_pila();
  break;

 case 6:
	clrscr();
	gotoxy(30,5);printf("FIN DEL PROGRAMA");
	break;

}
}while(opcion!=6);
}

void pila(){
char a;
nodo *aux;
int n;
do{
  imprimir_insertar();
  aux=new nodo ();
  gotoxy(1,1);printf("Ingrese un numero: ");cin>>n;
  aux->dato=n;
  aux->next=cab;
  cab=aux;
  imprimir_insertar();
  cout<<"\n\nDesea ingresar otro numero(s/n): ";cin>>a;
}while((a==83)||(a==115));
}
void incola (){

  nodo *aux, *temp=cab;
  int n;
  char o;
  do{
        clrscr();     
	gotoxy(1,2);cout<<"Ingrese numero "; cin>>n;
	aux=new nodo();
	aux->dato=n;
	aux->next=NULL;
  if(cola==NULL)
  {
    while(temp->next!=NULL)
	  temp=temp->next;
    cola=temp;
  }
  if(cab==NULL)
	cab=aux;
  else
	cola->next=aux;
  cola=aux;
  imprimir_insertar();
  cout<<"\n desea ingresar otro elemento (s/n)"; cin>>o;
	}while(o=='s'|| o=='S');
 }

void piladoble(){
char op1;
int n;
do{
  nodo *aux;
  aux=new nodo ();
  gotoxy(1,2);printf("Ingrese un numero: ");cin>>n;
  aux->dato=n;
  aux->prev=cab;
  if (cab1==NULL)
	cola=aux;
  else
	cab1->prev=aux;
  aux->prev=NULL;
  cab1=aux;
  imprimir_insertar_cola();
  cout<<"\n\nDesea ingresar otro numero(s/n): ";cin>>op1;
}while((op1==83)||(op1==115));
}
void coladoble(){
char op1;
int n;
do{
  imprimir_insertar_cola();
  nodo *aux1;
  aux1 = new nodo ();

  gotoxy(1,2);printf("Ingrese un numero: ");cin>>n;
  imprimir_insertar_cola();
  aux1 -> dato=n;
  aux1 -> next=NULL;
  if (cab1==NULL){
	cab1=aux1;
	 aux1 -> prev =NULL;
	}else{
	cola1 -> next=aux1;
	aux1 -> prev= cola1;
  }
  cola1=aux1;
  imprimir_insertar_cola();
  cout<<"\n\nDesea ingresar otro numero(s/n): ";cin>>op1;
}while((op1==83)||(op1==115));
}

void circular_pila(){
char a;nodo *aux,*aux2;
int n;
do{
  imprimir_circular();
  aux = new nodo ();
  gotoxy(1,1);printf("Ingrese un numero: ");cin>>n;
  aux -> dato=n;
  imprimir_circular();
  if(cab2==NULL)
   aux -> next= aux;
  else{
   aux -> next =cab2;
   aux2=cab2;
   while(aux2 ->next!= cab)
    aux2=aux2->next;
   aux2 -> next= aux;
   }
   cab=aux;
  imprimir_circular();

  cout<<"\n\nDesea ingresar otro numero(s/n): ";cin>>a;
}while((a==83)||(a==115));
getch();
}

void imprimir_insertar(){
nodo *aux=cab;
int y=3;
clrscr();
gotoxy(45,2);printf("LISTA simple: ");
while(aux!=NULL)
{
	gotoxy(45,y);printf("%d",aux->dato);
	aux=aux->next;
	y++;
}

}
void imprimir_insertar_cola(){
nodo *aux1=cab1;
int y=3;
clrscr();
gotoxy(58,2);printf("LISTA doble: ");
while(aux1!=NULL)
{
	gotoxy(58,y);printf("%d",aux1->dato);
	aux1=aux1->next;
	y++;
}

}

void imprimir_circular(){
nodo *aux;
aux=cab;
cout<<"\n"<<aux ->dato;
aux=aux -> next;
while (aux!=cab){
 cout<<aux->dato;
 aux=aux->next;}}
