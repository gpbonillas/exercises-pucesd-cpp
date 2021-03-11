/* kyr5-05.c: strcpy, copia cadenas de caracteres */
#include <stdio.h>

void strcpy1(char *s, char *t);
void strcpy2(char *s, char *t);
void strcpy3(char *s, char *t);
void strcpy4(char *s, char *t);

void main()
{
  char a[] = "Esta es la cadena a copiar";
  char s1[50], s2[50], s3[50], s4[50];

  printf("\n\nCopia de cadenas.\n");
  printf("cadena original: %s\n", a);

  strcpy1(s1, a);
  printf("  con sub¡ndices; cadena copiada: %s\n", s1);

  strcpy2(s2, a);
  printf("  1a. con punteros; cadena copiada: %s\n", s2);

  strcpy3(s3, a);
  printf("  2a. con punteros; cadena copiada: %s\n", s3);

  strcpy4(s4, a);
  printf("  3a. con punteros; cadena copiada: %s\n", s4);

}

/* strcpy1: copia cadena t hacia s; con sub¡ndices */
void strcpy1(char *s, char *t)
{
  int i;

  i = 0;
  while ((s[i] = t[i]) != '\0')		/* copia y compara */
    i++;
}


/* strcpy2: copia cadena t hacia s; con punteros versi¢n 1 */
void strcpy2(char *s, char *t)
{
  while ((*s = *t) != '\0') {		/* copia y compara */
    s++;			/* avanza puntero en s */
    t++;			/* avanza puntero en t */
    }
}

/* strcpy3: copia cadena t hacia s; con punteros versi¢n 2 */
void strcpy3(char *s, char *t)
{
  while ((*s++ = *t++) != '\0')		/* copia, avanza, y compara */
    ;					/* proposici¢n vac¡a */
}

/* strcpy4: copia cadena t hacia s; con punteros versi¢n 4 */
void strcpy4(char *s, char *t)
{
  while ((*s++ = *t++))		/* copia y avanza mientras <> 0 */
    ;				/* proposici¢n vac¡a */

    /* se prefiere la versi¢n anterior, que mantiene
       la comparaci¢n expl¡cita != '\0' en el while  */
}

