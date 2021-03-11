#include<iostream.h>
#include<conio.h>
#include<stdio.h>
void copiar(char a[], char b[]){
 int i=0;
 while(b[i]!='\0'){
   a[i]=b[i];
  i++;
 }
 a[i]='\0'; 
 } 
 int longitud(char c[]){
 int i=0,l=0;
 while(c[i]!='\0'){
     if(c[i]!=32){
     l++;
     }
     i++;
     }
  return l;

 }
 
 void concatenar(char d[], char e[]){
 int i=0,l=0;
 while(d[i]!='\0')
 i++;
 while(e[l]!='\0')
 {
   d[i]=e[l];
   i++;
   l++;
 }
 d[i]='\0';
 }
 int comparar(char f[],char g[]){
 int i=0,dif=0;
 while ((f[i]!='\0'|| g[i]!='\0') && dif==0){

 if(f[i]!=g[i]){
  dif= f[i]-g[i];
   i++;
 }
 return dif;

 }
 
 void main(){
 int opc;
 char m;
 do{
 clrscr();
 gotoxy(27,1);cout<<"MENU PRINCIPAL DE FUNCIONES";
 gotoxy(23,3);cout<<"1. COPIAR UNA CADENA";
 gotoxy(23,5);cout<<"2. LONGITUD DE UNA CADENA";
 gotoxy(23,7);cout<<"3. CONCATENAR UNA CADENA";
 gotoxy(23,9);cout<<"4. COMPARAR UNA CADENA";
 gotoxy(23,11);cout<<"5. SALIR";
 gotoxy(23,15);cout<<"INGRESE LA OPCION QUE DESEA: ";cin>>opc;
 switch (opc){
 case 1:
 clrscr();
 char cad1[100],cad2[100];
 cout<<"INGRESE LA CADENA: ";gets(cad1);
 copiar(cad2,cad1);
 cout<<"la copia de la cadena es: ";puts(cad2);
 gotoxy(23,17);cout<<"¿DESEA REGRESAR AL MENU PRINCIPAL S/N? ";cin>>m;
 break;
 case 2:
 clrscr();
 char cad1[100];
 int longt;
 cout<<"INGRESE LA CADENA: ";gets(cad1);
 longt=longitud(cad1);
 cout<<"la longitud de la cadena es: ";cout<<longt<<caracteres;
 gotoxy(23,17);cout<<"¿DESEA REGRESAR AL MENU PRINCIPAL S/N? ";cin>>m;
 break;
 case 3:
 clrscr();
 char cad1[100], cad2[100];
 cout<<"INGRESE UNA FRASE: "; gets(cad1);
 cout<<"INGRESE LA SEGUNDA FRASE: "; gets(cad2);
 concatenar(cad1,cad2);
 cout<<"LA FRASE CONCATENADA ES: ";puts(cad1);
 gotoxy(23,17);cout<<"¿DESEA REGRESAR AL MENU PRINCIPAL S/N? ";cin>>m;
 break;
 case 4:
 clrscr();
 char cad1[100],cad2[100];
 int comp;
 cout<<"INGRESE LA 1ª FRASE: "; gets(cad1);
 cout<<"INGRESE LA 2ª FRASE: "; gets(cad2);
 comparar(cad1,cad2);
 if(comp==0)
 cout<<"cadena 1 es igual a cadena 2";
 if(comp>0)
 cout<<"la cadena 1 es mayor a cadena 2";
 if(comp<0)
 cout<<"la cadena 1 es menor a cadena 2";
 gotoxy(23,17);cout<<"¿DESEA REGRESAR AL MENU PRINCIPAL S/N? ";cin>>m;
 break;
 }
 }
 while(m=='s'||m=='S');
 }
 }
 }