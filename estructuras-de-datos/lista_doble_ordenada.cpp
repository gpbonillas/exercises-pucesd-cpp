#include<iostream.h>
#include<conio.h>
class nodo
{
 public:
 int dato;
 nodo *next;
 nodo *prev;
};
nodo *cab=NULL;
nodo *cola=NULL;
int n;

void enlistar(int n)
{
 nodo *nuevo=new nodo();
 nodo *aux=cab,*aux1;
 nuevo->dato=n;
 nuevo->next=NULL;
 nuevo->prev=NULL;
 int x=0;
 if (cab==NULL)
 {cab=nuevo;
  cola=nuevo;}
  else{do{
	 if(n<aux->dato)
	 {if(aux==cab)
	     {nuevo->next=cab;
	      cab->prev=nuevo;
	      cab=nuevo;}
	  else{aux1->next=nuevo;
	       nuevo->prev=aux1;
	       nuevo->next=aux;
	       aux->prev=nuevo;}
	  x++;
	  }else if(n==aux->dato)
	   {x++;break;}
	  aux1=aux;
	  aux=aux->next;
	 }while((aux!=cab)&&(!x));
	if(!x)
	 {cola->next=nuevo;
	 nuevo->prev=cola;
	 cola=nuevo;}
    }
 cab->prev=cola;
 cola->next=cab;
 }
             



void imprimir()
{if(cab!=NULL){
 nodo *aux=cab,*aux2=cola;
 cout<<"\n\n x la cabeza  x la cola\n";
do
  {
   cout<<"\t"<<aux->dato<<"\t"<<aux2->dato<<endl;
   aux=aux->next;
   aux2=aux2->prev;
  }while(aux!=cab);
 }else
 cout<<"lista vacia..!!";
 }



void eliminar(int n)
{
 nodo *aux=cab,*aux1,*aux2;
 int x=0;
 if (aux==NULL)
 {cout<<"LISTA VACIA:::";}
 else if (aux->dato==n)
 {x++;
  if(aux==cola)
  {cab=cola=NULL;}
  else
  {cab=cab->next;}
  }
  else{
       aux1=aux;
       aux=aux->next;
       aux2=aux->next;
       do{
	  if(n==aux->dato)
	    {
	     if(aux==cola)
	     {cola=aux1;}
	     else{
	      aux1->next=aux2;
	      aux2->prev=aux1;}
	      x++;
	     }
	    aux1=aux;
            aux=aux->next;
	    aux2=aux->next;
	  }while((aux!=cab)&&(!x));
       }
  if(cab!=NULL)
   {cab->prev=cola;
   cola->next=cab;}
  if(!x)
  cout<<"valor no encontrado";
  else
  cout<<"Eliminado!!";
 }






void main()
{
 int op;
 do{
 clrscr();
 cout<<"\tMENU PRINCIPAL\n";
 cout<<"1.-Enlistar\n";
 cout<<"2.-Imprimir( cabeza y cola)\n";
  cout<<"3.-Eliminar\n";
 cout<<"4.-Salir\n\n";
 cout<<"Ingresa tu opcion..";
 cin>>op;
 clrscr();
 switch(op){
  case 1:cout<<"Ingrese el valor";cin>>n;
	 enlistar(n);break;
  case 2:cout<<"Press any key to show\n";getch();
	 imprimir();getch();break;
  case 3:cout<<"Ingrese el valor a eliminar\n";
	 cin>>n;eliminar(n);getch();
	 break;
  case 4:cout<<"\n\n\n\t\tSISTEMA APAGADO";break;
  default:cout<<"\n\n\tLa opcion es incorrecta!!";
	  cout<<"\n\tPress una tacla para volver al menu..";getch();
	  break;
  }
 }while(op!=4);
}