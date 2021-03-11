#include<iostream.h>
int posneg(int n);
void main(){
int num, pos;
cout<<"Ingrese un numero: ";cin>>num;cout<<"\n";
pos=posneg(num);
if(pos>0){
cout<<"P";
}else{
cout<<"N";
}
			}

int posneg(int n){
if(n>0){
return 1;
}else{
return 0;
  }
  }
