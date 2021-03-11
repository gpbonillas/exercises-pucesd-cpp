#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
void inig();
int main(void)
{
float nper=0, menos1=0, mas1=0, prepa=0, cch=0, otra=0;
float angulo,angulo2;
inig();
setlinestyle(0,1,3);
printf("PROCESADO DE UNA ENCUESTA:");
printf("\nNumero de personas encuestadas: ");
scanf("%f",&nper);
do{
printf("\n¨Cuantas personas tardan en llegar mas de 1 hora a la escuela? ");
scanf("%f",&mas1);
}while(mas1 > nper);
menos1 = nper - mas1;
printf("\nPersonas que tardan menos de 1 hora en llegar: %f",menos1);
do{
printf("\n¨Cuantas personas vienen de prepa?");
scanf("%f",&prepa);
}while(prepa > nper);
do{
printf("\n¨Cuantas personas vienen de cch?");
scanf("%f",&cch);
}while(cch > (nper - prepa));
otra = nper - prepa - cch;
printf("\nPersonas de otras escuelas: %f",otra);
printf("\nSe van a generar las graficas...");
angulo = ( 360/nper ) * mas1;
setcolor(14);
setfillstyle(1,14);
outtextxy(10, 410,"Alumnos que tardan mas de 1 hora");
pieslice( 100, 300 , 0, angulo, 100 );
setcolor(13);
setfillstyle(1,13);
outtextxy(10, 430,"Alumnos que tardan menos de 1 hora");
pieslice(100,300, angulo, 360, 100);

angulo = ( 360/nper ) * prepa;
setcolor(2);
setfillstyle(1,2);
outtextxy(400, 410,"Alumnos de la ENP");
pieslice( 450, 300 , 0, angulo, 100 );
setcolor(1);
setfillstyle(1,1);
outtextxy(400, 430,"Alumnos del CCH");
angulo2 = ( 360/nper ) * (prepa+cch);
pieslice(450,300, angulo, angulo2, 100);
if(otra >= 1)
{
setcolor(12);
setfillstyle(1,12);
angulo2 = ( 360/nper ) * (prepa+cch);
outtextxy(400, 450,"Alumnos de otras escuelas");
pieslice(450,300, angulo2, 360, 100);
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