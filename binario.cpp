#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
int bin( int *binario, int *decimal,int n);
void main(){
int num, r;
int binario[20];
int decimal[20];
char opc;
do{
clrscr();
gotoxy(1,1);cout<<"Ingrese un numero decimal: ";cin>>num;
r=bin(binario, decimal, num);
gotoxy(1,7);printf("BINARIO: ");
for(int j=0;j<r;j++){
cout<<binario[j];}
gotoxy(1,13);printf("¿Desea volver a ingresar?: ");cin>>opc;
}while(opc=='s'||opc=='S');
}


int bin(int *binario, int *decimal, int n){
int c=0, d=0;
if(n==1)
{
 *binario=n;
 d++;
 binario++;
 *binario='\0';
}
else
 {
  while(n!=1)
	 {
	  *decimal=(n%2);
		n=n/2;
		decimal++;
		if(n==1)
		 {
		  *decimal=n;
		 }
		c++;
	 }
  while(c>=0)
	 {
	  *binario=*decimal;
		decimal--;
		binario++;
		d++;
		c--;
	 }
  *binario='\0';
 }
return d;
}//Fin de la funcion
