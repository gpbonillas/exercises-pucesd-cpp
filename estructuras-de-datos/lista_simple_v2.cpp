#include<iostream.h>
#include<conio.h>
//nodo//
class nodo{
public:
int n;
nodo *next;};
nodo *cabeza=NULL;
nodo *first=NULL;

//guardar la lista (simple)//
void enlistar(int aux){
nodo *ele;
if(cabeza==NULL){
ele= new nodo();
ele->n=aux;
cabeza=ele;
first=ele; }
else {
ele= new nodo();
ele->n=aux;
ele->next=cabeza;
cabeza=ele;
}
first->next=cabeza;
}

//imprimir la lista//
void listar1(){
nodo *aux;
aux=cabeza;

while(aux!=first){
cout<<aux->n<<"\n";
aux=aux->next;}
//caso nulo
if(cabeza==NULL && first==NULL){
cout<<"Su actual lista circular no tiene elementos";}
else
cout<<first->n;
}

//imprimir la lista N VECES//
void listarn(int nom){
nodo *aux;
aux=cabeza;
//caso no nulo
int cont=0;
while(cont!=nom){
if(aux==first)cont++;
cout<<aux->n<<"\n";
if(cabeza==NULL && first==NULL){
cout<<"Su actual lista circular no tiene elementos";}
else
aux=aux->next;
}}

//conteo// no utilizado por el momento
int conteo(){
nodo *aux;int cant=0;
aux=cabeza;
while(aux!=NULL){
aux=aux->next;
cant++;}
return cant;}

//borrar/////////////////
void borrar(int num){
nodo *aux,*ult=NULL;

aux=cabeza;
	//caso 1 solo elemento
	if(cabeza==first){
	cabeza=NULL;
	first=NULL;
	}
	//condicion de busqueda
	while(aux->n!=num && aux!=first){
	ult=aux;
	aux=aux->next;
	}
	if(aux->n!=num && aux==first){
	cout<<"El numero ingresado no ha sido encontrado:";
	getch();
	goto fin;
	}
	//caso primer ingresado
	if(aux==first){
	ult->next=cabeza;
	first=ult;
	goto fin;
	}
	//caso ultimo ingresado
	if(ult==NULL){
	cabeza=cabeza->next;
	first->next=cabeza;
	goto fin;
	}
//caso valor medio
*(ult)->next=*((ult->next)->next);
fin:
}

/*
//borrar n numeros//NO UTILIZADO EN EL PROGRAMA
void borrarn(int num){
nodo *aux,*ult=NULL;
repetir:

aux=cabeza;
	while(aux->n!=num && aux!=first){
	ult=aux;
	aux=aux->next;
	}
	//caso primer ingresado
	if(aux==first){
	ult->next=cabeza;
	first=ult;
	goto fin;}
	//caso ultimo ingresado
	if(ult==NULL){
	cabeza=cabeza->next;
	first->next=cabeza;
	goto fin;}
//caso valor medio
*(ult)->next=*((ult->next)->next);
while(aux->n!=NULL){aux=aux->next;}
goto repetir;
fin:
}
*/

//cuerpo//
void main()
{
menu:


clrscr();
cout<<"\t\t***MENU PARA LA CREACION DE LISTAS***\n\n";
cout<<"1. Enlistar\n";
cout<<"2. Listar\n";
cout<<"3. Listar n ciclos\n";
cout<<"4. Borrar numero\n";
//cout<<"5. Borrar numeros (n)\n";
cout<<"5. Salir\n";
int x,n,nom;
cin>>x;
switch(x)
{
	case 1:
{clrscr();
cin>>n;
enlistar(n);
goto menu;
}
	case 2:
{
clrscr();
listar1();
getch();
goto menu;
}

	case 3:
{
clrscr();
cout<<"Ingrese el numero de ciclos que quiere observar:\n";
cin>>nom;cout<<"\n\n";
listarn(nom);
getch();
goto menu;
}


	case 4:
{
clrscr();
int num;
cin>>num;
borrar(num);
goto menu;
}
/*	case 5:
{
clrscr();
int num;
cin>>num;
borrarn(num);
goto menu;
}*/
	case 5:
goto salir;
	default:
goto menu;
}
salir:
}