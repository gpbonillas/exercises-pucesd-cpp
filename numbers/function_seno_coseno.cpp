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
printf("\n\nFUNCION SENO (amarillo) Y COSENO (verde)");

for (i=0; i<360; i++)
{
y = origeny - ( 100 * ( sin( (i*M_PI)/180 ) ) );
putpixel(origenx+i, y, 14);
delay(20);
}
for (i=0; i<360; i++)
{
y = origeny - ( 100 * ( cos( (i*M_PI)/180 ) ) );
putpixel(origenx+i, y, 2);
delay(20);
}
printf("\n\nFIN DE LA GRAFICACION");
getch();
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