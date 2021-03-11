#include<iostream.h>
float circulo (float n);
float cuadrado (float n);
float rectangulo (float n, float m);
float triangulo (float n, float m);
void main(){
int n;
cout<<"             MENU                \n\n\n";
cout<<"Opc 1: Calcular Area de un circulo \n";
cout<<"Opc 2: Calcular area de un cuadrado \n";
cout<<"Opc 3: Calcular area de un rectangulo \n";
cout<<"Opc 4: Calcular area de un triangulo \n\n\n";
cout<<"Elija una opcion: ";cin>>n;cout<<"\n";

switch(n){
case 1:
float radio, Sup;
cout<<"Ingrese el radio del circulo en m: ";cin>>radio;cout<<"\n";
Sup=circulo(radio);
cout<<"Area del circulo es : "<<Sup<<" metros cuadrados";
break;

case 2:
float lado, A;
cout<<"Ingrese el lado del cuadrado en m: ";cin>>lado;cout<<"\n";
A=cuadrado(lado);
cout<<"Area del cuadrado es: "<<A<<" metros cuadrados";
break;

case 3:
float base, altura, area;
cout<<"Ingrese la base del rectangulo en m: ";cin>>base;cout<<"\n";
cout<<"Ingrese la altura del rectangulo en m: ";cin>>altura;cout<<"\n";
area=rectangulo(base,altura);
cout<<"Area del rectangulo es: "<<area<<" metros cuadrados";
break;

case 4:
float ba, h, s;
cout<<"Ingrese la base del triangulo en m: ";cin>>ba; cout<<"\n";
cout<<"Ingrese la altura del triangulo en m: ";cin>>h; cout<<"\n";
s= triangulo(ba,h);
cout<<"Area del triangulo es : "<<s<<" metros cuadrados";
break;
default:
cout<<"OPCION INCORRECTA";
 }
  }


	float circulo (float n){
float g, pi=3.1416;
g=(n*n)*pi;
return g;
 }
	float cuadrado (float n){
 float tr;
 tr=n*n;
 return tr;
}

	float rectangulo (float n , float m){
float asup;
asup=n*m;
return asup;
}



	float triangulo (float n, float m){
float superficie;
superficie=(n*m)/2;
return superficie;
}












