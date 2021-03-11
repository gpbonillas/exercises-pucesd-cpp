#include<conio.h>
#include<iostream.h>
int n;

class nodo                          
{
public:
 int dato;
nodo *next;
};
nodo *cab,*aux;  //pila
nodo *cab2,*cola; //cola

void pilar(int n)
{
 nodo *nuevo;
 nuevo= new nodo();
 nuevo->dato=n;
 if(cab==NULL)
   {aux=nuevo;}
 else
   {nuevo->next=cab;}
 cab=nuevo;
 aux->next=cab;

}


void imprimir_pila()
{
 nodo *aux2=cab;
 if (aux2==NULL)
    cout<<"Lista vacia";
 else{
do
  {
   cout<<aux2->dato<<endl;
   aux2=aux2->next;
  }while(aux2!=cab);
 }
}

void eliminar_pila(int n)
{
 nodo *aux0=cab,*aux1;
 int x=0;
if(aux0==NULL) 
  {cout<<"Lista Vacia";}
else if(aux0->dato==n){
   if(aux0==aux)
     {cab=NULL;
      aux=NULL;}
   else{
   cab=cab->next;
   aux->next=cab;}
   cout<<"Valor eliminado..!!";}
else{
     do{
        aux1=aux0;
	aux0=aux0->next;
        if(aux0->dato==n)
	   {x++;
            if(aux0==aux)
	       {aux=aux1;
		aux->next=cab;}
	    else{aux1->next=aux0->next;}}
      }while((aux0!=cab)&&(!x));
      if(!x)
      cout<<"Valor no encontrado..!!";
      else
      cout<<"Valor eliminado..!!";}
}

void colar(int n)
{
 nodo *nuevo;
 nuevo= new nodo();
 nuevo->dato=n;
 if(cab2==NULL)
   {cab2=nuevo;}
 else
   {cola->next=nuevo;}
 cola=nuevo;
 cola->next=cab2;
}


void imprimir_cola()
{
 nodo *aux2=cab2;
 if (aux2==NULL)
    cout<<"Lista vacia";
 else{
do
  {
   cout<<aux2->dato<<endl;
   aux2=aux2->next;
  }while(aux2!=cab2);
 }
}

void eliminar_cola(int n)
{
 nodo *aux0=cab2,*aux1;
 int x=0;
if(aux0==NULL) 
  {cout<<"Lista Vacia";}
else if(aux0->dato==n){
   if(aux0==cola)
     {cab2=NULL;
      cola=NULL;}
   else{
   cab2=cab2->next;
   cola->next=cab2;}
   cout<<"Valor eliminado..!!";}
else{
     do{
        aux1=aux0;
	aux0=aux0->next;
        if(aux0->dato==n)
	   {x++;
            if(aux0==cola)
	       {cola=aux1;
		cola->next=cab2;}
	    else{aux1->next=aux0->next;}}
      }while((aux0!=cab2)&&(!x));
      if(!x)
      cout<<"Valor no encontrado..!!";
      else
      cout<<"Valor eliminado..!!";}
}

 void main()
{
 int op;
 do{
 clrscr();
 cout<<"\tMENU PRINCIPAL\n\n";
 cout<<"1.-Pilar\n";
 cout<<"2.-Imprimir pila\n";
 cout<<"3.-Eliminar pila\n";
 cout<<"---------------------\n";
 cout<<"4.-Colar\n";
 cout<<"5.-Imprimir cola\n";
 cout<<"6.-Eliminar cola\n";
 cout<<"---------------------\n";
 cout<<"7.-Salir\n\n";
 cout<<"Ingresa tu opcion..";
 cin>>op;
 clrscr();
 switch(op){
  case 1:cout<<"Ingrese el valor a pilar.. ";cin>>n;
	 pilar(n);break;
  case 2:cout<<"Press any key to show\n";getch();
	 imprimir_pila();getch();break;
  case 3:cout<<"Ingrese el valor a eliminar[p].. ";cin>>n;
	 eliminar_pila(n);getch();break;
  case 4:cout<<"Ingrese el valor a colar.. ";cin>>n;
	 colar(n);break;
  case 5:cout<<"Press any key to show\n";getch();
	 imprimir_cola();getch();break;
  case 6:cout<<"Ingrese el valor a eliminar[c].. ";cin>>n;
	 eliminar_cola(n);getch();break;
  case 7:cout<<"\n\n\n\t\tSISTEMA APAGADO";break;
  default:cout<<"\n\n\tLa opcion es incorrecta!!";
	  cout<<"\n\tPress una tacla para volver al menu..";getch();
	  break;
  }
 }while(op!=7);
}





