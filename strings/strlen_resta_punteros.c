/* kyr5-03b: strlen, longitud de cadena; resta de punteros */
#include <stdio.h>

int strlen(char *);

void main()
{

  printf("\n\nLongitud de cadenas; usa resta de punteros.\n");

  printf("por pasaje de la cadena, largo: ");
  printf("%d\n", strlen("Esta cadena tiene largo 26"));

}

/* strlen: devuelve la longitud de una cadena de caracteres */
int strlen(char *s)
{
  char *p = s;          /* s puntero al principio */
  while (*p != '\0')    /* p puntero al final */
    p++;
  return p - s;		/* la resta de punteros es el largo */
}
