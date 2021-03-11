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
//arco
setcolor(9);
outtextxy(cx, cy-200, "arc...");
for(angulo=0; angulo<=360; angulo++)
{
arc( cx, cy , angInicial, angulo, radio );
delay(15);
}
outtextxy(cx, cy+200, "Presiona una tecla...");
getch();
cleardevice();
//circulo
setcolor(11);
outtextxy(cx, cy-200, "circle...");
circle(cx, cy, radio);

outtextxy(cx, cy+200, "Presiona una tecla...");
getch();
cleardevice();
//elipse
setcolor(14);
outtextxy(cx, cy-200, "ellipse...");
for( angulo=0; angulo <= 360; angulo++)
{
ellipse( cx, cy , angInicial, angulo, radio+150, radio );
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