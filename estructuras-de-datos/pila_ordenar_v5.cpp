#include<conio.h>
#include<iostream.h>
int n;

class nodo
{
public:
 int dato;
nodo *next;
};
nodo *cab=NULL;


void pilar(int n)
{
 nodo *nuevo= new nodo(),*aux=cab,*aux1;
 int x=0;
 nuevo->dato=n;
 nuevo->next=NULL;
 if(cab==NULL)
  {cab=nuevo;}
 else{
  while((aux!=NULL)&&(!x))
  {
   if(n>aux->dato)
    {if (aux==cab)
	{nuevo->next=cab;
	 cab=nuevo;}
     else{
	 aux1->next=nuevo;
	 nuevo->next=aux;}
	x++;  
    }
    else if(n==aux->dato)
    {x++;}
   aux1=aux;
   aux=aux->next;
  }
 if(!x)
  {aux1->next=nuevo;}
}
}

void imprimir()
{
 nodo *aux;
 aux=cab;
 while(aux!=NULL)
  {
   cout<<aux->dato<<endl;
   aux=aux->next;
  }
 }


void buscar(int n)
{
 nodo *aux;int x=0;
 aux=cab;
 while(aux!=NULL)
  {
   if((aux->dato)==n)
   {x++;}
   aux=aux->next;
  }
 if(x!=0)
   cout<<"El valor existe..!!";
 else
   cout<<"El valor no existe..!!";
 }

void eliminar (int n)
{
 nodo *aux=cab,*aux1;
 int x=0;
 if(cab!=NULL){
 while((aux!=NULL)&&(!x))
      {
       if(aux->dato==n)
	 {if(aux==cab)
	     {cab=cab->next;}
	  else{aux1->next=aux->next;}
	  x++;       
	 }
       aux1=aux;
       aux=aux->next;
     }
  if(!!x)
   cout<<"valor eliminado...";
 }
 else{
 cout<<"Lista vacia...!!";}
 }
 


 void main()
{
 int op;
 do{
 clrscr();
 cout<<"\tMENU PRINCIPAL\n";
 cout<<"1.-Pilar\n";
 cout<<"2.-Imprimir\n";
 cout<<"3.-Buscar\n";
 cout<<"4.-Eliminar\n";
 cout<<"5.-Salir\n\n";
 cout<<"Ingresa tu opcion..";
 cin>>op;
 clrscr();
 switch(op){
  case 1:cout<<"Ingrese el valor";cin>>n;
	 pilar(n);break;
  case 2:cout<<"Press any key to show\n";getch();
	 imprimir();getch();break;
  case 3:cout<<"Ingrese el valor a buscar";cin>>n;
	 buscar(n);getch();break;
  case 4:cout<<"Ingrese el valor a eliminar";cin>>n;
	 eliminar(n);getch();break;
  case 5:cout<<"\n\n\n\t\tSISTEMA APAGADO";break;
  default:cout<<"\n\n\tLa opcion es incorrecta!!";
	  cout<<"\n\tPress una tacla para volver al menu..";getch();
	  break;
  }
 }while(op!=5);
}

