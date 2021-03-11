#include<iostream.h>
#include<conio.h>
#include<stdio.h>

class guiatel{
public:
char nombre[15];
char cel[12];
};

void abrir();
void cerrar();
void guardar();
void ver();

FILE *fic;
guiatel cont;

void main()
{
  int o;
  abrir();
  do
  {
    clrscr();
    gotoxy(5,1);printf("MENU");
    gotoxy(1,3);printf("Opc 1: Guardar contacto. ");
    gotoxy(1,4);printf("Opc 2: Ver contacto. ");
    gotoxy(1,5);printf("Opc 3: Salir. ");
    gotoxy(1,7);printf("ELIJA UNA OPCION(1/3): ");o=getche();

    switch(o)
    {
      case 49:
	guardar();
      break;

      case 50:
	ver();
	getch();
      break;

      case 51:
	clrscr();
	gotoxy(30,5);printf("FIN DEL PROGRAMA");
	cerrar();
      break;
    }
  }while(o!=51);
}

void abrir()
{
  fic=fopen("contactos.txt","a+");
}

void cerrar()
{
  fclose(fic);
}

void guardar()
{
  char opc;
  do
  {
    clrscr();
    gotoxy(5,1);printf("INGRESAR INFORMACION. ");
    gotoxy(1,3);printf("Ingrese nombre: ");gets(cont.nombre);
    gotoxy(1,5);printf("Ingrese celular de %s: ",cont.nombre);gets(cont.cel);
    fwrite(&cont,sizeof(guiatel),1,fic);
    gotoxy(1,8);printf("¿DESEA INGRESAR OTRO CONTACTO?(S/N): ");opc=getche();
  }while(opc==83||opc==115);
}

void ver()
{
  int y;
  clrscr();
  rewind(fic);
  y=5;
  gotoxy(15,1);printf("CONTACTOS.");
  gotoxy(5,3);printf("NOMBRES\t\tCELULAR");
  //fread(&cont,sizeof(guiatel),1,fic);
  while(feof(fic)==0)
  {
    gotoxy(5,y);printf("%s\t\t%s",cont.nombre,cont.cel);
    fread(&cont,sizeof(guiatel),1,fic);
    y++;
  }
}






































