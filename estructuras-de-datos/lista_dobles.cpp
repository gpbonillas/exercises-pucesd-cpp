#include<conio.h>
#include<iostream.h>
int n;
int m;

class nodo
{
public:
 int dato;
 nodo *next;
 nodo *prev;
};
nodo *cab=NULL;
nodo *cola=NULL;




void enlistar(int n)
{
 nodo *nuevo;
 nuevo= new nodo();
 nuevo->dato=n;
 nuevo->next=NULL;
 nuevo->prev=NULL;

 if(cab==NULL)
   {cab=nuevo;}
 else
   {nuevo->prev=cola;
    cola->next=nuevo;}
 cola=nuevo;
}

void imprimir()
{if(cab!=NULL){
 nodo *aux=cab,*aux2=cola;
 cout<<"\n\n x la cabeza  x la cola\n";
while((aux!=NULL)&&(aux2!=NULL))
  {
   cout<<"\t"<<aux->dato<<"\t"<<aux2->dato<<endl;
   aux=aux->next;
   aux2=aux2->prev;
  }
 }else
 cout<<"lista vacia..!!";
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

void reemplazar(int n,int m)
{
 nodo *aux;int x=0;
 aux=cab;
 if(aux->dato==n)
  {aux->dato=m;
   cout<<"El valor fue reemplazado..!!";}
 else{
 while((aux!=NULL)&&(!x))
  {
   aux=aux->next;
   if(aux->dato==n)
   {x++;aux->dato=m;}
   
  }
 if(!x)
   {cout<<"El valor no existe..!!";}
 else
   {cout<<"El valor fue reemplazado..!!";}
 }

}

void eliminar(int n)
{
nodo *aux,*aux1,*aux2;
int x=0;
aux=cab;
if (aux==NULL)
   {cout<<"lista vacia..!!";}
else if ((aux->dato)==n)
     {cab=cab->next;
      cab->prev=NULL;
     cout<<"El valor fue eliminado..!!";}
else{while((aux->next!=NULL)&&(x==0))
      {
       aux1=aux;
       aux=aux->next;
       aux2=aux->next;
       if ((aux->dato)==n)
	  {x++;
	   if(aux==cola){
	      cola=aux1;
	      cola->next=NULL;}
	   else{
	      aux1->next=aux2;
	      aux2->prev=aux1;}
          }	  
      }
      if (!x)
	 {cout<<"El valor no existe en la lista..!!";}
      else
	 {cout<<"El valor fue eliminado..!!";}
    }
}



void desacolar()
{
if(cab!=NULL)
 {cola=cola->prev;
  cola->next=NULL;
  if (cola==NULL)
     {cab=NULL;}
 }
 else
 {cout<<"\nlista vacia..!!";
  getch();}
}


void desapilar()
{
if(cab!=NULL)
 {cab=cab->next;
  cab->prev=NULL;
 }
 else
 {cout<<"\nlista vacia..!!";
  getch();}
}




void main()
{
 int op;
 do{
 clrscr();
 cout<<"\tMENU PRINCIPAL\n";
 cout<<"1.-Enlistar\n";
 cout<<"2.-Imprimir( cabeza y cola)\n";
 cout<<"3.-Buscar\n";
 cout<<"4.-Eliminar valor\n";
 cout<<"5.-Reemplazar valor\n";
 cout<<"6.-Eliminar cabeza\n";
 cout<<"7.-Eliminar cola\n";
 cout<<"8.-Salir\n\n";
 cout<<"Ingresa tu opcion..";
 cin>>op;
 clrscr();
 switch(op){
  case 1:cout<<"Ingrese el valor";cin>>n;
	 enlistar(n);break;
  case 2:cout<<"Press any key to show\n";getch();
	 imprimir();getch();break;
  case 3:cout<<"Ingrese el valor a buscar";cin>>n;
	 buscar(n);getch();break;
  
  case 4:cout<<"Ingrese el valor a eliminar";cin>>n;
	 eliminar(n);getch();break;
  case 5:cout<<"Ingrese el valor a reemplazar";cin>>n;
	 cout<<"Ingrese el nuevo valor";cin>>m;
	 reemplazar(n,m);getch();break;
  case 6:cout<<"Press any key to delete";getch();
	desapilar();break;
  case 7:cout<<"Press any key to delete";getch();
	 desacolar();break;
  case 8:cout<<"\n\n\n\t\tSISTEMA APAGADO";break;
  default:cout<<"\n\n\tLa opcion es incorrecta!!";
	  cout<<"\n\tPress una tacla para volver al menu..";getch();
	  break;
  }
 }while(op!=8);
}

