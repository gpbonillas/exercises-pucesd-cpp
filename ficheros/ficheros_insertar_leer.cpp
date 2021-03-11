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
    cout<<"ELIJA UNA OPCION(1/3): ";cin>>opcion;

    switch(opcion)
    {
      case 1:
	insertar(archivo);
        getch();
      break;

      case 2:
        leer(archivo);
        getch();
      break;

      case 3:
        clrscr();
        gotoxy(32,5);cout<<"FIN DEL PROGRAMA";
      break;
    }
  }while(opcion!=3);
}

void insertar(FILE *archivo)
{
  char car, op1;
  archivo=fopen("fich1.cpp","w");
  do
  {
    clrscr();
    cout<<"Ingrese un caracter: ";cin>>car;
    fputc(car,archivo);
    cout<<"\n\n\n¿DESEA INGRESAR NUEVAMENTE?(S/N): ";cin>>op1;
  }while(op1==83||op1==115);

  fclose(archivo);
}

void leer(FILE *archivo)
{
  char car;
  archivo=fopen("fich1.cpp","r");
  clrscr();
  if(archivo==NULL)
    cout<<"EL ARCHIVO NO EXISTE, CREELO";
  else
  {
    cout<<"LOS DATOS SON: \n\n\n";
    while(feof(archivo)==0)
    {
      car=fgetc(archivo);
      cout<<car<<"\n";
    }
  }
  fclose(archivo);
}










































