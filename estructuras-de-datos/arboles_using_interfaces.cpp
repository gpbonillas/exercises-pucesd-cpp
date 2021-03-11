#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<graphics.h>

#include "interface.h"
#include "arbol.h"

void main(void){
     int gdriver = DETECT, gmode;
     int elemento, valor, opcion, i;
     char *dato;
     NODOARBOL *raiz=NULL;
     clrscr();

for(;;){
     nuevo:
     valor=0;
     opcion=menu();
     if((opcion>=8 && opcion<=16) && raiz==NULL){
     window(52,8,80,12);
     textattr(YELLOW + BLINK);
     textbackground(BLACK);
     cprintf("\n\r n\r No hay nodos \n\r en el  rbol  ");
     window(1,1,80,25);
     getch(); continue;
     }

     switch(opcion){
	 case 6:
	    clrscr();
	    printf("\nIngrese elemento a insertar [0 : 99]: "); gets(dato);
	    for(i=0;i<strlen(dato);i++)
	    if(!isdigit(dato[i])){ printf("\nDato inv lido"); getch(); goto nuevo;}
	    elemento=atoi(dato);
	    if(elemento<0 || elemento>99){
	    printf("\nDato desbordado"); getch(); break;}
	    insertar(&raiz, elemento);
	    break;

	 case 8:
	    clrscr();
	    printf("\nIngrese elemento a eliminar [0 : 99]: "); gets(dato);
	    for(i=0;i<strlen(dato);i++)
	    if(!isdigit(dato[i])){ printf("\nDato inv lido"); getch(); goto nuevo;}
	    elemento=atoi(dato);
	    if(elemento<0 || elemento>99){
	    printf("\nDato desbordado"); getch(); break;}
	    buscar(raiz, elemento, &valor);
	    if(valor==1){ raiz=eliminar( raiz, elemento);
			  printf("\nNodo eliminado\n"); getch(); }
	    break;

	 case 10:
	     clrscr();
	     printf("El  rbol inorder es: "); inorder(raiz);
	     getch();
	     break;

	 case 12:
	     clrscr();
	     printf("El  rbol preorder es: "); preorder(raiz);
	     getch();
	     break;

	 case 14:
	     clrscr();
	     printf("El  rbol postorder es: "); postorder(raiz);
	     getch();
	     break;

	 case 16:
	     clrscr();
	     initgraph(&gdriver, &gmode, "");
	     dibujar(raiz, 15, 3, 7, 0);
	     getch();
	     cleardevice();
	     closegraph();
	     break;
	 case 18: exit(0);
	     }
	 }
}
