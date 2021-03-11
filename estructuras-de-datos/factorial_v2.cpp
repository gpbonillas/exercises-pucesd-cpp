#include<iostream.h>
#include<math.h>
double n, i, f;
void main(){
cout<<"Introduzca un numero: ";cin>>n; cout<<"\n";
f=1;
for (i=n; i!=0; i--){
f=(f*i);
}
cout<<"Su factorial es:  ";
cout<<f;
cout<<"\n";
}