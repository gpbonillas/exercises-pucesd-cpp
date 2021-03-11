#include <stdio.h>

// Paso de parámetros por valor.
// En este ejemplo, esta función no tendrá el efecto deseado, porque las variables
// del programa principal no se verán afectadas.
void intercambiar1(int a, int b)
{
     int tmp = a;
	  a = b;
     b = tmp;
}

// Paso de parámetros por referencia, sintaxis 1.
// Esta función sí que consigue intercambiar los valores de las variables
// del programa principal.
void intercambiar2(int *a, int *b)
{
     int tmp = *a;
     *a = *b;
     *b = tmp;
}

// Paso de parámetros por referencia, sintaxis 2.
// Esta función también consigue su objetivo. A todos los efectos,
// es idéntica a la función anterior, ¡pero es código en C++!
void intercambiar3(int &a, int &b)
{
     int tmp = a;
     a = b;
     b = tmp;
}

// Programa principal
int main()
{
    int dato1 = 30, dato2 = 90;
    printf("Antes de la llamada a las funcioens: dato1 = %i, dato2 = %i\n", dato1, dato2);
    intercambiar1(dato1, dato2);
    printf("Después de intercambiar1: dato1 = %i, dato2 = %i\n", dato1, dato2);
    intercambiar2(&dato1, &dato2);
    printf("Después de intercambiar2: dato1 = %i, dato2 = %i\n", dato1, dato2);
    intercambiar3(dato1, dato2);
    printf("Después de intercambiar3: dato1 = %i, dato2 = %i\n", dato1, dato2);
    return 0;
}