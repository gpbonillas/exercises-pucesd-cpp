# include <iostream.h>
# include <conio.h>
# include <string.h>
# include <math.h>
# include <stdio.h>
void main() {
int n,i,pot[20],pot1[20];
cout<<"Ingrese la cantidad de potencias que desea realizar: "; cin>> n;

int *po;

for (i=0;i<n;i++){
	pot[i]=pow(i+1,2);
	pot1[i]=pow(i+1,3);

	*po=pot[i];
        gotoxy(10,i+5);cout<<*po;

	*po=pot1[i];
        gotoxy(20,i+5);cout<<*po;

	}
}
//



