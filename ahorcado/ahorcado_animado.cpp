#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 
#define N 12
char txt[9];
char datos[N][9]={
"anteojo","avioneta","zapallo","martir",
"espejo","anzuelo","heciano","tripode",
"insecto","agujero","carnada","cabeza"};
 
char dibuj[9][7]={
  "____",
  "|  |",
  "|  |",
  "|",
  "|",
  "|",
  "|",
  "|",
  "------"
};
 
struct pst{
  int pos;
  char part[5];
}parts[7]={{3,"  O"},{4," /"},{4,"|"},
{4,"\\"},{5,"  |"},{6," /"},{6," \\"}};
 
int main(int argc, char *argv[])
{
  int n,m,o,p,i,j,r,eq=0;char lc,tmp[10];
 
  srand(time(NULL));
  o=rand()%N;
 
  m=strlen(datos[o]);p=m-2;
 
  txt[0]=datos[o][0];txt[m-1]=datos[o][m-1];
  for(n=1;n<m-1;n++)txt[n]='_';txt[m]=0;
  printf("Ahorcatesss!!! Vr. 1.0\n\n");tmp[0]=0;
  for(i=0;i<9;i++)printf("%s\n",dibuj[i]);
 
  do{
 
    for(j=0;j<strlen(tmp);j++){
      lc=tmp[j];r=p;
      for(n=1;n<m-1;n++)
        if(datos[o][n]==lc){
          txt[n]=lc;datos[o][n]='_';p--;
        }
      if(r==p){
        strcat(dibuj[parts[eq].pos],parts[eq].part);
        eq++;
      }
      for(i=0;i<9;i++)printf("%s\n",dibuj[i]);
    }
 
    if(eq>=7)break;
 
    if(p>0){
      printf("\nPalabra: %s - Ingrese 1 letra (* para terminar): ",txt);
      scanf("%10s",&tmp);
    }lc=tmp[0]; 
    system("cls");
  }while(lc!='*'&&p);
 
  if(!p)printf("\nPalabra: %s - Ganaste cara de Naco!!!\n\n",txt);
  else if(eq>=7)printf("\nJAJA!!! Loooooser!!!\n\n");
  else printf("\nK c's Papá??? Recatate!!!\n\n");
 
  system("PAUSE");	
  return 0;
}