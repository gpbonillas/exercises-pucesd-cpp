#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
int i, j, *puntero, vector1[20], vector[3], aux=0, opcion, aux1=1;
void menu();

void main() {
gotoxy (25,1); cout <<"T R I A N G U L O   D E   P A S C A L\n\n\n";
do {
menu();
int n;

switch (opcion) {
case 1:
clrscr();
cout <<"Ingrese el numero de digitos que desea: "; cin >> n;
cout<<"\n";
for (i=0;i<n;i++) {
cout <<"Ingrese "<<i+1<<" digito: "; cin >>vector[i];
}
getche();
break;

case 2:
clrscr();
for(i=0; i < n-1; i++){
      for(j=i+1; j < n; j++) {
      if(vector[i] > vector[j]){
         aux = vector[i];
         vector[i] = vector[j];
         vector[j] = aux;
      }
   }
}
cout<<"\n";
for (i=0;i<n;i++) {
*puntero= vector[i];
cout <<*puntero;
cout<<"\n";
}
getche();
break;

case 3:
clrscr();
for(i=0; i < n-1; i++){
      for(j=i+1; j < n; j++) {
      if(vector[i] < vector[j]){
         aux = vector[ i ];
         vector[i] = vector[j];
         vector[j] = aux;
      }
   }
}
cout<<"\n";
for (i=0;i<n;i++) {
*puntero= vector[i];
cout <<*puntero;
cout<<"\n";
}
getche();
break;

case 4:
clrscr();
gotoxy(20,20); cout << "Elaborado por Jaime Gómez";
aux1=0;
getch();
break;

default:  cout <<  "error";
break;

}


} // cierro do
while (aux1==1);







}


void menu (){
	clrscr();
        gotoxy (5,2); cout <<"ESCOJA LA OPCIO DESEADA\n\n";
	gotoxy (15,5); cout <<"1.- INGRESAR VECTOR";
	gotoxy (15,7); cout <<"2.- IMPRIMIR ORDENADO ASCEDENTE";
	gotoxy (15,9); cout <<"3.- IMPRIMIR ORDENADO DESCENDENTE";
	gotoxy (15,11); cout <<"4.- SALIR";
	gotoxy (5,17);
	cout << "Ingrese la opcion deseada ";  cin >> opcion;
}
