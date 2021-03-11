#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

class listaf{
public:
char nombre[10];
char celular[10];
listaf *next;
};

void cargar();
void ingresar();
void imprimir();
void eliminar();
void guardar();

listaf *cab=NULL, buffer;
FILE *f;
void main()
{
  int o;
  f=fopen("contactos.txt","a+");
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
  listaf *nuevo;
  fread(&buffer,sizeof(listaf),1,f);
  while(feof(f)==0)
  {
    nuevo= new listaf();
    strcpy(nuevo->nombre,buffer.nombre);
    strcpy(nuevo->celular,buffer.celular);
    nuevo->next=cab;
    cab=nuevo;
    fread(&buffer,sizeof(listaf),1,f);
  }
}

void ingresar()
{
  listaf *nuevo;
  char opc;
  do
  {
    clrscr();
    nuevo=new listaf();
    gotoxy(1,1);printf("Ingrese nombre: ");gets(buffer.nombre);
    gotoxy(1,3);printf("Ingrese celular de %s : ",buffer.nombre);gets(buffer.celular);
    strcpy(nuevo->nombre,buffer.nombre);
    strcpy(nuevo->celular,buffer.celular);
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
  y=5;
  gotoxy(15,1);printf("CONTACTOS.");
  gotoxy(5,3);printf("NOMBRES\t\tCELULAR");
  while(aux!=NULL)
  {
    gotoxy(5,y);printf("%s\t\t%s",aux->nombre,aux->celular);
    aux=aux->next;
    y++;
  }
}

void eliminar()
{
  listaf *aux, *temp1;
  char o1, cad[15];
  do
  {
    clrscr();
    aux=cab;
    gotoxy(1,1);printf("¿Ingrese nombre a eliminar?: ");gets(cad);
    if(strcmp(cad,cab->nombre)==0)
      cab=cab->next;
    else
    {
      temp1=cab;
      while(aux!=NULL)
      {
	if(strcmp(cad,aux->nombre)==0)
	  temp1->next=aux->next;
	temp1=aux;
        aux=aux->next;
      }
    }
      gotoxy(1,5);printf("¿DESEA ELIMINAR NUEVAMENTE(S/N)? : ");cin>>o1;
  }while(o1==83||o1==115);
}

void guardar()
{
  f=fopen("contactos.txt","w");
  listaf *aux=cab;
  while(aux!=NULL)
  {
    strcpy(buffer.nombre,aux->nombre);
    strcpy(buffer.celular,aux->celular);
    fwrite(&buffer,sizeof(listaf),1,f);
    aux=aux->next;
  }
}