#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
void inig();
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
void inig();
int main(void)
{
int x1=200, x2=400, y1=150, y2=350, i;
inig( );
setbkcolor(1);
//rectangulo
setcolor(11);
setlinestyle(1,1,3);
rectangle(x1,y1,x2,y2);
outtextxy(20,20,"rectangle. Solo se modifican sus lineas. Presiona una tecla...");
getch();
//bar
for(i=0;i<=10;i++)
{
cleardevice();
setfillstyle(i,14);
bar(x1,y1,x2,y2);
delay(1000);
}
outtextxy(20,20,"bar. Tiene relleno, pero no bordes. Presiona una tecla...");
getch();
cleardevice();
//bar3d
setcolor(13);
setlinestyle(0,1,3);
for(i=0;i<=10;i++)
{
cleardevice();
setfillstyle(i,11);
bar3d(x1, y1, x2, y2, 50, 1);
delay(1000);
}
outtextxy(20,20,"bar3d. Tiene relleno, tiene bordes, aparenta 3d. Presiona una tecla...");
getch();
closegraph();
return 0;
}
void inig(){ //funcion para iniciar el modo grafico
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver, &gmode, "C:\\BORLANDC\\BGI");
errorcode = graphresult();
if (errorcode != grOk)
{
printf("Error grafico: %s\n", grapherrormsg(errorcode));
printf("Presiona alguna tecla para finalizar:");
getch();
exit(1);
}
}
