//////////////////////////////////////////////////////////
/////////codigo de c++ para el juego res en raya/////////
/////////Elaborado por: Luis Suarez/////////////////////
////////Cuarto Sistemas////////////////////////////////
//////////////////////////////////////////////////////
#include <stdio.h>
#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
//--------------estructura para datos---------
struct estructura
{
int mat[3][3];
char nj1[15];
char nj2[15];
int jug;
int mod;
char narch[10];
};
//-----------------------funciones-----------------------------
void abrir(void);
void caratula(void);
void limpiarMatrix(int [][3]);
void cuadro(char nomb1[],char nomb2[],int modo);
void imprimirSimbolo(int,int,int);
void mover(int [][3],int,int,int,int *modo,char[],char[],estructura registro);
int cantidad(int [][3],int,int);
int ganador(int [][3]);
int empate(int [][3]);
int modoJuego(void);
void nombres(int modo,char nomb1[],char nomb2[]);
void ininombres(char nomb1[],char nomb2[]);
void limpiarregistro(estructura datos);
int matrizVacia(int [][3]);
//----------------funcion principal-----------------------------------
void main()
{
caratula();
estructura registro;
int matriz[3][3];
int salir;
int simbolo;
int fila,columna;
int jugador;
int modo;
char nombre1[15];
char nombre2[15];
randomize();
do
{
fila=1;
columna=1;
simbolo=jugador=1;
salir=0;
modo=modoJuego();
if (modo==2)
{
exit(1);
}
if (modo==1)
{
nombres(modo,nombre1,nombre2);
salir=2;
while ((salir!=1))
{
limpiarMatrix(matriz);
char oj[5];
cuadro(nombre1,nombre2,modo);
mover(matriz,jugador,fila,columna,&modo,nombre1,nombre2,registro);
settextstyle(2,0,6);
outtextxy(150,280,"1. SALIR AL MENU");
outtextxy(150,300,"2. REEPETIR JUEGO");
outtextxy(150,320,"DIGITE LA OPCION:");
cscanf("%s",oj);
outtextxy(350,320,oj);
salir=atoi(oj);
}
salir=0;
}
} while (salir!=1);
}
//-------------Matriz en cero--------------
void limpiarMatrix(int mat[][3])
{
for(int f=0;f<3;f++)
for(int c=0;c<3;c++)
{
mat[f][c]=0;
imprimirSimbolo(0,f,c);
}
}
//----------------------CUADROS DE JUEGO-----------------------------------
void cuadro(char nomb1[],char nomb2[],int modo)
{
cleardevice();
setcolor(1);
line(0,0,640,0);
line(5,5,635,5);
line(0,479,639,479);
line(5,475,635,475);
line(0,479,0,0);
line(5,475,5,5);
line(639,0,639,479);
line(635,5,635,475);
setcolor(4);
settextstyle(1,0,4);
outtextxy(50,10,"Instituto Superior Cordillera");
settextstyle(2,0,6);
outtextxy(100,70,"JUGADOR 1");
setcolor(1);
outtextxy(120,90,nomb1);
setcolor(4);
outtextxy(100,110,"TIPO");
setcolor(1);
outtextxy(120,130,"HUMANO");
setcolor(4);
outtextxy(100,150,"SIMBOLO");
setcolor(1);
settextstyle(1,0,8);
outtextxy(120,150,"X");
setcolor(4);
settextstyle(2,0,6);
outtextxy(450,70,"JUGADOR 2");
setcolor(1);
outtextxy(470,90,nomb2);
setcolor(4);
outtextxy(450,110,"TIPO");
setcolor(1);
outtextxy(470,130,"HUMANO");
setcolor(4);
outtextxy(450,150,"SIMBOLO");
setcolor(1);
settextstyle(1,0,8);
outtextxy(470,150,"O");
setcolor(4);
bar(210,90,405,280);
line(210,90,210,280);
line(275,90,275,280);
line(340,90,340,280);
line(405,90,405,280);
line(210,90,405,90);
line(210,155,405,155);
line(210,220,405,220);
line(210,280,405,280);
settextstyle(1,0,2);
setcolor(7);
outtextxy(10,450,"Con el Movimiento de las teclas de direcion Enpiese A Jugar
");
}
//--------Imprimir el simbolo en la fila y columna.
void imprimirSimbolo(int simbolo,int fila, int columna)
{
int x,y,x1,y1;
//FILA 0
if((fila==0)&&(columna==0))
{
x=220;
y=70;
}
if(fila==0&&columna==1)
{
x=290;
y=70;
}
if(fila==0&&columna==2)
{
x=350;
y=70;
}
//FILA 1
if(fila==1&&columna==0)
{
x=220;
y=140;
}
if(fila==1&&columna==1)
{
x=290;
y=140;
}
if(fila==1&&columna==2)
{
x=350;
y=140;
}
//FILA 2
if(fila==2&&columna==0)
{
x=220;
y=200;
}
if(fila==2&&columna==1)
{
x=290;
y=200;
}
if(fila==2&&columna==2)
{
x=350;
y=200;
}
if (simbolo==-1)
{
setcolor(15);
outtextxy(x,y,"X");
setcolor(4);
outtextxy(x,y,"O");
}
if (simbolo==1)
{
setcolor(15);
outtextxy(x,y,"O");
setcolor(1);
outtextxy(x,y,"X");
}
if (simbolo==0)
{
setcolor(15);
outtextxy(x,y,"X");
outtextxy(x,y,"O");
}
}
//--------------------POCIONCION DE TECLA DIGITADA---------------------------
void mover(int matrix[][3],int jugador,int fila, int columna,int *modo,char
jug1[],char jug2[],estructura registro)
{
int tecla,turno,espacio,ff,cc,error;
char nombrea[10];
turno=jugador;
getch();
do
{
settextstyle(2,0,8);
outtextxy(150,45,"EL TURNO ES:");
if(turno==1)
{
setcolor(0);
outtextxy(350,45,jug2);
setcolor(4);
outtextxy(350,45,jug1);
settextstyle(1,0,8);
}else if(turno==-1)
{
setcolor(0);
outtextxy(350,45,jug1);
setcolor(4);
outtextxy(350,45,jug2);
settextstyle(1,0,8);
}
tecla=getch();
if (tecla == 0)
tecla = getch();
switch (tecla)
{
case 72:
{
gotoxy(25,20);
imprimirSimbolo(matrix[fila][columna],fila,columna);
//cambio de fila
if (fila==0)
fila=2;
else
fila--;
imprimirSimbolo(turno,fila,columna);
break;
}
case 80:
{
gotoxy(25,20);
imprimirSimbolo(matrix[fila][columna],fila,columna);
if (fila==2)
fila=0;
else
fila++;
imprimirSimbolo(turno,fila,columna);
break;
}
case 75:
{
imprimirSimbolo(matrix[fila][columna],fila,columna);
if (columna==0)
columna=2;
else
columna--;
imprimirSimbolo(turno,fila,columna);
break;
}
case 77:
{
imprimirSimbolo(matrix[fila][columna],fila,columna);
if (columna==2)
columna=0;
else
columna++;
imprimirSimbolo(turno,fila,columna);
break;
}
case 13://------enter-----
{
if (matrix[fila][columna]==0)
{
if (turno==1)
{
matrix[fila][columna]=1;
imprimirSimbolo(1,fila,columna);
turno=-1;
}
else
if (turno==-1)
{
matrix[fila][columna]=-1;
imprimirSimbolo(-1,fila,columna);
turno=1;
}
}
else
{
settextstyle(2,0,8);
setcolor(4);
outtextxy(100,405,"CELDA OCUPADA");
outtextxy(100,425,"PRECIONE ENTER PARA CONTINUAR");
getch();
setcolor(0);
outtextxy(100,405,"CELDA OCUPADA");
outtextxy(100,425,"PRECIONE ENTER PARA CONTINUAR");
settextstyle(1,0,8);
}
if (ganador(matrix)==1)
{
settextstyle(2,0,8);
setcolor(4);
outtextxy(100,405,"GANO El JUGADOR:");
outtextxy(350,405,jug1);
tecla=27;
}
if (ganador(matrix)==-1)
{
settextstyle(2,0,8);
setcolor(4);
outtextxy(100,405,"GANO EL JUGADOR:");
outtextxy(350,405,jug2);
tecla=27;
}
if (empate(matrix)==1)
{
settextstyle(2,0,8);
setcolor(4);
outtextxy(100,405,"JUEGO EMPATADO");
tecla=27;
}
if( (ganador(matrix)==0) && ( empate(matrix)==0))
imprimirSimbolo(turno,fila,columna);
textcolor(WHITE);
break;
}
}
}while (tecla!=27);
}
//--------------------------cantidad para verificar ganador-----------
int cantidad(int matrix[][3],int linea,int num)
{
int cont=0;
int l;
switch (linea)
{
case 1:
{
for(l=0;l<3;l++)
{
if (matrix[0][l]==num)
cont++;
}
break;
}
case 2:
{
for(l=0;l<3;l++)
{
if (matrix[1][l]==num)
cont++;
}
break;
}
case 3:
{
for(l=0;l<3;l++)
{
if (matrix[2][l]==num)
cont++;
}
break;
}
case 4:
{
for(l=0;l<3;l++)
{
if (matrix[l][0]==num)
cont++;
}
break;
}
case 5:
{
for(l=0;l<3;l++)
{
if (matrix[l][1]==num)
cont++;
}
break;
}
case 6:
{
for(l=0;l<3;l++)
{
if (matrix[l][2]==num)
cont++;
}
break;
}
case 7:
{
for(l=0;l<3;l++)
{
if (matrix[l][l]==num)
cont++;
}
break;
}
case 8:
{
for(l=0;l<3;l++)
{
if (matrix[2-l][l]==num)
cont++;
}
break;
}
}
return(cont);
}
//-------------Que Jugador le toca------------------------------------
int ganador(int matrix[][3])
{
int winner=0;
if (cantidad(matrix,1,-1)==3)
winner=-1;
if (cantidad(matrix,2,-1)==3)
winner=-1;
if (cantidad(matrix,3,-1)==3)
winner=-1;
if (cantidad(matrix,4,-1)==3)
winner=-1;
if (cantidad(matrix,5,-1)==3)
winner=-1;
if (cantidad(matrix,6,-1)==3)
winner=-1;
if (cantidad(matrix,7,-1)==3)
winner=-1;
if (cantidad(matrix,8,-1)==3)
winner=-1;
if (cantidad(matrix,1,1)==3)
winner=1;
if (cantidad(matrix,2,1)==3)
winner=1;
if (cantidad(matrix,3,1)==3)
winner=1;
if (cantidad(matrix,4,1)==3)
winner=1;
if (cantidad(matrix,5,1)==3)
winner=1;
if (cantidad(matrix,6,1)==3)
winner=1;
if (cantidad(matrix,7,1)==3)
winner=1;
if (cantidad(matrix,8,1)==3)
winner=1;
return (winner);
}
//-----Retorna para conparar quien gana
int empate(int matrix[][3])
{
int emp;
int contador=0;
int c,f;
for(f=0;f<3;f++)
for(c=0;c<3;c++)
{
if (matrix[f][c]!=0)
contador++;
}
if ((ganador(matrix)==0)&&(contador==9))
emp=1;
else
emp=0;
return (emp);
}
//---------------------MENU PRINCIPAL----------------------------
int modoJuego(void)
{
cleardevice();
int opcion,tecla;
char opc[5];
setcolor(1);
line(0,0,640,0);
line(5,5,635,5);
line(0,479,639,479);
line(5,475,635,475);
line(0,479,0,0);
line(5,475,5,5);
line(639,0,639,479);
line(635,5,635,475);
settextstyle(1,0,4);
outtextxy(50,10,"Instituto Superior Cordillera");
setbkcolor(8);
bar3d(30,90,550,290,20,3);
setcolor(4);
outtextxy(70,100,"SELECCIONE UNA OPCION");
settextstyle(2,0,6);
outtextxy(50,150,"1.- IGRESAR AL JUEGO");
outtextxy(50,180,"2.- SALIR DEL JUEGO");
outtextxy(120,220,"DIGITE SU OPCION:");
cscanf("%s",opc);
setcolor(1);
outtextxy(280,220,opc);
opcion=atoi(opc);
return (opcion);
}
//---------------------nombres de jugadores-------------------------------
void nombres(int modo,char nomb1[],char nomb2[])
{
ininombres(nomb1,nomb2);
settextstyle(2,0,4);
outtextxy(50,250,"NOMBRE DEL PRIMER JUGADOR:");
cscanf("%s",nomb1);
outtextxy(300,250,nomb1);
outtextxy(50,270,"NOMBRE DEL SEGUNDO JUGADOR:");
cscanf("%s",nomb2);
outtextxy(300,270,nomb2);
}
//----------Nombre en Blanco-----------------
void ininombres(char nomb1[],char nomb2[])
{
for (int i=0;i<15;i++)
{
nomb1[i]=' ';
nomb2[i]=' ';
}
}
//--------0 si esta vacia y 1 si esta con valoresint
matrizVacia(int matrix[][3])
{
int resultado=0;
for (int f=0;f<3;f++)
for (int c=0;c<3;c++)
if(matrix[f][c]!=0)
resultado=1;
return resultado;
}
//------------limpiar el contenido--------------
void limpiarregistro(estructura datos)
{
for (int ff=0;ff<3;ff++)
for (int cc=0;cc<3;cc++)
datos.mat[ff][cc]=0;
for (int cc=0;cc<10;cc++)
{
datos.nj1[cc]=' ';
datos.nj2[cc]=' ';
datos.narch[cc]=' ';
}
datos.jug=0;
datos.mod=0;
}
//--------------------------CARATULA-----------------------------------------
void caratula()
{ abrir();
cleardevice ();
setcolor(1);
line(0,0,640,0);
line(5,5,635,5);
line(0,479,639,479);
line(5,475,635,475);
line(0,479,0,0);
line(5,475,5,5);
line(639,0,639,479);
line(635,5,635,475);
settextstyle(1,0,4);
outtextxy(50,10,"Instituto Superior Cordillera");
setbkcolor(8);
bar3d(30,90,550,290,20,3);
setcolor(4);
settextstyle(7,0,3);
setcolor(5);
outtextxy(50,100,"Programacion Orientada a Objetos");
outtextxy(100,140,"Luis Suarez");
outtextxy(100,160,"Cuarto Systemas");
outtextxy(100,180,"Ing: Ramiro Brito");
settextstyle(8,0,2);
setcolor(5);
outtextxy(100,240,"Precione Enter para Continuar");
getch();
cleardevice();
}
//-------------------ABRIR MODO GRAFICO----------------------
void abrir(void)
{
int gdriver = DETECT, gmode;
initgraph(&gdriver, &gmode, "C:\\borlandc\\bgi");
}