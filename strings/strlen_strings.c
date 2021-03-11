/* kyr5-03a: strlen, longitud de cadena */
#include <stdio.h>

int strlen(char *);

void main()
{
  char arr[] = "Esta cadena tiene largo 26";
  char *p_arr = &arr[0];

  printf("\n\nLongitudes de cadenas.\n");

  printf("por pasaje de la cadena, largo: ");
  printf("%d\n", strlen("Esta cadena tiene largo 26"));

  printf("por pasaje de arreglo, largo: ");
  printf("%d\n", strlen(arr));

  printf("por pasaje de puntero, largo: ");
  printf("%d\n", strlen(p_arr));

}

/* strlen: devuelve la longitud de una cadena de caracteres */
int strlen(char *s)
{
  int n;
  for (n = 0; *s != '\0'; s++)
    n++;
  return n;
}
