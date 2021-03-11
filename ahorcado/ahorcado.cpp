#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
int verificar (int a);
int array[10];
void main(){
int o, f, n, x, v;
char op, gano;
do{
clrscr();
o=0;f=0; n=0; x=0; v=0;
op='n'; gano='n';

	for( int i=0; i<10; i++){
	array [i]=random(9)+1;
	}
	do{
	clrscr();
	cout<<"Ingrese numeros del 1 al 10: ";cin>>n;cout<<"\n";
	x=verificar(n);
	o++;
	if(x>0){
	v=v+x;
	if (v==10){
	o=11;
	gano='s';}
	}else
	{
	f++;}
	}while(o<10);
	if (gano=='s'){
	cout<<"GANO\n\n";}
	else
	{cout<<"PERDIO\n\n";}
	cout<<"Desea Jugar otra vez?(s/n): ";
	cin>>op;
	}while(op=='s'||op=='S');
	}


	int verificar (int a){
	int j=0, aciertos=0;
	for(j=0; j<10; j++){
	if (a==array[j]){
	aciertos++;
	array[j]=0;}
	}
	return aciertos;
	}
