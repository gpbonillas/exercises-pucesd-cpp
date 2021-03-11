#include <stdio.h>

// Paso de par�metros por valor.
// En este ejemplo, esta funci�n no tendr� el efecto deseado, porque las variables
// del programa principal no se ver�n afectadas.
void intercambiar1(int a, int b)
{
     int tmp = a;
	  a = b;
     b = tmp;
}

// Paso de par�metros por referencia, sintaxis 1.
// Esta funci�n s� que consigue intercambiar los valores de las variables
// del programa principal.
void intercambiar2(int *a, int *b)
{
     int tmp = *a;
     *a = *b;
     *b = tmp;
}

// Paso de par�metros por referencia, sintaxis 2.
// Esta funci�n tambi�n consigue su objetivo. A todos los efectos,
// es id�ntica a la funci�n anterior, �pero es c�digo en C++!
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
    printf("Despu�s de intercambiar1: dato1 = %i, dato2 = %i\n", dato1, dato2);
    intercambiar2(&dato1, &dato2);
    printf("Despu�s de intercambiar2: dato1 = %i, dato2 = %i\n", dato1, dato2);
    intercambiar3(dato1, dato2);
    printf("Despu�s de intercambiar3: dato1 = %i, dato2 = %i\n", dato1, dato2);
    return 0;
}