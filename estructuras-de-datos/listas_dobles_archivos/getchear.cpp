#include<iostream.h>
#include<stdio.h>
#include<conio.h>

void insertar(FILE *archivo);
void leer(FILE *archivo);

void main()
{
  int opcion;
  FILE *archivo;
  do
  {
    clrscr();
    cout<<"MENU FICHEROS\n\n";
    cout<<"Opc 1: Insertar.\n";
    cout<<"Opc 2: Leer archivo.\n";
    cout<<"Opc 3: Salir.\n\n";
    cout<<"ELIJA UNA OPCION(1/3): ";opcion=getche();

    switch(opcion)
    {
      case '1':
	insertar(archivo);
      break;

      case '2':
	leer(archivo);
        getch();
      break;

      case '3':
        clrscr();
	gotoxy(32,5);cout<<"FIN DEL PROGRAMA";
        getch();
      break;
    }
  }while(opcion!=3);
}

void insertar(FILE *archivo)
{
  int  car;
  clrscr();
  archivo=fopen("h:\\ficherod.cpp","a");
  cout<<"Ingrese un texto: ";
  do
  {
    car=getche();
    fputc(car,archivo);
  }while(car!=13);
  fclose(archivo);
}

void leer(FILE *archivo)
{
  archivo=fopen("h:\\ficherod.cpp","r");
  clrscr();
  if(archivo==NULL)
    cout<<"EL ARCHIVO NO EXISTE, CREELO";
  else
  {
    cout<<"LOS DATOS DEL ARCHIVO SON: \n\n\n";
    while(feof(archivo)==0)
    {
      printf("%c",fgetc(archivo));
    }
  }
  fclose(archivo);
}










































