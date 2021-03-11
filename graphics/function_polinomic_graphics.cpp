//GRAFICA DE UNA FUNCION POLINOMICA
//Autor: Jos‚ Gustavo Barros G.
//Mail: barros.jose@hotmail.com
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
#include<float.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
void caratula (void);
void grid (void);
float T,T1,tt,f,X;
float a,b[10],n,t[20];
int i,j,x,y[60],bajo=0,l,s;
int px,py,term,coef=0, expo, xp,yp, termi;
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "C:\\BORLANDC\\BGI");
	cleardevice();
//	caratula();
	initgraph(&gdriver, &gmode, "C:\\BORLANDC\\BGI");
	cleardevice();
	settextstyle(SMALL_FONT, HORIZ_DIR,5);
	gotoxy(12,8);
	printf("Grafica de Funciones");
	gotoxy(12,12);
	printf("Introduzca el Exponente maximo n: ");
	scanf("%f",&n);
	gotoxy(12,13);
	printf("Introduzca el Termino Independiente: ");
	scanf("%f",&a);
	expo=n;
	for (term=0;term<n;term++)
	{
		gotoxy(12,14+term);
		coef++;
		printf("Introduzca el coeficiente de x^%d : ",expo);
		scanf("%f",&b[term]);
		expo--;
	}
	outtextxy(380,450,"GRAFICANDO...");
	sleep(2);
	cleardevice();
	grid();
	setcolor(WHITE);
	line(0,275,639,275);
	line(300,0,300,478);
	rectangle(1,1,638,478);
	for (T1=0;T1<=600;T1+=40)
	{
		line (T1,280,T1,270);
	}
	for (T1=0; T1<=510;T1+=25)
	{
		line (305,T1,295,T1);
	}
	for (x=-10;x<=10;x++)
	{
		y[i]=0;
		bajo=0;
		for (termi=n;termi>0;termi--)
		{
			t[termi-1]=b[bajo]*pow(x,n-bajo);
			bajo++;
			y[i]=y[i]+t[termi-1];
		}
		y[i]=y[i]+a;
		if (x==-10)
		{
			putpixel (300+x,275-y[i],RED);
		}
		else
		{
			//putpixel (200+x,275-y[i],WHITE);
			circle(300+x,275-y[i],1);
			line(300+xp,275-yp,300+x,275-y[i]);
		}
		xp=x;
		yp=y[i];
	}
	outtextxy(380,450,"Presione una tecla para Salir...");
	getch();
	return 0;
}
void grid (void)
{
setcolor(15);
rectangle(200,0,400,500);
rectangle(100,0,600,500);
rectangle(300,0,700,500);
rectangle(50,0,150,500);
rectangle(250,0,350,500);
rectangle(500,0,300,500);
rectangle(450,0,550,500);
rectangle(650,0,550,500);
rectangle(0,50,750,150);
rectangle(0,150,750,50);
rectangle(0,200,750,250);
rectangle(0,100,750,300);
rectangle(0,350,750,400);
rectangle(0,450,750,500);
}
void caratula (void)
{
   int l,k,s;
   char op;
   setcolor(1);
   setviewport(50,50,589,429,3);
   rectangle(538,189,539,379);
    setbkcolor(0);
    setcolor(9);
    settextstyle(4,HORIZ_DIR,5);
    outtextxy(50,30,"Gr fica de funciones");
    setcolor(9);
    settextstyle(4,HORIZ_DIR,5);
    outtextxy(188,80,"Autor:");
    setcolor(15);
    settextstyle(4,HORIZ_DIR,3);
    outtextxy(188,150,"Barros G. Jos‚ Gustavo");
    setcolor(9);
   for(k=30;k<=500;k++)
    {
     setcolor(15);
     arc(k,370,30,180,20);
     //line(i+4,360,i+10,360);
     arc(k+25,360,270,30,7);
     circle(k-15,370,3);
     circle(k+20,370,3);
     delay(10);
     setcolor(0);
     arc(k,370,30,180,20);
     //line(i+4,360,i+10,360);
     arc(k+25,360,270,30,7);
     circle(k-15,370,3);
     circle(k+20,370,3);
     delay(1250);
    }
    getch();
   closegraph();
}