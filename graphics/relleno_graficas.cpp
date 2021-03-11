#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
void inig();
int main(void)
{
int angulo, radio = 150, cx, cy, angInicial = 0;
inig();
cx = getmaxx()/2;
cy = getmaxy()/2;
setlinestyle(0,1,3);
//pieslice
setcolor(9);
outtextxy(cx, cy-200, "pieslice...");
for(angulo=0; angulo<=360; angulo++)
{
pieslice( cx, cy , angInicial, angulo, radio );
delay(15);
}
outtextxy(cx, cy+200, "Presiona una tecla...");
getch();
cleardevice();
//fillellipse
setcolor(11);
outtextxy(cx, cy-200, "fillellipse...");
fillellipse( cx, cy , radio+150, radio );
outtextxy(cx, cy+200, "Presiona una tecla...");
getch();
cleardevice();
//sector
setcolor(14);
outtextxy(cx, cy-200, "sector...");
for( angulo=0; angulo <= 360; angulo++)
{

sector( cx, cy , angInicial, angulo, radio+150, radio );
delay(15);
}
outtextxy(cx, cy+200, "Presiona una tecla...");
getch();
cleardevice();
closegraph();
return 0;
}
void inig(){ //funcion para iniciar el modo grafico
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver, &gmode, "..\\BGI");
errorcode = graphresult();
if (errorcode != grOk)
{
printf("Error grafico: %s\n", grapherrormsg(errorcode));
printf("Presiona alguna tecla para finalizar:");
getch();
exit(1);
}
}