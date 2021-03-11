#include<iostream.h>
#include<conio.h>
#include<graphics.h>
void main(){
int radio=100,x,y,x1,y1;
int gdriver=DETECT, gmode;
initgraph(&gdriver,&gmode,"C:\\BC45\\BGI");


x=getmaxx();
x1=x/2;
y=getmaxy();
y1=y/2;
setcolor(15);
ellipse(x1,y1,0,360,(radio+150),100);
getche();
cleardevice();
closegraph();
}
