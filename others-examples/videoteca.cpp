# include <iostream.h>
# include <stdlib.h>
# include <conio.h>
# include <alloc.h>
# include <stdio.h>


struct video {
	char nombre [20], telefono [12], direccion [25], pelicula[25], codpel[15];

	struct video *siguiente;
	};

struct video *primero, *ultimo;

void mostrar_menu() {
	gotoxy(20,1);
  	printf("*** V I D E O T E C A   P U C E ***");
	gotoxy(30,5);
  	printf("1.-I N T R O D U C I R    D A T O S");
  	gotoxy(30,8);
  	printf("2.-I M P R E S I O N   D E    D A T O S");
  	gotoxy(30,11);
  	printf("3.-S A L I R");
  	gotoxy(30,15);
  	printf("ELIJA LO DESEADO: "); fflush(stdout);  //

}

void anadir_elemento (){
	struct video *nuevo;
	nuevo = (struct video *) malloc (sizeof(struct video));

	if (nuevo==NULL) printf ("no hay memoeria disponible!!\n");

	gotoxy(20,1);
	printf("*** N U E V O    C L I E N T E ***\n\n");

	printf("Nombre: "); fflush(stdout);
	gets (nuevo->nombre);    //operador de seleccion

	printf("Direccion: "); fflush(stdout);
	gets (nuevo->direccion);    //operador de seleccion

	printf("Telefono: "); fflush(stdout);
	gets (nuevo->telefono);    //operador de seleccion

	printf("Pelicula alquilada: "); fflush(stdout);
	gets (nuevo->pelicula);    //operador de seleccion

	printf("Codigo de la pelicula: "); fflush(stdout);
	gets (nuevo->codpel);    //operador de seleccion

       
	nuevo->siguiente=NULL;

	if(primero==NULL){
	printf ("Primer elemento\n");
	primero=nuevo;
	ultimo=nuevo;
	}

	else {
	ultimo->siguiente=nuevo;
	ultimo=nuevo;
	}
}                                                                   
void mostrar_lista(){
	struct video *auxiliar;
	int i=0;
	auxiliar=primero;
	gotoxy(20,1);
	printf("*** I N F O RM A C I O N    D E    C L I E N T E ***\n\n");

	while (auxiliar!=NULL){
		printf(" Cliente: %s\n Direccción: %s\n Telefono: %s\n Pelicula Alquilada: %s\n Codigo de la Pelicula: %s \n\n\n",auxiliar->nombre,auxiliar->telefono,auxiliar->direccion,auxiliar->pelicula, auxiliar->codpel);
		auxiliar=auxiliar->siguiente;
		endl;
		i++;
	}
	if (i==0) printf ("\n La lista esta vacia!! \n");

}


void main(){
	char opcion;

	primero=(struct video *) NULL;
	ultimo=(struct video *) NULL;

	do {
		clrscr();
		mostrar_menu();
		opcion=getch();
			switch (opcion) {
				case '1':
					clrscr();
					anadir_elemento();
					break;

				case '2':
					clrscr();
					mostrar_lista();
                                        getche();
					break;
				
				case '3': exit (1);

				
				default: printf ("Opcion no valida!!!\n");
                                getche();
					break;
			}
		}while(opcion!='3');
}
















                                      