/* EMPRESA:PUCESD
	NOMBRE:Gabriel Bonilla
	FECHA: Viernes 16 de Octubre de 2009
	DESCRIPCION:Imprimir el producto, cociente y el resto de dos enteros de 3 digitos

	FECHA DE MODIFICACION:
	RESPONSABLE:
	VERSION 0.1
*/
#include<iostream.h>
long p, q, r, n, m;
void main()
{
#include"cabecera.cpp"
long n;
cout<<"Ingrese un numero menor a cuatro digitos: ";
cin>>n;
while(n>1000) {
cout<<"Ingrese el numero nuevamente:   \n";
cin>>n;
}
long m;
cout<<"Ingrese un segundo numero menor a cuatro digitos: ";
cin>>m;
while(m>1000){
cout<<"Ingrese el  numero nuevamente:    \n";
cin>>m;
}
cout<<"\n";
cout<<"\n";
long p, r, q;
p=n*m;
q=n/m;
r=n%m;
cout<<"Producto: "<<p<<"\n";
cout<<"\n";
cout<<"Resto: "<<r;cout<<"      "; cout<<"Cociente: "<<q;
}








