#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#define PIXELES 2000 //Cuantos pixeles apareceran en pantalla
#define DELAY 2000 // en milisegundos */
void inig();
int main(void)
{
int i, x, y, color, maxx, maxy, maxcolor;
inig();
maxx = getmaxx() + 1; //A estos 3 se les suma 1, por el random(n);
maxy = getmaxy() + 1; //...que devuelve un numero entre 0 y n-1
maxcolor = getmaxcolor() + 1;

while (!kbhit())
{
for (i=0; i<PIXELES; i++)
{
x = random(maxx);
y = random(maxy);
color = random(maxcolor);
putpixel(x, y, color);
}
delay(DELAY);
cleardevice();
}
closegraph();
return 0;
}
void inig(){ //funcion para iniciar el modo grafico
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver, &gmode, "C:\\BC45\\BGI");
errorcode = graphresult();
if (errorcode != grOk)
{
printf("Error grafico: %s\n", grapherrormsg(errorcode));
printf("Presiona alguna tecla para finalizar:");
getch();
exit(1);
}
}
