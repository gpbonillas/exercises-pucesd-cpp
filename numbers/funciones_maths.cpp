#include<iostream.h>
#include<math.h>
void main(){
int opcion;
int c=0, d=0, f=0;
int x, y , z;
long double ftn[10], dmn[10], dominio[10], fun1[10], d2[10], f22[10];
long double PI=3.14159265358979323846;
cout<<"            FUNCIONES                \n\n";
cout<<"Funcion 1:  LINEAL...f(x)=3x-1.                  \n";
cout<<"Funcion 2:  CUADRATICA...f(x)=x^2+2x-1.              \n";
cout<<"Funcion 3:  TRIGONOMETRICA...f(x)=cos(x).          \n";
cout<<"¿Con cual funcion desea trabajar?(1-3): ";cin>>opcion;cout<<"\n\n";

switch(opcion){


case 1:
int cont, i;
cout<<"¿Cuantos numeros desea ingresar?(1-10): ";cin>>cont;
while (cont>10){
cout<<"Ingrese nuevamente: ";cin>>cont;}
cout<<"\n";
	for (x=0; x<cont; x++){
cout<<"Ingrese valor "<<(x+1)<<" : ";cin>>dominio[x];}
cout<<"\n";
	for (i=0; i<cont; i++){
fun1[c]=(3*(dominio[i]))-1;
c++;}
cout<<"DOMINIO (x): \t"<<"IMAGENES f(x): \n";
	for (i=0; i<cont; i++){
cout<<"x"<<(i+1)<<"= "<<dominio[i]<<"\t\t";
cout<<"f(x"<<(i+1)<<")= "<<fun1[i]<<"\n";}

	break;


case 2:
int k, c2;
cout<<"¿Cuantos numeros desea ingresar?(1-10): ";cin>>c2;
while (c2>10){
cout<<"Ingrese nuevamente: ";cin>>c2;}
cout<<"\n";
	for( y=0; y<c2; y++){
cout<<"Ingrese valor "<<(y+1)<<" : ";cin>>d2[y];}
cout<<"\n";
	for (k=0; k<c2; k++){
f22[d]=(d2[k])*(d2[k]) + 2*(d2[k])-1;
d++;}
cout<<"DOMINIO (x): \t"<<"IMAGENES f(x): \n";
	for (k=0; k<c2; k++){
cout<<"x"<<(k+1)<<"= "<<d2[k]<<"\t\t";
cout<<"f(x"<<(k+1)<<")= "<<f22[k]<<"\n";}

	break;


case 3:
int j, it;
cout<<"¿Cuantos numeros desea ingresar?(1-10): ";cin>>it;
while (it>10){
cout<<"Ingrese nuevamente: ";cin>>it;}
cout<<"\n";
cout<<"AVISO: El dominio esta definido para grados sexagesimales";
cout<<"\n\n";
	for (z=0; z<it; z++){
cout<<"Ingrese un valor "<<(z+1)<<" : ";cin>>dmn[z];}
cout<<"\n";
	for (j=0; j<it; j++){
ftn[f]= cos((dmn[j]*PI)/180);
f++; }
cout<<"DOMINIO (x): \t"<<"IMAGENES f(x): \n";
	for(j=0; j<it; j++){
cout<<"x"<<(j+1)<<"= "<<dmn[j]<<"\t\t";
cout<<"f(x"<<(j+1)<<")= "<<ftn[j]<<"\n";}

	break;



default:
cout<<"OPCION INCORRECTA";
}
  }










