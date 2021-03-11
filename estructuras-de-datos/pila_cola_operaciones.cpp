#include<iostream.h>
#include<stdio.h>
#include<conio.h>
class nodo{
public:
int dato;
nodo *next;
};
nodo *cab1=NULL, *cab=NULL, *cola=NULL;
void insertar();
int tope_pila();
int tope_cola();
int base_cola();
int base_pila();
void imprimir();
void imprimir_insertar();

void main(){
int opcion, tc, tp, bc, bp;
do
{
clrscr();
printf("\tMENU: \n");
printf("\nOpc 1. Insertar: ");
printf("\nOpc 2. Tope    : ");
printf("\nOpc 3. Base    : ");
printf("\nOpc 4. Imprimir: ");
printf("\nOpc 5. Salir   : ");
printf("\n\nELIJA UNA OPCION(1/5): ");cin>>opcion;

switch(opcion)
{
 case 1:
	clrscr();
	insertar();
	getch();
	break;

 case 2:
	clrscr();
	tp=tope_pila();
	tc=tope_cola();
	if(tp==0&&tc==0)
	{gotoxy(30,5);printf("PILA Y COLA VACIA");}
	else
	{
	gotoxy(5,2);printf("TOPE PILA: %d",tp);
	gotoxy(25,2);printf("TOPE COLA: %d",tc);
	}
	getch();
	break;

 case 3:
	clrscr();
	bp=base_pila();
	bc=base_cola();
	if(bp==0)
	{gotoxy(30,5);printf("PILA Y COLA VACIA");}
	else
	{
	gotoxy(5,2);printf("BASE PILA: %d", bp);
	gotoxy(25,2);printf("BASE COLA: %d",bc);
	}
	getch();
	break;

 case 4: 
	clrscr();
	imprimir();
	getch();
	break;

 case 5:
	clrscr();
	gotoxy(30,5);printf("FIN DEL PROGRAMA");
	break;

}
}while(opcion!=5);
}



void insertar(){
nodo *npila, *ncola;
int num;
char op1;
do{      
     imprimir_insertar();
     npila= new nodo();
     ncola= new nodo();
     gotoxy(1,2);printf("Ingrese numero: ");scanf("%d",&num);
     imprimir_insertar();

     npila->dato=num;
     npila->next=cab;
     cab=npila;
     ncola->dato=num;
     ncola->next=NULL;
     if(cab1==NULL)
     {
       cab1=ncola;
     }
     else
       cola->next=ncola;
       cola=ncola;
     imprimir_insertar();
     gotoxy(1,2);printf("DESEA VOLVER A INGRESAR(S/N): ");cin>>op1;
     
  }while(op1==83||op1==115);
}


int tope_pila(){
if (cab==NULL)
  return 0;
else
  return cab->dato;
}   

int tope_cola(){
if (cab1==NULL)
  return 0;
else
  return cab1->dato;
}

int base_pila(){
nodo *aux=cab;
if(cab==NULL)
  return 0;
else{
     while(aux->next!=NULL)
     {aux=aux->next;}
     return aux->dato;
    }
}

int base_cola(){
if (cola==NULL)
    return 0;
else
    return cola->dato;
}


void imprimir(){
nodo *aux=cab, *aux1=cab1;
int y=3;
clrscr();
if (cab==NULL)
{gotoxy(30,5);printf("PILA Y COLA VACIA");}
else{
      gotoxy(2,2);printf("PILA : ");
      gotoxy(27,2);printf("COLA: ");
      while(aux!=NULL)
      {
        gotoxy(2,y);printf("%d",aux->dato);
        gotoxy(27,y);printf("%d",aux1->dato);
        aux=aux->next;
	aux1=aux1->next;
        y++;
      }
    }
  }

void imprimir_insertar(){
nodo *aux=cab, *aux1=cab1;
int y=3;
clrscr();
gotoxy(45,2);printf("PILA: ");
gotoxy(55,2);printf("COLA: ");
while(aux!=NULL)
{
   gotoxy(45,y);printf("%d",aux->dato);
   gotoxy(55,y);printf("%d",aux1->dato);
   aux=aux->next;
   aux1=aux1->next;
   y++;
}

}











  


















































































































































