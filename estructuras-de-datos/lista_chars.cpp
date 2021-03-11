#include<iostream.h>
#include<conio.h>
#include<stdio.h>

class listaf{
public:
char dato;
listaf *next;
}carg;

void cargar();
void ingresar();
void imprimir();
void eliminar();
void guardar();

listaf *cab=NULL;
FILE *f;
void main()
{
  int o;
  f=fopen("lista.txt","at+");
  cargar();
  do
  {
    clrscr();
    gotoxy(5,1);printf("MENU");
    gotoxy(1,3);printf("Opc 1. Insertar. ");
    gotoxy(1,4);printf("Opc 2. Imprimir. ");
    gotoxy(1,5);printf("Opc 3. Eliminar. ");
    gotoxy(1,6);printf("Opc 4. Salir. ");
    gotoxy(1,8);printf("INGRESE OPCION (1/4): ");o=getche();
    switch(o)
    {
      case '1':
	ingresar();
      break;

      case '2':
	imprimir();
	getch();
      break;

      case '3':
	eliminar();
      break;

      case '4':
	clrscr();
	gotoxy(30,5);printf("FIN DEL PROGRAMA");
	guardar();
	fclose(f);
      break;
    }
  }while(o!='4');
}

void cargar()
{
  char c;
  listaf *nuevo;
  fscanf(f,"%c",&c);
  while(feof(f)==0)
  {
    nuevo= new listaf();
    nuevo->dato=c;
    nuevo->next=cab;
    cab=nuevo;
    fscanf(f,"%c",&c);
  }
}

void ingresar()
{
  char n;
  listaf *nuevo;
  char opc;
  do
  {
    clrscr();
    nuevo=new listaf();
    gotoxy(1,1);printf("Ingrese numero: ");cin>>n;
    nuevo->dato=n;
    nuevo->next=cab;
    cab=nuevo;
    gotoxy(1,5);printf("¿DESEA VOLVER A INGRESAR?(S/N): ");cin>>opc;
  }while(opc==83||opc==115);
}

void imprimir()
{
  int y;
  listaf *aux=cab;
  clrscr();
  y=3;
  gotoxy(5,1);printf("LISTA DE ENTEROS");
  while(aux!=NULL)
  {
    gotoxy(3,y);printf("%c",aux->dato);
    aux=aux->next;
    y++;
  }
}

void eliminar()
{
  listaf *aux=cab, *temp1;
  char num;
  char o1;
  do
  {
    clrscr();
    gotoxy(1,1);printf("¿Que numero desea eliminar?: ");cin>>num;
    if(cab->dato==num)
      cab=cab->next;
    else
    {
      temp1=cab;
      while(aux!=NULL)
      {
        if(aux->dato==num)
	  temp1->next=aux->next;
	temp1=aux;
        aux=aux->next;
      }
    }
      gotoxy(1,5);printf("¿DESEA VOLVER A INGRESAR? : ");cin>>o1;
  }while(o1==83||o1==115);
}

void guardar()
{
  f=fopen("lista.txt","w");
  char c1;
  listaf *aux=cab;
  //int n;
  //rewind(f);
  //fseek(f,0,SEEK_SET);
  while(aux!=NULL)
  {
    c1=aux->dato;
    fprintf(f,"%c",c1);
    aux=aux->next;
  }
}

 



    



      
























































