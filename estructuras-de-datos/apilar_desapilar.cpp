#include<iostream.h>
#include<stdio.h>
#include<conio.h>
class nodo{
public:
int dato;
nodo *next;
};
void apilar ();
void imprimir ();
void imprimir_eliminar();
void desapilar();
int base();
int tope();
void eliminar();
void insertar_elemento();
void desapilar_ultimo();
nodo *cab=NULL;
void main(){
int op;
do{
clrscr();
printf("\tMENU\n");
cout<<"Opc 1. Apilar: \n";
cout<<"Opc 2. Imprimir: \n";
cout<<"Opc 3. Desapilar: \n";
cout<<"Opc 4. Tope: \n";
cout<<"Opc 5. Base: \n";
cout<<"Opc 6. Eliminar \n";
cout<<"Opc 7. Insertar elemento: \n";
cout<<"Opc 8. Desapilar el ultimo: \n";
cout<<"Opc 9. Salir:\n ";
cout<<"\nOPCION(1-9): ";cin>>op;
switch(op){
case 1:
  apilar();
break;

case 2:
  imprimir();
  getche();
break;

case 3:
  desapilar();
  getche();
break;

case 4:
  clrscr();
  if(tope()==0)
    cout<<"LA PILA ESTA VACIA";
  else
  cout<<"El tope de la pila es: "<<tope();
  getche();
break;

case 5:
  clrscr();
  if(base()==0)
    cout<<"LA PILA ESTA VACIA";
  else
    cout <<"La base de la pila es: "<< base();
  getche();
break;

case 6:
  clrscr();
  eliminar();
  getche();
break;

case 7:
  clrscr();
  insertar_elemento();
  getche();
break;

case 8:
  clrscr();
  desapilar_ultimo();
  getche();
break;

case 9:
  clrscr();
  gotoxy(30,3);cout<<"FIN DEL PROGRAMA";
break;
}
}while(op!=9);}


void apilar(){
char op1;
int n;
do{
  clrscr();
  nodo *aux;
  aux = new nodo ();
  printf("Ingrese un numero: ");cin>>n;
  aux -> dato=n;
  aux -> next=cab;
  cab=aux;
  cout<<"\n\nDesea ingresar otro numero(s/n): ";cin>>op1;
}while((op1==83)||(op1==115));
}


void imprimir(){
clrscr();
cout<<"LA PILA ES: \n";
nodo *aux=cab;
if(aux==NULL)
{
  clrscr();
  cout<<" \n   LA PILA ESTA VACIA ";
}
while(aux!=NULL)
{
  cout<<"\n"<<aux->dato;
  aux=aux->next;
}
}


void desapilar(){
char op2;
int flag=0;
if(cab==NULL)
{ clrscr();
  cout<<"LA PILA ESTA VACIA";
}
else
{
  do{
     clrscr();
  if(cab!=NULL){
     cab=cab->next;
  }else{
     cout<<"PILA VACIA, IMPOSIBLE DESAPILAR";
     flag=1;
     op2=110;}
     if(flag==0)
     {gotoxy(1,3);cout<<"Desea desapilar nuevamente: ";cin>>op2;}
  }while(op2==83||op2==115);
}
}

int tope(){
if(cab!=NULL)
  return cab->dato;
else
  return 0;
}


int base(){
nodo *aux=cab;
if(aux==NULL){
	return 0;
}
else{
	while(aux->next!=NULL)
		aux=aux->next;
	return aux->dato;
}
}





void eliminar(){
nodo *aux=cab, *temp1, *temp3;
int flag, flag2;
char op3;
int n2;
if(aux==NULL)
	{cout<<"\tPILA VACIA, NO SE PUEDE ELIMINAR";}
else{
do{
        aux=cab;
	flag=0;
	clrscr();
	imprimir_eliminar();
	gotoxy(1,1);cout<<"Ingrese numero a eliminar: ";cin>>n2;
  if(cab->dato==n2)
	{
	cab=aux->next;
	aux=NULL;
	flag=1;
	}

  while(aux!=NULL)
  {
    if((aux->dato)==n2)
      {
	temp1=aux->next;
	aux=temp3;
	aux->next=temp1;
	flag=1;
        aux=NULL;
      }
    temp3=aux;
    aux=aux->next;

  }
  imprimir_eliminar();
  if(flag==0)
       {clrscr();
	op3=110;
        imprimir_eliminar();
	gotoxy(20,15);cout<<"NO SE ENCUENTRA EL NUMERO "<<n2<<" EN LA PILA";
        
	}
  
        gotoxy(1,1);cout<<"¿Desea eliminar otro numero?: ";cin>>op3;

 if((cab==NULL)&&(op3==83||op3==115))
   {
       clrscr();
       gotoxy(1,1);cout<<"PILA VACIA, NO SE PUEDE ELIMINAR";
       op3=110;
          
   }
 
}while(op3==83||op3==115);
}
}

void imprimir_eliminar(){
clrscr();
gotoxy(50,2);cout<<"PILA:";
int x=50, y=3;
nodo *aux=cab;
while(aux!=NULL)
	{
	 gotoxy(x,y);cout<<aux->dato;
	 aux=aux->next;
	 y++;
	}
}

void insertar_elemento(){
nodo *aux=cab, *aux1, *temp3;
int n,num;
char opc4;

if(aux==NULL)
{
      cout<<"PILA VACIA, NO SE PUEDE INSERTAR";
}
else
{
   do
   {
      clrscr(); 
      aux=cab;
      aux1= new nodo();
      cout<<"Ingrese el numero a insertar: ";cin>>num;
      imprimir_eliminar();
      gotoxy(1,1);cout<<"El numero "<<num<<" se insertara sobre..: ";cin>>n;
      temp3=aux;
      if(cab->dato==n)
      {
         aux1->dato=num;
         aux1->next=cab;
         cab=aux1;
         aux=NULL;
      }

      while(aux!=NULL)
      {
	if((aux->dato)==n)
	{
	  aux1-> dato=num;
	  aux1-> next=aux;
          aux=temp3;
          aux->next=aux1;
          aux=NULL;
        }
        temp3=aux;
        aux=aux->next;
      }
      clrscr();
      gotoxy(1,1);cout<<"¿Desea insertar otro numero?: ";cin>>opc4;

   }while(opc4==83||opc4==115);

 }
}


void desapilar_ultimo(){
nodo *aux=cab, *temp1=cab;
char op5;
if (aux==NULL)
   cout<<"LA PILA ESTA VACIA";
else
   {
    do
     {
	     clrscr();
	     aux=cab;
        imprimir_eliminar();
	if(cab->next==NULL)
	     cab=NULL;
	while(aux!=NULL)
	 {
	     if(aux->next==NULL)
	     {
                  temp1->next=NULL;
	     }
             temp1=aux;
	     aux=aux->next;
	 }
             imprimir_eliminar();
             gotoxy(1,2);cout<<"¡¡¡SE DESAPILO EL ULTIMO NODO!!!";
             gotoxy(1,5);cout<<"¿Desea desapilar nuevamente?: ";cin>>op5;

	if((cab==NULL)&&(op5==83||op5==115))
	{
          clrscr();
          cout<<"PILA VACIA, NO SE PUEDE SEGUIR";
          op5=110;
	}
     }while(op5==83||op5==115);
    }
  }

       





















       












