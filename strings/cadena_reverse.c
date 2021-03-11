/* tim2-03.c: inversion de cadena de caracteres */
#include <stdio.h>

void main()
{
char str[10];
int i;

printf("Ingrese cadena: ");
for (i = 0; i <= 9 ; i++) {
  *(str + i) = getchar();
  if ( *(str + i) == '\n' || *(str + i) == EOF ) {
    ungetch();
    break;
  }
}
printf("Cadena invertida: ");
for (; i >= 0; i--)
  printf("%c", *(str + i));

printf("\n");

}
