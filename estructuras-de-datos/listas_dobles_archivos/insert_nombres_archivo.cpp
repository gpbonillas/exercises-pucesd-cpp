#include "stdio.h"
#include "conio.h"
#include "iostream.h"
#include "string.h"

FILE *f;

class dato{
  public:
  char nombre[20];
}nodo;

void ingresar(){
 clrscr();
 cout << "Ingrese un nombre";cin >> nodo.nombre;
 fwrite(&nodo, sizeof(dato), 1, f);
}

void leer(){
clrscr();
   rewind(f);

   while (!feof(f)){
	cout << nodo.nombre <<endl;
	fread(&nodo, sizeof(dato), 1, f);

   }
   getch();
}


void main(){
   f= fopen("archivo.txt","a+");
   char ch;
   do{
     clrscr();
     cout << "1.- Ingresar...."<<endl;
     cout << "2.- Leer...."<<endl;
     cout << "3.- Salir....";
     ch = getche();
     switch(ch){
	case '1':
		ingresar();
		break;
	case '2':
		leer();
		break;
     }

   }while (ch!='3');


   fclose(f);
}