#include<iostream.h>
void main() {
float pot=1, sum=0, cont=1, lim;
cout<<"Ingrese un limite para la serie (1/2^2): ";cin>>lim;cout<<"\n";

	while(cont<=lim){
	pot=pot*2;
	sum=sum+(cont/pot);
	cont++;
	}
	cout<<"\n La sumatoria de la serie es: "<<sum;
	}

