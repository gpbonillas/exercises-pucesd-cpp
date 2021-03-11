#include<iostream.h>
#include<conio.h>
//nodo//
class nodo{
public:
int n;
nodo *next;};
nodo *cabeza=NULL;

//guardar la lista
void guardar(int m){
nodo *aux;
aux= new nodo();
aux->next=cabeza;
cabeza=aux;
if(cabeza!=NULL){
while( ((aux->next)->n) < m && aux->next!=NULL ){
(aux)->n=(aux->next)->n;
aux=aux->next;}
aux->n=m;
}
else{
aux->n=m;
}}

//imprimir la lista//
void listar(){
nodo *aux;
aux=cabeza;
while(aux!=NULL){
cout<<aux->n<<"\n";
aux=aux->next;}
}

//conteo
int conteo(){
nodo *aux;int cant=0;
aux=cabeza;
while(aux!=NULL){
aux=aux->next;
cant++;}
return cant;}

//borrar
void borrar(int num){
nodo *aux,*ult=NULL;
aux=cabeza;
	while(aux->n!=num&&aux!=NULL){
	ult=aux;
	aux=aux->next;
	}
	if(aux==NULL)goto fin;

	if(ult==NULL)
	cabeza=cabeza->next;
	else
	if(aux->next==NULL)
	ult->next=NULL;
*(ult)->next=*((ult->next)->next);
fin:
}

//borrar
void borrarn(int num){
nodo *aux,*ult=NULL;
repetir:
aux=cabeza;
	while(aux->n!=num&&aux!=NULL){
	ult=aux;
	aux=aux->next;
	}

	if(aux==NULL)goto fin;

	if(ult==NULL)
	cabeza=cabeza->next;
	else
	if(aux->next==NULL)
	ult->next=NULL;
*(ult)->next=*((ult->next)->next);

while(aux->n!=NULL){aux=aux->next;}
goto repetir;
fin:
}

//cuerpo//
void main()
{
menu:
clrscr();
cout<<"\t\t***MENU PARA LA CREACION DE LISTAS***\n\n";
cout<<"1. Enlistar\n";
cout<<"2. Listar\n";
cout<<"3. Borrar numero\n";
cout<<"4. Borrar numeros (n)\n";
cout<<"5. Salir\n";
int x,n;
cin>>x;
switch(x)
{
	case 1:
{clrscr();
cin>>n;
guardar(n);
goto menu;
}
	case 2:
{
clrscr();
listar();
getch();
goto menu;
}
	case 3:
{
clrscr();
int num;
cin>>num;
borrar(num);
goto menu;
}
	case 4:
{
clrscr();
int num;
cin>>num;
borrarn(num);
goto menu;
}
	case 5:
goto salir;
	default:
goto menu;
}
getch();
salir:
}