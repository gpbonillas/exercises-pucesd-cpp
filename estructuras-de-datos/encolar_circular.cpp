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
nodo *cola=NULL;




void colar(int n)
{
 nodo *nuevo;
 nuevo= new nodo();
 nuevo->dato=n;
 if(cab==NULL)
   {cab=nuevo;}
 else
   {cola->next=nuevo;}
 cola=nuevo;
 cola->next=cab;
}

void imprimir()
{
 nodo *aux=cab;
 if (cab==NULL)
    cout<<"Lista vacia";
 else{
do
  {
   cout<<aux->dato<<endl;
   aux=aux->next;
  }while(aux!=cab);
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
 if(!x)
   cout<<"El valor no existe..!!";
 else
   cout<<"El valor si existe..!!";
 }






void eliminar(int n)
{
nodo *aux,*aux1;
int x=0;
aux=cab;
if (aux==NULL)
   {cout<<"No hay valores para eliminar..!!";}
else if ((aux->dato)==n)
     {cab=aux->next;
     cout<<"El valor fue eliminado..!!";}
else{
     
     while((aux->next!=NULL)&&(x==0))
      {
       aux1=aux;
       aux=aux->next;
       if ((aux->dato)==n)
	  {aux1->next=aux->next;
	   x=1;}
      }
      if (!x)
	 {cout<<"El valor no existe en la lista..!!";}
      else
	 {cout<<"El valor fue eliminado..!!";}
    }
}



void desacolar()
{
 nodo *aux=cab;
 if(aux==NULL)
    cout<<"No hay datos para eliminar";
 else{
    cab=aux->next;
    if (cab==NULL)
	cola=NULL;
    }
    }



void main()
{
 int op;
 do{
 clrscr();
 cout<<"\tMENU PRINCIPAL\n";
 cout<<"1.-Colar\n";
 cout<<"2.-Imprimir\n";
 cout<<"3.-Buscar\n";
 cout<<"4.-Eliminar\n";
 cout<<"5.-Desacolar\n";
 cout<<"6.-Salir\n\n";
 cout<<"Ingresa tu opcion..";
 cin>>op;
 clrscr();
 switch(op){
  case 1:cout<<"Ingrese el valor";cin>>n;
	 colar(n);break;
  case 2:cout<<"Press any key to show\n";getch();
	 imprimir();getch();break;
  case 3:cout<<"Ingrese el valor a buscar";cin>>n;
	 buscar(n);getch();break;
  case 4:cout<<"Ingrese el valor a eliminar";cin>>n;
	imprimir();getch();break;
  case 5:cout<<"Press una tecla para desacolar\n";getch();
	 desacolar();break;
  case 6:cout<<"\n\n\n\t\tSISTEMA APAGADO";break;
  default:cout<<"\n\n\tLa opcion es incorrecta!!";
	  cout<<"\n\tPress una tacla para volver al menu..";getch();
	  break;
  }
 }while(op!=6);
}

