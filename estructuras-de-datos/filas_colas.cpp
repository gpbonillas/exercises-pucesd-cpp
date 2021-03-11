#include<iostream.h>
#include<conio.h>
int asteriscos(int n);
void main(){
int ast, num;
cout<<"¿Cuantos asteriscos horizontales y verticales desea ver?...";cin>>num;
cout<<"\n";
ast= asteriscos(num);
}

int asteriscos (int n){
 for(int i=3; i<=n+2; i++){
 gotoxy (i,4);cout<<"*";
 gotoxy (1,i);cout<<"*";
 }
 return 0;
	}
