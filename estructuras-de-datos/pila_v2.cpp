#include<iostream.h>
#include<stdio.h>
#include<conio.h>
class nodo{
public:
int dato;
nodo *next;};
void apilar ();
void imprimir ();
void desapilar();
int base();
int tope();
void eliminar();
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
cout<<"Opc 7. Salir \n:";
cout<<"\nOPCION(1-7): ";cin>>op;
switch(op){
case 1:
  apilar();
break;
case 2:
  imprimir();
break;
case 3:
  desapilar();
break;
case 4:
  clrscr();
  cout << tope();
  getche();
break;
case 5:
  clrscr();
  cout << base();
  getche();
break;
case 6:
  clrscr();
  eliminar();
  getche();
break;
case 7:
  clrscr();
  gotoxy(30,3);cout<<"FIN DEL PROGRAMA";
}
}while(op!=7);}


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
getch();
}


void desapilar(){
char op2;
do{
  clrscr();
if(cab!=NULL){
  cab=cab->next;
}else{
  cout<<"PILA VACIA";}
  gotoxy(1,5);cout<<"Desea desapilar nuevamente: ";cin>>op2;
}while(op2==83||op2==115);
}

int tope(){
if(cab!=NULL)
  return cab->dato;
}


int base(){
nodo *aux=cab;
if(aux==NULL){
	clrscr();
	cout<<" \n   LA PILA ESTA VACIA ";
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
char op3;
int n2;
if(aux==NULL)
{cout<<"\tPILA VACIA, NO SE PUEDE ELIMINAR";}
else
{
do{
	clrscr();
	cout<<"Ingrese numero a eliminar: ";cin>>n2;

while(aux!=NULL)
{
if((aux->dato)==n2)
  {
	temp1=aux->next;
	aux=temp3;
	aux->next=temp1;//OJO REVISAR LINEA
  }
	temp3=aux;
	aux=aux->next;
}//FIN DEL WHILE
	gotoxy(1,5);cout<<"Desea eliminar otro numero: ";cin>>op3;
}while(op3==83||op3==115);

}//FIN DEL ELSE
}//FIN DE LA FUNCION
