#include<iostream.h>
#include<math.h>
void main(){
float n, s, e;
cout<<"Ingrese un numero: ";cin>>n;cout<<"\n\n";
s=0;
	for(float d=1; d<=n; d++){
e=pow(2,d);
s=s+(d/e);
}
cout<<"La suma de la serie (num/2^num) es:  "<<s;
}