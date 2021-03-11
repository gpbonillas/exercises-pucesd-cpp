#include<iostream.h>
void main(){
int num, fact, cont;
fact=1;
cont=1;
cout<<"Ingrese un numero: ";cin>>num; cout<<"\n";
while(num>0){
fact=fact*cont;
num--;
cont++;
}
cout<<"El factorial del numero es: "<<fact;
}
