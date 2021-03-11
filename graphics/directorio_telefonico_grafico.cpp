#include stdio.h
#include conio.h
#include ctype.h
#include string.h
#include stdlib.h

 struct DIREC{
 char    nombre[35];
 char    tele[20];
} ;

FILE *pack(FILE *a);
void ordena(FILE *a);
void consulta2(FILE *a);
long busca_Clave2(FILE *a,char buscado[]);
void lee(FILE *a);
void imprime(FILE *a);

void main(){

 char   opcion;
 FILE *archivo;
 archivo=fopen ("TELE.DAT","rb+");   /* usar opción "wb+" para crear el archivo .DAT y después cambiar a "rb+" */

 while(1){
  clrscr();
  textattr(6+5*5);
  clrscr();
  textcolor(YELLOW);
  cprintf("                            DIRECTORIO TELEFONICO");
  printf("\n\n");
  cprintf("          N");
  printf("uevo");
  textcolor(YELLOW);
  cprintf("     L");
  printf("ista");
  textcolor(YELLOW);
  cprintf("     B");
  printf("aja");
  textcolor(YELLOW);
  cprintf("     C");
  printf("onsulta");
  textcolor(YELLOW);
  cprintf("     O");
  printf("rdena");
  textcolor(YELLOW);
  cprintf("     S");
  printf("alir");

  gotoxy(1,25);
  printf("          *** PRESIONE LA LETRA RESALTADA PARA ESCOGER LA OPCION ***");
  gotoxy(1,4);
  opcion=toupper(getch());

  if(opcion=='S')
  break;
  switch(opcion){
 case 'N':{
  lee(archivo);
  break;
 }
 case 'L':{
  imprime(archivo);
  break;
 }
 case 'B':{
  pack(archivo);
  break;
 }
 case 'C':{
  consulta2(archivo);
  break;
 }
 case 'O':{
  ordena(archivo);
  break;
 }
  }
 }
 clrscr();
 fclose (archivo);
 normvideo();
 clrscr();
}

/*********************************************************************/

void imprime(FILE *a){
 int r,y=0,c=1;
 struct DIREC reactivo;
 clrscr();
 textcolor(YELLOW);
 cprintf("NOMBRE                                     TELEFONO");
 normvideo();
 rewind(a);
  while(1){
 r=fread(&reactivo,sizeof(struct DIREC),1,a);
 if(r==0)
  break;

   if((c%2)!=0){
   textattr(6+5*5);
  /* textcolor(LIGHTGRAY);*/
   printf("\n");
   cprintf("%d.- %-30s %16s",c,reactivo.nombre,reactivo.tele);
   normvideo();
  }
  else{
   textattr(6+5*4);
 /*  textcolor(WHITE);*/
   printf("\n");
   cprintf("%d.- %-30s %16s",c,reactivo.nombre,reactivo.tele);
   normvideo();
  }

   if(y==23){
   getch();
   y=0;
  }
    y++;
    c++;
 }
    getch();
}


/*********************************************************************/

void lee(FILE *a){
 struct DIREC reactivo;
 printf("\n\n");

  fflush(stdin);
  printf("Nombre    : ");strupr(gets(reactivo.nombre));
 if(strlen(reactivo.nombre)<30){

 if(busca_Clave2(a,reactivo.nombre)==0){
 printf("Tel‚fono  : ");gets(reactivo.tele);
  fseek(a,0,SEEK_END);
  fwrite (&reactivo,sizeof(struct DIREC),1,a);
   }
   else{
    printf("\n\nYa existen esos datos!!!");
    getch();
   }
  }
   else{
    printf("\n\nM ximo 25 letras por nombre...");
    printf("\n\n­­­El programa puede da¤arse si repite este error!!!");
    getch();
 }
}

/*********************************************************************/

 long busca_Clave2(FILE *a,char buscado[]){
  long p;
  struct DIREC r;
  rewind(a);
 while(1){
  if(fread(&r,sizeof(struct DIREC),1,a)==0)
  break;
   if(strcmp(r.nombre,buscado)==0){
   p=ftell(a)/sizeof(struct DIREC);
   return(p);
 }
  }
 return 0;
 }

/*********************************************************************/

 void consulta2(FILE *a){
  char nombre[30];
  long p;
  struct DIREC r;
 printf("\n\nDame el nombre a buscar: ");
 strupr(gets(nombre));

 p=busca_Clave2(a,nombre);

  if(p!=0){

  fseek(a,(p-1)*sizeof(struct DIREC),SEEK_SET);
  fread(&r,sizeof(struct DIREC),1,a);
  printf("\n\n\n");
  textcolor(LIGHTGRAY);
  cprintf("NOMBRE                                     TELEFONO");
  normvideo();
  printf("\n%-20s %30s",r.nombre,r.tele);
   getch();

  }
 else{
  printf("\n\nLa informaci¢n solicitada no existe ...");
  getch();
 }
  }

/*********************************************************************/

 void ordena(FILE *a){
  int i=0,j=0,s,t;
  struct DIREC r;
  struct DIREC temp[100];
  struct DIREC temporal;
  while(1){
  fseek(a,i*sizeof(struct DIREC),SEEK_SET);
  if(fread(&r,sizeof(struct DIREC),1,a)==0)
  break;
   temp[j]=r;
   i++;
   j++;
  }
   for(s=0;s0){
   temporal=temp[s];
   temp[s]=temp[t];
   temp[t]=temporal;
    }

   s=0;
   i=0;
   while(1){
    if(s>=j)
    break;
   r=temp[s];
   fseek(a,i*sizeof(struct DIREC),SEEK_SET);
   fwrite (&r,sizeof(struct DIREC),1,a);
   s++;
   i++;
    }
   printf("\n\nSus archivos han sido ordenados alfab‚ticamente...");
   getch();

  }


/*********************************************************************/

 FILE *pack(FILE *a){
  int i=0;
  long p;
  char clave[30];
  struct DIREC r;
  FILE *t;
  t=fopen ("TMP.DAT","wb");

 printf("\n\nDame el nombre a dar de baja: ");
 strupr(gets(clave));
 p=busca_Clave2(a,clave);

 if(p!=0){
 while(1){
  fseek(a,i*sizeof(struct DIREC),SEEK_SET);
  if(fread(&r,sizeof(struct DIREC),1,a)==0)
  break;
   if(strcmp(r.nombre,clave)!=0){
   fseek(a,i*sizeof(struct DIREC),SEEK_SET);
   fwrite (&r,sizeof(struct DIREC),1,t);
  }
   i++;
 }
  fclose (t);
  fclose (a);
  remove("TELE.DAT");
  rename("TMP.DAT","TELE.DAT");
   t=fopen ("TELE.DAT","rb+");
     printf("\n\nLa informaci¢n solicitada ha sido dada de baja...");
   getch();
  return(t);
  }
  else{
   printf("\n\nNo existe el nombre...");
   getch();
  }
   return 0;
}

/*********************************************************************/