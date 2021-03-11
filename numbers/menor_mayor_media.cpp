#include<iostream.h>
#include<conio.h>
int s=0, c=0, k=0;
float n, M, p;
void main(){
cout<<"Cuantos numeros quiere ingresar? ";cin>>n;

  for(int i=1; i<=n; i++){
clrscr();
cout<<"Ingrese un numero: ";cin>>M;cout<<"\n";

  if(M<k){
k=M;
}else{
c=M;
}
s=s+M;
p=s/n;
 }

cout<<"El menor es: "<<c;cout<<"\n\n";
cout<<"El mayor es: "<<k;cout<<"\n\n";
cout<<"La media es: "<<p;

}
