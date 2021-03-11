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
 nodo *nuevo;
 nuevo= new nodo();
 nuevo->dato=n;
 nuevo->next=cab;
 cab=nuevo;
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
 nodo *aux1,*aux2;
 int x=0,a=0,i;
 aux1=aux2=cab;
 while((aux1!=NULL)&&(x==0))
  {
   if((aux1->dato)==n)
     {x++;}
   aux1=aux1->next;
   a++;
  }
 a--;
 if(x!=0){
 for(i=1;i<a;i++)
    {aux2=aux2->next;}

 (aux2->next)=aux1;
 cout<<"El valor fue eliminado..!!";
 }
 else
  cout<<"No se encontro el valor";
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

