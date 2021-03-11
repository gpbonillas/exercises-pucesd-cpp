/* vgb5-01.c punteros: asignacion, derreferencia, arreglos */

#include <stdio.h>

void main()
{
  int x = 1, y = 2, z[10];
  int *ip;	/* ip es puntero a entero */

  printf("\n\n\n\nPRUEBA DE PUNTEROS.\n");
  printf("Valores iniciales: x=%d, y=%d\n", x, y);
  printf("direcci¢n de memoria inicial en puntero ip=%u\n", ip);
  printf("basura en derreferencia *ip=%u\n", *ip);
  printf("basura en z: %d, %d, %d, %d\n\n", z[0], z[1], z[2], z[3]);

  ip = &x;	/* ip apunta a x; *ip da el valor de x */
  printf("Asignaci¢n ip = &x\n");
  printf("puntero ip apunta a x; ip=%u; x=%d; *ip=%d\n\n", ip, x, *ip);

  y = *ip;	/* y es ahora 1 */
  *ip = 0;	/* x es ahora 0 */
  printf("Asignaciones y = *ip, *ip = 0\n");
  printf("y=%d;  x=%d\n\n", y, x);

  z[0] = 100;	/* z[0] asignado directamente */
  ip = &z[0];
  printf("Asignaciones z[0] = 100, ip = &z[0]\n");
  printf("ip puntero a z:  ip=%u, ip+1=%u, ip+2=%u, ip+3=%u\n", \
    ip, ip+1, ip+2, ip+3);
  printf("z[0]=%d; *z=%d\n\n", z[0], *z);

  *ip = 100;
  *(ip+1) = 110;
  *(ip+2) = 120;
  *(ip+3) = 130;
  printf("Asignaci¢n de z incrementando el puntero\n");
  printf("contenido de z:  "\
    "*ip=%d, *(ip+1)=%d, *(ip+2)=%d, *(ip+3)=%d\n\n", \
    *ip, *(ip+1), *(ip+2), *(ip+3));

  getchar();
}
