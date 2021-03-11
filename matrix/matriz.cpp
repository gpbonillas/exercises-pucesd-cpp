#include<iostream.h>
#include<conio.h>
void imprimir(int m1[10][10], int n);

void main(){
int ma1[10][10], i, j, x, y, num;

cout<<"Ingrese dimension: ";cin>>num;
x=3;y=3;
for(i=0;i<num;i++)
{
  for(j=0;j<num;j++)
  {
    gotoxy(x,y);cin>>ma1[i][j];
    x+=4;
  }
  x=3;
  y++;
}

imprimir(ma1,num);

}

void imprimir(int m1[10][10], int n)
{
 clrscr();
 int x, y, i, j;
 x=10; y=10;
 for(i=0;i<n;i++){
 for(j=0;j<n;j++){
 gotoxy(x,y);cout<<m1[i][j];
 x+=4;
 }
 x=10;
 y++;
}
}






  
