#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>

void main(){

int c=0, cont=0, veri=0, longi,longit , i;
char cad1[50], cad2[50], cad1n[50];
cout<<"Ingrese una cadena: ";gets(cad1);cout<<"\n";
longi=strlen(cad1);

for(i=longi-1; i>=0; i--){
cad2[i]=cad1[cont];
cont++;
}

for(i=0; i<longi; i++){

if(cad2[i]==cad1[i]){
veri++;}
}
cout<<"veri="<<veri<<"\n";
if(veri==longi){
cout<<"ES PALINDROMO";
}else{
cout<<"NO ES";
}
}