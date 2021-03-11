#include<iostream.h>
long s;
float a;
void main(){
cout<<"Ingrese su salario actual: ";cin>>s;cout<<"\n";
if(s>20000){
a=s;
cout<<"Su nuevo sueldo es el mismo: "<<a<<"  Dolares";
  }else{
if ((s<=20000) && (s>=15001)){
a=s+(s*(0.05));
cout<<"Su nuevo sueldo es: "<<a<<"  Dolares";
  }else{
if ((s>=9001) && (s<=15000)){
a=s+(s*(0.1));
cout<<"Su nuevo sueldo es: "<<a<<"  Dolares";
  }else{
a=s+(s*(0.2));
cout<<"Su nuevo sueldo es: "<<a<<"  Dolares";
}
  }
	 }
		}
