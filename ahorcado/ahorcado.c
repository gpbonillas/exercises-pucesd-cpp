#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

void main(){

char matriz[10][20]={"helicoptero","naranja","helice","jardinero","electricista","calendario","taladro","cometa","saltamontes","antena"};
int plantilla[1][20],abc=0,x=37,y=21;
char abecedario[34];
int palabra,numpalabras=10,adivina,fallos,longpalabra,longadivina,salir;
char repetir='s';
int acierto; //Variable booleana: 1 significa que acert� una

int i,j;
char letra[1];


clrscr();
printf("\n\t=======================================");
printf("\n\t           JUEGO DEL AHORCADO");
printf("\n\t=======================================");
printf("");
printf("\n\tInstrucciones: El ordenador pensar  una palabra y t� tienes 10");
printf("\n\tintentos para acertarla. En cada intento podr s elegir una letra.");
printf("\n\tSi la palabra a adivinar la contiene, aparecer  en su corres-");
printf("\n\tpondiente posici�n. Sino, tendr s un intento menos.Hasta agotar");
printf("\n\tlos 10. ����BUENA SUERTE!!!");
printf("\n\n");
printf("\nPulsa una tecla para empezar...");
getch();
				 //Busca una palabra aleatoriamente
do{

clrscr();
randomize();
acierto=0;
fallos=0;
longpalabra=0;
longadivina=0;
salir=0;
adivina=random(numpalabras-1)+1;

for (i=0;matriz[adivina][i]!='\0';i++)
{
plantilla[1][i]=0;
longpalabra++;
}

plantilla[1][i]='\0';

gotoxy(12,13);
printf("Palabra a adivinar: ");



//Presentamos la linea inicial punteada con tantos espacios como letras
for (i=0;matriz[adivina][i]!='\0';i++)
{
printf(" _ ");
}
do
{

gotoxy(10,15);
printf("Introduce una letra: "); scanf("%s",&letra);


gotoxy(12,13);
printf("Palabra a adivinar: ");

for (i=0;matriz[adivina][i]!='\0';i++)
{
if (matriz[adivina][i]==letra[0]){

plantilla[1][i]=1;
printf(" %c ",matriz[adivina][i]);
acierto=1;
}else{
if (plantilla[1][i]==1){
printf(" %c ",matriz[adivina][i]);
}else{
printf(" _ ");
}
}
}


gotoxy(21,21);
printf("Letras cogidas: ");
abecedario[abc]=letra[0];
x++;

gotoxy(x,y);
printf("%c",abecedario[abc]);
abc++;


longadivina=0;

for (j=0;plantilla[1][j]!='\0';j++){

if (plantilla[1][j]==1)
longadivina=longadivina+plantilla[1][j];
}

acierto=0;
if (fallos==9){
salir=1;}
if (longadivina==longpalabra) {
salir=1;}
}
while (salir==0);
if (fallos==9)
{
gotoxy(35,5);
printf("LO SIENTO...... No acertaste.");
gotoxy(35,7);
printf("La palabra era ");puts(matriz[adivina]);
gotoxy(35,9);
printf("�Quieres intentarlo otra vez?(s/n) ");
repetir=getch();
}else{
gotoxy(35,5);
printf("���FELICIDADES!!! Acertaste!!");
gotoxy(35,7);
printf("�Quieres intentarlo otra vez?(s/n) ");
repetir=getch();
}
}
while (repetir=='s');
}
