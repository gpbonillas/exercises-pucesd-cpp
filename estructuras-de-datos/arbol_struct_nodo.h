typedef struct nodo{
	int dato;
	struct nodo *izq;
	struct nodo *der;
	} NODOARBOL;

void insertar(NODOARBOL **cabeza, int elemento){

     if(*cabeza==NULL){
	*cabeza= (NODOARBOL *) malloc(sizeof(NODOARBOL));

	if(*cabeza==NULL){
	   printf("No hay memoria\n");
	   return;
	   }

	(*cabeza)->dato=elemento;
	(*cabeza)->izq=NULL;
	(*cabeza)->der=NULL;
       }

     else if(elemento< (*cabeza)->dato) insertar(& (*cabeza)->izq, elemento);

     else if(elemento> (*cabeza)->dato) insertar(& (*cabeza)->der, elemento);

     else{ printf("\nNo puede insertar: valor duplicado\n\n");
	   getch(); }
}

void inorder(NODOARBOL *cabeza){
     if(cabeza!=NULL){
	inorder(cabeza->izq);
	printf("%d ",cabeza->dato);
	inorder(cabeza->der);
     }
}


void preorder(NODOARBOL *cabeza){
     if(cabeza!=NULL){
	printf("%d ", cabeza->dato);
	preorder(cabeza->izq);
	preorder(cabeza->der);
     }
}


void postorder(NODOARBOL *cabeza){
     if(cabeza!=NULL){
	postorder(cabeza->izq);
	postorder(cabeza->der);
	printf("%d ",cabeza->dato);
     }
}


void buscar(NODOARBOL *cabeza, int elemento, int *valor){
    if(cabeza!=NULL){
       if((cabeza)->dato==elemento) *valor=1;

       else{
	    if(elemento<(cabeza)->dato) buscar((cabeza)->izq, elemento, valor);

	    else buscar((cabeza)->der, elemento, valor);
	    }
    }
    else{ printf("\nDato no encontrado\n");
	  getch(); }
}

NODOARBOL *eliminar(NODOARBOL *cabeza, int elemento){
	     NODOARBOL *p1, *p2;

	     if(elemento==cabeza->dato){
		if(cabeza->izq==cabeza->der){
		   free(cabeza);
		   return(NULL);
		}

		else if(cabeza->izq==NULL){
		   p1=cabeza->der;
		   free(cabeza);
		   return(p1);
		}

		else if(cabeza->der==NULL){
		   p1=cabeza->izq;
		   free(cabeza);
		   return(p1);
	       }

	       else{
		   p2=cabeza->der;
		   p1=cabeza->der;
		   while(p1->izq) p1=p1->izq;
		   p1->izq=cabeza->izq;
		   free(cabeza);
		   return(p2);
	       }
	     }

	     if(cabeza->dato<elemento) cabeza->der=eliminar(cabeza->der, elemento);
	     else cabeza->izq=eliminar(cabeza->izq, elemento);
	     return(cabeza);
}

void dibujar(NODOARBOL *cabeza, int a, int b, int c, int d){
     char value[3];
     if(cabeza!=NULL){
	itoa(cabeza->dato,value,10);
	circle(300+a,75+b,14);
	setcolor(YELLOW); outtextxy(295+a,75+b,value); setcolor(WHITE);

	if(d==1) line(300+a+pow(2,c+1),b+14,300+a,61+b);
	else if(d==2) line(300+a-pow(2,c+1),b+14,300+a,61+b);

	dibujar(cabeza->izq,a-pow(2,c)-pow(2,d-4),b+75,c-1,1);
	dibujar(cabeza->der,a+pow(2,c)+pow(2,d-4),b+75,c-1,2);}
}