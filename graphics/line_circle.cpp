#include<graphics.h>
#include<conio.h>

void Points(int xc,int yc,int x,int y,int color)
{
  putpixel(xc+x,yc+y,color);
  putpixel(xc-x,yc+y,color);
  putpixel(xc+x,yc-y,color);
  putpixel(xc-x,yc-y,color);
  putpixel(xc+y,yc+x,color);
  putpixel(xc+y,yc-x,color);
  putpixel(xc-y,yc+x,color);
  putpixel(xc-y,yc-x,color);
}

void MyCircle(int xc,int yc,int radio,int color)
{
  int x,y,p;
  x=0;
  y=radio;
  p=3-2*radio;
  while(x<y)
  {
   Points(xc,yc,x,y,color);
   if(p<0)
      p=p+4*x+6;
   else{
    p=p+4*(x-y)+10;
    y=y-1;
   }
   x++;
  }
  if(x==y)
   Points(xc,yc,x,y,color);
}

void MyLine(int x1, int y1, int x2, int y2, int color)
{
  int xdelta;
  int ydelta;
  int xstep;
  int ystep;
  int change;

  xdelta = x2 - x1;
  ydelta = y2 - y1;
  if (xdelta < 0){
   xdelta = -xdelta;
   xstep = -1;
  }
  else
   xstep = 1;
  if (ydelta < 0){
   ydelta = -ydelta;
   ystep = -1;
  }
  else
   ystep = 1;
  if (xdelta > ydelta){
   change = xdelta >> 1;
   while (x1 != x2){
     putpixel(x1, y1,color);
     x1 += xstep;
     change += ydelta;
     if (change > xdelta){
      y1 += ystep;
      change -= xdelta;
     }
   }
  }
  else{
   change = ydelta >> 1;
   while (y1 != y2){
     putpixel(x1, y1,color);

     y1 += ystep;
     change += xdelta;
	  if (change > ydelta){
		x1 += xstep;
      change -= ydelta;
     }
	}
  }
}

int main()
{
 int gdriver=DETECT,gmode;
 initgraph(&gdriver,&gmode,"C:\\BC45\\BGI");
 MyCircle(getmaxx()/2,getmaxy()/2,25,WHITE);
 MyLine(100,200,300,110,YELLOW);
 getch();
 closegraph();
 return 0;
}
