# include <iostream.h>
# include <stdio.h>
# include <conio.h>
# include <string.h>
# include <fstream.h>

void insertar (int n);
void eliminar (int n);
void mostrar ();

class nodo {
 	public :
 	int dato;
	nodo *next;
};
	nodo *aux=NULL;
	nodo *cab=NULL;
	nodo *cola=NULL;

void main (){
int opcion=0;
do {
clrscr();
gotoxy(20,2);cout<<" M E N U ";
gotoxy(10,5);cout<<"1.-  IN G R E S A R";
gotoxy(10,7);cout<<"2.-  I M P R I M I R";
gotoxy(10,9);cout<<"3.-  E L I M I N A R";
gotoxy(10,11);cout<<"4.-  E X I T ";
gotoxy(10,15);cout<<"Ingrese la opcion deseada:::::>>> ";cin>>opcion;

switch (opcion){
case 1:
	int n;
	clrscr();
	insertar(n);
	getch();
	break ;

case 2:
	clrscr();
	mostrar();
	getch();
	break ;

case 3:
	int l;
	clrscr();
	cout<< "Ingrese el valor que desea eliminar :" ;
	cin>>l;
	eliminar(l);
	getch();
	break ;

case 4:
	clrscr();
        opcion=4;
}

}while (opcion!=4);
	getch();
	}


void insertar(int n){

	 nodo *nuevo ;
	 cout<<"Ingrese numero: ";
	 cin>>n;
	 nuevo =new nodo;
	 nuevo->dato=n;
	 nuevo->next=cola->next;
	 cola->next=nuevo;
	 cab=nuevo;

}


void mostrar (){
	aux = cab;
	while (aux->next!=cab) {
		cout <<aux->dato<<endl;
		aux=aux->next;
                }
}

void eliminar(int n){
	nodo *aux ;
	nodo *mnodo;
	aux=cab;
	mnodo=aux;
	int op=1;
	if (cab->dato==n)
	     	cab=cab->next;
	else
	while ((aux!=NULL)&&(op==1)){
	     	aux =aux->next;
	if (aux->dato==n){
		mnodo->next=aux->next;
	     	op=0;
        }
        else
		mnodo=aux;
}
}
