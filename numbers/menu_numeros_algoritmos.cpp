#include<iostream.h>
#include<conio.h>
void main(){
clrscr();
int opc;
cout<<"                     MENU       \n\n";
cout<<"Opc 1: Mayor de 2 numeros \n";
cout<<"Opc 2: Suma de n numeros pares y el producto de los impares\n";
cout<<"Opc 3: N primeros numeros de la serie de Fibonacci \n\n";
cout<<"Ingrese la opcion que desee(1-3): ";cin>>opc;cout<<"\n\n\n";

switch(opc){

case 1:
int a, b;
cout<<"        Mayor de 2 numeros\n\n\n";
cout<<"Ingrese un numero: ";cin>>a;cout<<"\n";
cout<<"Ingrese otro numero: ";cin>>b;cout<<"\n";
if(a>b){
cout<<"El mayor es: "<<a;
}else{
cout<<"El mayor es: "<<b;

break;

case 2:

int n, j, pro=1, var, sum=0;
cout<<"      Suma de n numeros pares y el producto de los impares\n\n\n";
cout<<"Ingrese un numero limite de numeros: ";cin>>n;cout<<"\n";
for (j=1; j<=n; j++){
cout<<"Ingrese un numero: ";cin>>var;
if(var%2==0){
sum=sum+var;
}else{
pro=pro*var;
}
  }
cout<<"\n";
cout<<"La suma de los pares es: "<<sum;cout<<"\n";
cout<<"El producto de los impares es: "<<pro;
break;

case 3:
int k, am, bm, i, suma ;
cout<<"        N primeros numeros de la serie de Fibonacci \n\n\n";
cout<<"Ingrese un numero limite: ";cin>>k;cout<<"\n";
am=0; bm=1;
cout<<am<<"\n"; cout<<bm<<"\n";
for ( i=1; i<=k-2; i++){
	 suma=am+bm;
	 cout<<suma<<"\n";
	 am=bm; bm=suma;
}
 break;
default:
cout<<"OPCION INCORRECTA";

}
	}
		}



