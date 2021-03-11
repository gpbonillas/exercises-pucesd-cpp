# include <stdio.h>
# include <iostream.h>
# include <conio.h>

class nodo{
public:
int dato;
nodo *next;
};
nodo *cab=NULL,*cola=NULL,*d;


void insertar (int n);
void imprimir();
void eliminar();

void main(){

int op,n;
do{
clrscr();
cout<<" M E N U   D E   O P C I O N E S ";
cout<<"\n1.- INSERTAR";
cout<<"\n2.- IMPRIMIR";
cout<<"\n3.- SALIR";
cout<<"\nELIGA LA OPCION DESEADA";cin>>op;

switch(op){

	case 1:
                clrscr();
		insertar(n);
        getch();
	break;


	case 2:
                clrscr();
		imprimir();
        getch();
	break;

	case 3:
		clrscr();
		eliminar();
        getch();
	break;          

	default:
		cout<<"OPCION INVALIDA";
        getch();
	break;
}
	}while(op!=3);
        
}


void insertar (int n){
	
	nodo *nuevo;
	cout<<" ingrses dato:";
        cin>>n;
	nuevo=new nodo();
        nuevo->dato=n;
	nuevo->next=cab;
	cab=nuevo;
        
}

void imprimir(){
	nodo *aux=cab;

        	while(aux!=NULL){

		cout<<aux->dato<<endl;
		aux=aux->next;
                
		}

void eliminar(){
       nodo aux=p,*m nodo=aux;
       int op=1;

	if(p->n=n){
		p=p->next;
	else{
		while((aux!=NULL)&&(op==1)){
			aux=aux->next;

		if(aux->==n)
			m nodo->next=aux->next;op=0;
		}
		else{
			m nodo=aux;
                }
}

}