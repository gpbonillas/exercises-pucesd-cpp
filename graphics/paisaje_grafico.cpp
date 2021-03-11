#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>

void main(){
int radio=50,x,y,x1,y1,i,j;
int gdriver=DETECT, gmode;
initgraph(&gdriver,&gmode,"C:\\BORLANDC\\BGI");


x=getmaxx();
x1=x/2;
y=getmaxy();
y1=y/2;
setfillstyle(1,11);
bar(0,0,x,465);
setlinestyle(SOLID_LINE,1,1);
setcolor(2);
line(40,350,110,350);
line(40,350,75,260);
line(75,260,110,350);
setcolor(6);
line(65,350,65,450);
line(85,350,85,450);
for(i=66;i<=85;i++)
  {line(i,350,i,450);}

setcolor(2);
j=260;
i=75;
while(j<=350)
  {line(i,j,i,350);
  j=j+3;
  i--;
  }
for(i=41;i<=45;i++)
  {line(i,350,75,260);}
setcolor(2);
j=75;
for(i=260; i<=350; i=i+3)
  {line(j,i,j,350);
   j++;
  }
for(j=109;j>=105;j--)
   {line(j,350,75,260);}
setfillstyle(1,6);
bar(460,166,635,465);
setcolor(0);
line(460,166,460,465);
line(460,166,635,166);
line(635,166,635,465);
setfillstyle(1,0);
for(i=418;i>170;i=i-40)
   {bar(460,i,522,i);
    bar(575,i,635,i);
   }
setcolor(0);
line(522,166,522,465);
line(575,166,575,465);
line(495,160,495,166);
line(600,160,600,166);
setfillstyle(1,12);
bar(528,435,569,465);
line(548,435,548,465);
line(528,435,528,465);
line(569,435,569,465);
line(528,435,569,435);
setfillstyle(1,5);
setcolor(3);
ellipse(180,200,0,45,50,30);
do{
setfillstyle(1,13);
bar(465,140,630,160);
settextstyle(3,0,1);
randomize();
i=random(15);
setcolor(random(15));
if((i+2)%2==0){
outtextxy(475,140,"PATRICIO'S HOTEL");
}else{
settextstyle(3,0,1);
outtextxy(505,140,"WELCOME");
}
delay(100);
}while(!kbhit());

cleardevice();
closegraph();
}
