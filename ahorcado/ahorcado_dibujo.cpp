
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FALLOS_MAXIMO   6
#define ENTRADA_LONG  16

enum boolean {FALSE, TRUE};

/* Conjunto de palabras */
char *palabras[] = {"baloncesto", "tenis de mesa", "programador"};

/* Dibujo del ahorcado */
char dibujo [9][9];

void inicializar_dibujo      (void);
void seleccionar_palabra   (char **oculta, char **verdadera);
int  validar_entrada          (char entrada[]);
void interfaz                   (char **oculta, char **verdadera, char caracter, char buffer[][1]);
void inicializar_buffer    (char buffer[][1]);
void mostrar_info               (char *oculta, int intentos, char buffer[][1]);
int esta                            (char caracter, char *original);
int acabado                        (char *oculta, char *original);
void mostrar_dibujo            (void);
void actualizar_dibujo       (int intentos);

int main()
{
      char *oculta;
      char *original;
      int valido;
      char buffer[26][1];
      int intentos = 0;
      char entrada[ENTRADA_LONG];

      /* Inicializar dibujo */
      inicializar_dibujo ();

      /* Buffer de caracteres ingresados */
      inicializar_buffer (buffer);

      seleccionar_palabra (&oculta, &original);

      while (intentos < FALLOS_MAXIMO)
      {
            valido = FALSE;
				interfaz (&oculta, &original, entrada[0], buffer);
            
            while (!valido)
				{

                  mostrar_dibujo();

                  mostrar_info (oculta, intentos, buffer);
            
                  if (acabado (oculta, original))
						{
                     puts ("\nHa ganado!!");
							return 0;
                  }

                  /* Pedimos entrada */
                  fgets (entrada, ENTRADA_LONG, stdin);
                  valido = validar_entrada (entrada) ;

                  if (!valido)
                  {   
                     puts ("Caracter no permitido, pulsa <INTRO> para continuar");
                     getchar();
                  }
                  else
                  {
                     /* Si fallamos se incrementa en contador de fallos y
                      * se actualiza el dibujo */
                     if (!esta (entrada[0], original))
                     {
                           intentos++;
                           actualizar_dibujo (intentos);
                     }
                  }
            }
      }
      /* Imprimimos solucion */
      printf ("\nFallaste, la palabra era \"%s\"\n", original);
      
      return 0;
}

void actualizar_dibujo (int intentos)
{
      switch (intentos)
      {
            case 1 :   dibujo[2][7] = 'O';
                           break;
            case 2 :   dibujo[3][7] = '|';
                           dibujo[4][7] = '|';
                           break;
            case 3:      dibujo[3][6] = '/';
                           break;
            case 4:      dibujo[3][8] = '\\';
                           break;
            case 5:      dibujo[5][6] = '/';
                           break;
            case 6:      dibujo[5][8] = '\\';
                           break;
      }
}

/* Mostramos al monigote */
void mostrar_dibujo (void)
{
      int i,j;

      for (i = 0; i < 9; i++)
      {
            printf ("\n");
            for (j = 0; j < 9; j++)
                  printf ("%c", dibujo[i][j]);
      }
      printf ("\n");
}

/* Iniciar monigote */
void inicializar_dibujo (void)
{
      int i,j;

      for (i = 0; i < 9; i++)
            for (j = 0; j < 9; j++)
                  dibujo[i][j] = ' ';

      for (i = 1; i < 8; i++)
            dibujo[i][1] = '|';

      for (j = 1; j < 8; j++)
            dibujo[1][j] = '_';

      dibujo[7][2] = '_';
      dibujo[7][3] = '_';

}

/* Verifica si el juego ha terminado */
int acabado (char *oculta, char *original)
{
      int fin = FALSE;

      if (strcmp(oculta, original) == 0)
            fin = TRUE;   
      return fin;
}

/* Verifica si un caracter esta en la palabra */
int esta (char caracter, char *original)
{
      int i;
      int localizado = FALSE;

      for (i = 0; (i < strlen(original)) && !localizado; i++)
            if (caracter == original[i])
                  localizado = TRUE;
      return localizado;
}


/* Mostramos la palabra oculta, los intentos, los caracteres ingresados ..*/
void mostrar_info (char *oculta, int intentos, char buffer[][1])
{
      char i;
   
      /* Mostramos palabra oculta */
      printf ("\n\t");
      puts (oculta);
   
      /* Mostramos caracteres ingresados */
      printf ("\n\nCaracteres ingresados: ");
      for (i = 'a'; i <= 'z'; i++)
      {
            if (buffer[i][0] == TRUE)
                  printf ("%-2c", i);
      }
      
      /* Mostramos los intentos fallidos */
      printf ("\nIntentos: %d\n", intentos);
      printf ("Ingresa caracter: ");
}

/* Buffer de caracteres ingresados */
void inicializar_buffer (char buffer[][1])
{
      char i;
      for (i = 'a'; i <= 'z'; i++)
            buffer[i][0] = FALSE;
}


void seleccionar_palabra (char **oculta, char **verdadera)
{
      int i;
      int opcion;

      /* Palabra al azar */
      srand (time(NULL));
      opcion = rand() % 3;

      /* Ocultamos palabra */
      *oculta = (char*) calloc (strlen(palabras[opcion]) + 1, sizeof(char));
      strcpy (*oculta, palabras[opcion]);
      
      for (i = 0; i < strlen(*oculta); i++)
      {
            if ((palabras[opcion])[i] != ' ')
               (*oculta)[i] = '-';
      }

      /* La palabra original */
      *verdadera = (char*) calloc (strlen(palabras[opcion]) + 1, sizeof(char));
      strcpy (*verdadera, palabras[opcion]);
}
      


int validar_entrada (char entrada[])
{
      if (isalpha(entrada[0]) && (strlen(entrada) == 2))
            return TRUE;
      else
            return FALSE;
}

/* Sustituye el caracter en la palabra */
void interfaz (char **oculta, char **verdadera, char caracter, char buffer[][1])
{
      int i;
      
      if (buffer[caracter][0] == TRUE)
      {
            puts ("Caracter ya ingresado, pulsa <INTRO> para continuar");
            getchar();
      }

      /* Sustituimos caracter */
      for (i = 0; i < strlen(*verdadera); i++)
      {
            if (caracter == (*verdadera)[i])
            {
                  (*oculta)[i] = caracter;
            }
      }

      /* Marcamos caracter en el buffer de caracteres ingresados */
      buffer[caracter][0] = TRUE;
}