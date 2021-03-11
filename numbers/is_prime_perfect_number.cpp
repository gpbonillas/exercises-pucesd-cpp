#include<iostream.h>
int primo (int num);
int perfecto (int num);
void main(){
int plus, n, s;
cout<<"Ingrese un numero: ";cin>>n;cout<<"\n";
plus= primo (n);
if (plus==2){
cout<<"\n ES PRIMO ";
}else{
cout<<"\n NO ES PRIMO ";
}
s= perfecto (n);
if (s==n){
cout<<"\n ES PERFECTO ";
}else{
cout<<"\n NO ES PERFECTO ";
}
  }

int primo (int num){
int divisor=1, suma=0;
while (divisor<=num){
 if(num%divisor==0){
 suma=suma+1;
 }
 divisor++;
 }
 return suma;
	}
int perfecto (int num){
int mul=1, sum=0;
 while(mul<num){
  if (num%mul==0){
  sum=sum+mul;
  }
  mul++;
  }
  return sum;
	 }
