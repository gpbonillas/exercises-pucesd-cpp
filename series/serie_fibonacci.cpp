#include<iostream.h>
#include<conio.h>
int num, i, a=0, b=1,suma=0;
void main(){
gotoxy(30,1);cout<<"SERIE DE FIBONACCI";
gotoxy(1,3);cout<<"Cuantos elemnetos de  la serie desea? ";cin>>num;
gotoxy(1,5);cout<<"Los "<<num<<" primeros numeros son: ";cout<<"\n";
if(num==1)
{cout<<a;}
if(num==2)
{cout<<a<<"\n";
cout<<b<<"\n";}

while(num>2){
cout<<a<<"\n";
cout<<b<<"\n";
for(i=2;i<num;i++){
suma=a+b;
cout<<suma;
a=b;
b=suma;
cout<<"\n";
}
num=0;
}
}