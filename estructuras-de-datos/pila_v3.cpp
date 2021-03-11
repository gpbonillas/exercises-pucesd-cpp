#include<iostream.h>
#include<conio.h>
#include <string.h>

class nodo {
 public:
 int dato;
 nodo *next;
 };
 nodo *cab= NULL;

 void apilar (){
 int n;
 char o;
 do{
 clrscr();
 cout<<" ingrese numero "; cin>>n;

 nodo *aux;

 aux= new nodo ();
 aux -> dato= n;
 aux -> next =cab;
 cab=aux;
  cout<<"\n desea ingresar otro elemento (s/n)"; cin>>o;
	}while(o=='s'|| o=='S');
  getch();
 }

 void imprimir (){
  nodo *aux= cab;
  
if(aux==NULL){
	cout<<"\n \t no a ingresado datos ";
  }
  while( aux!= NULL){
	cout<<endl<<aux -> dato;
	aux= aux -> next;
	}
	getch();
  }


 void main (){
  int n,op;
 
 do{
  clrscr();
  cout<<"\t\t\t menu de pilas \n";
  cout<<"1. ingresar \n";
  cout<<"2. imprimir \n";
  cout<<"3. salir \n";
  cout<<" ingrese opcion: "; cin>> op;
  int o;
  
switch(op){
	case 1:
  clrscr();

	 apilar ();
  break;
  case 2:
  clrscr();
  cout<<" \n LA PILA INGRESADA ES: \n";
  imprimir ();
  break;

  case 3:
  clrscr();
  cout<<"\n\t\n\t\t FIN ";
	break;

  default:
  cout<<"\n opcion incorrecta ";
  getch();
  break;
  }
  }while(op!=3);
  }
