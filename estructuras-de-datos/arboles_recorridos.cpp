#include "conio.h"
#include "stdio.h"
#include "iostream.h"


class nodo{
public :
   int dato;
   nodo *izq;
   nodo *der;

} *raiz=NULL;

void insertar (nodo **aux, int elem){
  if (*aux== NULL){
     nodo * nuevo;
     nuevo = new nodo();
     nuevo->dato = elem;
     nuevo->izq = NULL;
     nuevo->der = NULL;
     *aux = nuevo;

  }
  else if ((*aux)->dato < elem)
      insertar(&(*aux)->der, elem);
  else
     if ((*aux)->dato > elem)
      insertar(&(*aux)->izq, elem);
}

void preorden(nodo *aux){
  if (aux!=NULL){
	  cout << aux->dato << endl;
	  preorden(aux->izq);
	  preorden(aux->der);
  }
}

void inorden(nodo *aux){
  if (aux!=NULL){
	  inorden(aux->izq);
	  cout << aux->dato << endl;
	  inorden(aux->der);
  }
}

void postorden(nodo *aux){
  if (aux!=NULL){
	  postorden(aux->izq);
	  postorden(aux->der);
	  cout << aux->dato << endl;
  }
}

void main(){
  clrscr();
  int i, v[17]={20,15,21,19,8,50,75,46,31,13,16,18,26,28,0,2,1};

  for (i=0;i<17;i++){
    insertar(&raiz,v[i]);
  }

  cout << "se ingreso 10-30-20"<< endl;
  cout << "----------------------------------------- "<< endl;
  cout << "PRE-ORDEN"<<endl;
  //preorden(raiz);
  cout << "----------------------------------------- "<< endl;
  cout << "IN-ORDEN"<<endl;
  inorden(raiz);
  cout << "----------------------------------------- "<< endl;
  cout << "POST-ORDEN"<<endl;
  //postorden(raiz);
  cout << "----------------------------------------- "<< endl;
  getch();
}
