#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


int main(void)
{
   /* Variables para iniciar modo grafico */
	int gdriver = DETECT, gmode, errorphp;

   /* Inicializa modo grafico */
	initgraph(&gdriver, &gmode, "C:\\BC45\\BGI");

	/* Lee resultado de inicializacion */
   errorphp = graphresult();

   if (errorphp != grOk)  /* Si hubo un error */
   {
      printf("Ocurrio un error: %s\n", grapherrormsg(errorphp));
      printf("Presione una tecla para salir:");
      getch();
      exit(1);             /* Sale del programa */
   }


   /* Limpia pantalla */
   cleardevice();

   /* Fija color de fondo */
   setbkcolor(BLACK);

   /* Fija color de texto */
   setcolor(WHITE);

   /* Muestra mensaje a partir en coordenada: 40, 20 */
   outtextxy(40, 20, "Hola desde modo grafico");

   /* Dibuja linea */
   line(0, 0, getmaxx(), getmaxy());
   
   /* Espera a que se presione una tecla */
   getch();

   /* Cierra modo grafico */
   closegraph();

   return 0;
}