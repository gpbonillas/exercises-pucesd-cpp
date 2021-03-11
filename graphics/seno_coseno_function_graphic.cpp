#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <math.h>
void inig();
int main(void)
{
int origenx = 50 ,origeny = 200, y, i;
inig();
outtextxy(50,20,"Grafica seno y coseno con putpixel, line y outtextxy.");
//se dibujan los ejes de coordenadas
setcolor(11);
setlinestyle(0,1,3);
line(origenx,origeny,origenx+360,origeny);
line(origenx,origeny-150,origenx,origeny+150);
//se rotulan los ejes coordenados, se obtiene 'y' para el coseno de 0
y = 100 * ( cos( (0*M_PI)/180 ) );
line(origenx-5, y, origenx+5, y);
line(origenx-5, origeny+y, origenx+5, origeny+y);
setcolor(10);
outtextxy(origenx-20, origeny+y, "-1");
outtextxy(origenx-20, y, "1");
outtextxy(origenx+365, origeny, "X");
outtextxy(origenx, origeny-155, "Y");
//se extienden lineas con y = +-1... para que se vea cool
setlinestyle(2,1,1);
setcolor(9);
line(origenx, y, origenx+360, y);
line(origenx, origeny+y, origenx+360, origeny+y);
//se dibujan las funciones
for (i=0; i<360; i++)
{
y = origeny - ( 100 * ( sin( (i*M_PI)/180 ) ) );
putpixel(origenx+i, y, 14);
delay(10);
}
for (i=0; i<360; i++)
{
y = origeny - ( 100 * ( cos( (i*M_PI)/180 ) ) );
putpixel(origenx+i, y, 2);
delay(10);
}
getch();
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