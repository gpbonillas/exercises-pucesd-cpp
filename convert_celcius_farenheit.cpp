/* EMPRESA:PUCESD
	NOMBRE:Gabriel Bonilla
	FECHA: Viernes, 16 de Octubre de 2009
	DESCRIPCION:Convertir grados Celcius a Fahrenheit

	FECHA DE MODIFICACION:Miercoles 7 de octubre de 2009
	RESPONSABLE:
	VERSION 0.1
*/
#include<iostream.h>
float c, f;
void main()
{
#include"cabecera.cpp";
cout<<"Ingrese los grados celcius a convertir: ";
cin>>c;
cout<<"\n";
f=(9*c/5)+32;
cout<<"Grados Fahrenheit: "<<f;
}

