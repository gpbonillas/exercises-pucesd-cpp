#include<iostream.h>
#include<stdio.h>
#include<conio.h>

class nodo{
public:
int dato;
nodo *next;
};

nodo *cab=NULL;
nodo *cola=NULL;

void ingreso(int n);
void imprimir_pila();
void imprimir_cola();
void desapilar();
void eliminar(int n);

void main()
{
  int n;
  char o, opc;
  do
  {
    clrscr();
    gotoxy(15,1);cout<<"MENU";
    gotoxy(1,3);cout<<"Opc 1. Ingresar lista circular.";
    gotoxy(1,4);cout<<"Opc 2. Imprimir PILA.";
    gotoxy(1,5);cout<<"Opc 3. Imprimir COLA. ";
    gotoxy(1,6);cout<<"Opc 4. Desapilar. ";
    gotoxy(1,7);cout<<"Opc 5. Eliminar numero. ";
    gotoxy(1,8);cout<<"Opc 6. Salir. ";
    gotoxy(1,10);cout<<"Ingrese una opcion(1-6): ";opc=getche();

    switch()
    {
      case '1':
	do
        {
	  clrscr();
          imprimir_pila();
	  gotoxy(1,1);cout<<"Ingrese numero: ";cin>>n;
	  ingreso(n);
	  imprimir_pila();
	  gotoxy(1,1);cout<<"¿DESEA VOLVER A INGRESAR(S/N)?: ";cin>>o;
	}while(o==83||o==115);
      break;

      case '2':
	clrscr();
	imprimir_pila();
	getch();
      break;

      case '3':
	clrscr();
	imprimir_cola();
	getch();
      break;

      case '4':
	do
	{
	  clrscr();
	  desapilar();
	  gotoxy(1,1);cout<<"SE DESAPILO EXITOSAMENTE.";
	  gotoxy(1,2);cout<<"DESEA DESAPILAR NUEVAMENTE(S/N)?:";cin>>o;
	}while(o==83||o==115);
      break;

      case '5':
	do
	{
	  clrscr();
	  imprimir_pila();
          gotoxy(1,1);cout<<"Ingrese numero a eliminar: ";cin>>n;
	  eliminar(n);
	  imprimir_pila();
	  gotoxy(1,1);cout<<"¿DESEA VOLVER A ELIMINAR(S/N)?: ";cin>>o;
	}while(o==83||o==115);
      break;

      case '6':
	clrscr();
	gotoxy(15,5);cout<<"FIN DEL PROGRAMA";
      break;

    }
  }while(opc!='6');
}



















          















      


































