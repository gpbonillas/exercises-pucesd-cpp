/* kyr5-07.c: ordena l¡neas de texto, con arreglo de punteros */
#include <stdio.h>
#include <string.h>
#include <alloc.h>

#define MAXLINEAS 5000		/* m xima cantidad de l¡neas */

char *ptr_lineas[MAXLINEAS];	/* arreglo de punteros a l¡neas de texto */

int leelineas(char *ptr_lineas[], int nlineas);
void escrlineas(char *ptr_lineas[], int nlineas);

void qsort(char *ptr_lineas[], int izq, int der);

int main()
{
  int nlineas;		/* cantidad de l¡neas de entrada le¡das */

  if ((nlineas = leelineas(ptr_lineas, MAXLINEAS)) >= 0) {
    qsort(ptr_lineas, 0, nlineas - 1);
    escrlineas(ptr_lineas, nlineas);
    return 0;
    }
  else {
    printf("error: entrada demasiado grande para ordenar\n");
    return 1;
    }
}


#define MAXLARGO 1000	/* m xima longitud de una l¡nea de entrada */
int getline(char *, int);
/* char *alloc(int) */


/* leelineas: lee l¡neas de la entrada */
int leelineas(char *ptr_lineas[], int maxlineas)
{
  int lgo, nlineas;
  char *p, linea[MAXLARGO];

  nlineas = 0;
  while ((lgo = getline(linea, MAXLARGO)) > 0)
    if (nlineas >= maxlineas ||         /* demasiadas l¡neas */
	(p = malloc(lgo)) == NULL)	/* no hay espacio para l¡nea */
      return -1;	/* valor de error */
    else {
      linea[lgo -1] = '\0';   /* elimina caracter nueva l¡nea */
      strcpy(p, linea);
      ptr_lineas[nlineas++] = p;        /* asigna l¡nea al arreglo */
    }
  return nlineas;
}


/* escribe las l¡neas una vez ordenadas */
void escrlineas(char *ptr_lineas[], int nlineas)
{
  int i;

  for (i = 0; i < nlineas; i++)
    printf("%s\n", ptr_lineas[i]);
}


/* getline: lee una linea en s, devuelve su longitud */
int getline(char s[], int lim)
{
  int c, i;
  for (i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n'){
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

/* qsort: ordena v[izq]..v[der] en orden ascendente */
void qsort(char *v[], int izq, int der)
{
  int i, ultimo;
  void swap(char *v[], int i, int j);

  if (izq >= der)	/* vuelve al encontrarse los extremos */
    return;
  swap(v, izq, (izq + der) / 2);
  ultimo = izq;
  for ( i = izq + 1; i <= der; i++)
    if (strcmp(v[i], v[izq]) < 0)
      swap(v, ++ultimo, i);
  swap(v, izq, ultimo);
  qsort(v, izq, ultimo -1);
  qsort(v, ultimo + 1, der);
}

/* swap: intercambia v[i] con v[j] */
void swap(char *v[], int i, int j)
{
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}




