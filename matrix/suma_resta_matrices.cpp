/*Programa que captura dos matrices e imprime en una matriz su resta
y en otra matriz la suma de las matrices capturadas*/
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main (void)
{
int mat1[3][2], mat2[3][2], mat3[3][2], mat4[3][2];
int y,r,col;
clrscr();
for(r=0;r<3;r++)
for(y=0;y<2;y++)
{
printf("Matriz 1 en [%d][%d]: ",r,y); scanf("%d",&mat1[r][y]);
printf("Matriz 2 en [%d][%dj: ",r,y); scanf("%d",&mat2[r][y]);
mat3[r][y]=(mat1[r][y])+(mat2[r][y]);
mat4[r][y]=(mat1[r][y])-(mat2[r][y]);
}
clrscr();
for(r=0;r<3;r++)
{
col=5;
for(y=0;y<2;y++)
{
gotoxy(col,r+1); printf("[%d]",mat3[r][y]);
gotoxy(col+20,r+1); printf("[%d]",mat4[r][y]);
col=col+5;
}
}
getch();
}
