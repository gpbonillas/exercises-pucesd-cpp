#include <stdio.h>               /*LIBRERIA POR DEFAULT*/
#include <stdlib.h>              /*LIBRERIA PARA MANEJAR EL RANDOM*/
#include <ctype.h>               /*LIBRERIA PARA MANEJAR EL ISALPHA*/
#include <conio.h>               /*LIBRERIA DE GRAFICOS*/
#include <string.h>              /*LIBRERIA PARA MANEJAR EL STRLEN*/
char palabras[10][10];           /*ARREGLO DONDE GUARDO LOS NOMBRES*/
char palabra[10],respuesta[10];  /*VARIABLE DONDE IRE ALMACENANDO LAS LETRAS*/
char letra,opc,catego;                  /*VARIABLE QUE ALMACENO LA LETRA*/
int i,j,y,elegida,longitud,opor,a;
int presenta(void);
int categoria(void);
int elegir(int);
int imprime(void);

void main(void){
presenta();
do{
categoria();
clrscr();

i=j=y=elegida=longitud=opor=a=0;   /*INICIALIZO LAS VARIABLES CON CERO*/

	for(i=0;i<10;i++){
		 respuesta[i]=NULL;}        /*CON ESTE FOR LIMPIO LA CADENA*/

randomize();/*ESTA FUNCION CARGA LOS NOMBRES AL ARREGLO*/
j=random(9);/*ESTA FUNCION ELIGE UN NUMERO ALEATORIO PARA ESCOGER UNA PALABRA*/
/*FUNCION QUE ELIGE ALEATORIAMENTE LA PALABRA*/
elegir(j);
longitud=strlen(palabra);
imprime();
do{
gotoxy(28,12);
printf("E L I G E  L A  L E T R A=>>");

do{
letra=toupper(getch());     /*CON ESTE DO NO ADMITO NUMEROS*/
}while(!isalpha(letra));

gotoxy(10+opor*3,22);
printf("%c",letra);

for(i=0;i<longitud;i++){
if(letra==palabra[i]){
gotoxy(15+i*4+18,19);
printf("%c",letra);
respuesta[i]=letra;            }}
y=strcmp(palabra,respuesta);
if(y==0){
gotoxy(32,23);
printf("CORRECTO");}
opor++;
}while(opor<20 && y!=0);
if(opor==20){
gotoxy(26,23);
printf("**INCORRECTO LA PALABRA ERA** %s",palabra);}
gotoxy(28,25);
printf("�DESEA VOLVER A JUGAR[S/N]=>>?");

do{
opc=toupper(getch());
}while(opc!='S' && opc!='N');
}while(opc!='N');
presenta();
clrscr();
exit(1);
return;
}

cargarfrutas(){
  strcpy(palabras[0],"MANZANA");
  strcpy(palabras[1],"NARANJA");
  strcpy(palabras[2],"SANDIA");
  strcpy(palabras[3],"FRESA");
  strcpy(palabras[4],"TORONJA");
  strcpy(palabras[5],"MANGO");
  strcpy(palabras[6],"PLATANO");
  strcpy(palabras[7],"UVAS");
  strcpy(palabras[8],"GUAYABA");
  strcpy(palabras[9],"CIRUELA");
  return 0;}

elegir(int pal){
strcpy(palabra,palabras[pal]);
return 0;}

imprime(){
for(i=1;i<=longitud;i++){
gotoxy(15+i*4+14,20);printf("_");}
	 return 0;}

presenta(){
clrscr();
gotoxy(25,12);
printf("JUEGO DEL AHORCADO");
gotoxy(30,13);
printf("ESPERA UN MOMENTO...");
return 0;}

cargardeportes(){
  strcpy(palabras[0],"FUTBOL");
  strcpy(palabras[1],"BASEBALL");
  strcpy(palabras[2],"GOLF");
  strcpy(palabras[3],"TENNIS");
  strcpy(palabras[4],"GIMNASIA");
  strcpy(palabras[5],"PINPON");
  strcpy(palabras[6],"SOCCER");
  strcpy(palabras[7],"NATACION");
  strcpy(palabras[8],"MARATON");
  strcpy(palabras[9],"CICLISMO");
  return 0;}

cargarpaises(){
strcpy(palabras[0],"JAPON");
  strcpy(palabras[1],"COREA");
  strcpy(palabras[2],"FRANCIA");
  strcpy(palabras[3],"ITALIA");
  strcpy(palabras[4],"MEXICO");
  strcpy(palabras[5],"CANADA");
  strcpy(palabras[6],"USA");
  strcpy(palabras[7],"ARGENTINA");
  strcpy(palabras[8],"BRASIL");
  strcpy(palabras[9],"PARAGUAY");
  return 0;}

categoria(){
clrscr();
gotoxy(25,1);
printf("***C A T E G O R I A S***");
gotoxy(30,5);
printf("1.-F R U T A S");
gotoxy(30,8);
printf("2.-D E P O R T E S");
gotoxy(30,11);
printf("3.-P A I S E S");
gotoxy(30,15);
printf("ELIGE TU OPCION=>>");

do{
catego=getch();
}while(catego!='1' && catego!='2' && catego!='3');

switch(catego){
case '1':cargarfrutas();
break;
case '2':cargardeportes();
break;
case '3':cargarpaises();
break;}
return 0;
}