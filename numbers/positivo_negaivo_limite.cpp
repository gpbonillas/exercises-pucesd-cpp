#include<iostream.h>
#include<ctype.h>
#include<conio.h>

void main(){
int n, x=0, q=0, r=0, i;
int p;

cout<<"Ingresar un numero limite: ";cin>>n;
for (i=1; i<=n; i++){
cout<<"Ingrese un numero: ";cin>>p;
	 if (p>0){
x=x+1;
  }else{
	 if (p<0){
q=q+1;
  }else{
r=r+1;
	}
		 }
			 }

cout<<"\n\n";
cout<<"Se ingresaron: \n\n";
cout<<x<<"  Positivos\n"<<q<<"  Negativos\n"<<r<<"  Nulos";
}

