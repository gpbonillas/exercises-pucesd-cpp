#include<iostream.h>

void copiar (char *c1, char *c2);
char *c1;
char *c2;

void main(){
  cout<<"Ingrese una cadena: ";cin>>c1;endl;
  copiar(c1,c2);
}

void copiar (char *c1, char*c2){
  while(*c1!='\0'){
    *c2=*c1;
    c2++;
    c1++;
  }
  cout<<"La cadena que usted ingreso es: "<<c2;
}
