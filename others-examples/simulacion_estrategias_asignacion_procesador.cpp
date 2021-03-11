/* Simulación de estrategias de asignación del procesador */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream.h>
#include <io.h>
FILE *textfile; /* Pointer al archivo usado */
// char regis[70]; /* Registro del archivo usado (para lectura) */
class Proc
{
  public:
  /* identif: identificación del proceso */
  char identif;
  /* fin: estado de finalización del proceso */
  /* 0: listo para ejecutar */
  /* 1: interrumpido p/ entrada / salida */
  /* 3: interrumpido p/ tiempo */
  /* 2: terminado */
  int fin;
  /* cuenta: total de ciclos de control asignados al proceso */
  int cuenta;
  /* pri: prioridad del proceso */
  int pri;
  /* nivel: identificación de la sub-cola donde est el proceso */
  int nivel;
  Proc()
  {
    identif = 0;
    fin = 0;
    cuenta = 0;
    pri = 0;
    nivel = 0;
  }; // Inicialización de valores.
};

class procesos
{
  public:
  int cc; // Número de ciclos de control.
  int np; // Número de procesos.
  char auxiden; // Variable auxiliar.
  int auxfin; // Variable auxiliar.
  int auxcuenta; // Variable auxiliar.
  int auxpri; // Variable auxiliar.
  int auxnivel; // Variable auxiliar.
  int cambio; // Variable auxiliar.
  Proc p[50]; // Vector (lista) de procesos.
  void inicio(); // Acciones iniciales.
  void introducir_datos(); // Carga de identificación de procesos.
  void mostrar(); // Mostrar lista de procesos.
  void fifo(); // Simulación según estrategia FIFO.
  void rrobin(); // Simulación según estrategia RR (Round Robin).
  void hrn(); // Simulación según estrategia HRN (Relación de Respuesta Máxima).
  void rnm(); // Simulación según estrategia RNM (Retroalimentación de Niveles Múltiples).
  void final(); // Acciones finales.
};

void procesos::inicio()
{
  cout << "*****************************************************";
  cout << "\n";
  cout << "*Estrategias de asignación del procesador a procesos*";
  cout << "\n";
  cout << "*en ejecución concurrente. *";
  cout << "\n";
  cout << "*****************************************************";
  cout << "\n";
  cout << "\n";
  cout << "Introduzca el número de ciclos de control de la simulación.";
  cout << "\n";
  cout << "(Se sugiere entre 30 y 40 por cada 10 procesos): ";cin >> cc;
  cout << "\n";
  cout << "Introduzca el número de procesos de la simulación.";
  cout << "\n";
  cout << "(El maximo permitido es 50): ";cin >> np;
  cout << "\n";
  if (np > 50)
  {
    np = 50;
    cout << "El número de procesos se ha limitado a 50. \n";
    cout << "\n";
  }
  /* Apertura del archivo usado para grabación */
  cout << "Apertura del archivo resumen ’PROCESOS.TXT’ para grabación. \n";
  cout << "(Carpeta BIN de la carpeta TC). \n";
  cout << "\n";
  if ((textfile = fopen("procesos.txt", "a")) == NULL)
  {
    printf("Error de apertura para grabación en el archivo ’procesos.txt’ \n");
    exit (0);
   }
}
void procesos::introducir_datos()
{
  char opc;
  cout << "\nSi desea introducir manualmente la identificación de los procesos \n";
  cout << "tipee: ’s’, de lo contrario: ’n’ y el sistema asumira las identificaciones. \n";
  cin >> opc;
  if (opc =='s')
  {
    for (register int i=0; i<np; i++)
    {
      cout << "Introduzca la identificación del proceso p[" <<i << "]: ";
      cin >> p[i].identif;
    }
  }
  else
  {
    p[0].identif = 'a';
    p[1].identif = 'b';
    p[2].identif = 'c';
    p[3].identif = 'd';
    p[4].identif = 'e';
    p[5].identif = 'f';
    p[6].identif = 'g';
    p[7].identif = 'h';
    p[8].identif = 'i';
    p[9].identif = 'j';
    p[10].identif = 'k';
    p[11].identif = 'l';
    p[12].identif = 'm';
    p[13].identif = 'n';
    p[14].identif = 'o';
    p[15].identif = 'p';
    p[16].identif = 'q';
    p[17].identif = 'r';
    p[18].identif = 's';
    p[19].identif = 't';
    p[20].identif = 'u';
    p[21].identif = 'v';
    p[22].identif = 'w';
    p[23].identif = 'x';
    p[24].identif = 'y';
    p[25].identif = 'z';
    p[26].identif = '1';
    p[27].identif = '2';
    p[28].identif = '3';
    p[29].identif = '4';
    p[30].identif = '5';
    p[31].identif = '6';
    p[32].identif = '7';
    p[33].identif = '8';
    p[34].identif = '9';
    p[35].identif = 'A';
    p[36].identif = 'B';
    p[37].identif = 'C';
    p[38].identif = 'D';
    p[39].identif = 'E';
    p[40].identif = 'F';
    p[41].identif = 'G';
    p[42].identif = 'H';
    p[43].identif = 'I';
    p[44].identif = 'J';
    p[45].identif = 'K';
    p[46].identif = 'L';
    p[47].identif = 'M';
    p[48].identif = 'N';
    p[49].identif = 'O';
  }
  for (register int i=0; i<np; i++)
  {
    p[i].fin = 0;
    p[i].cuenta = 0;
    p[i].pri = 0;
    p[i].nivel = 0;
  }
}

void procesos::mostrar()
{
  printf("\n");
  cout << "Listado de procesos:" <<"\n";
  cout << "********************" <<"\n";
  cout << "Estado: 0 -> Listo para ejecutar." <<"\n";
  cout << "Estado: 1 -> Interrumpido en espera de entrada / salida." <<"\n";
  cout << "Estado: 2 -> Proceso terminado." <<"\n";
  cout << "Estado: 3 -> Interrumpido por tiempo (no aplicable en FIFO ni en HRN)."<<"\n";
  for (register int i=0; i<np; i++)
  {
    cout <<"Proceso p[" <<i << "]: " << p[i].identif<< " Estado: "<< p[i].fin<< "Ciclos de control utilizados: "<< p[i].cuenta<< "\n";
    cout <<"Proceso p[" <<i << "]: " << p[i].identif<< " Prioridad: "<< p[i].pri<< "Nivel: "<< p[i].nivel;cout <<"\n";
  }
}

void procesos::fifo()
{
  auxiden = 0; auxfin = 0; auxcuenta = 0; cambio = 0;
  /* Grabación en el archivo usado */
  fprintf(textfile, "%s\n", "************************************************************");
  fprintf(textfile, "%s", "Simulacion FIFO con ");
  fprintf(textfile, "%i", cc);
  fprintf(textfile, "%s\n", " ciclos de control.");
  cout <<"\n";
  cout <<"Secuencia de selección de procesos para su ejecución según FIFO:";
  cout <<"\n";
  cout <<"****************************************************************";
  cout <<"\n";
  cout <<"Los procesos son atendidos según su orden en la lista de procesos listos:";
  cout <<"\n" <<"\n";
  for (register int j=0; j<cc; j++) // ***Realiza ’cc’ ciclos de control***
  {
    auxfin = 0;
    for (register int m=0; m<np; m++)
    {auxfin = auxfin + p[m].fin;}
    if (auxfin == (np * 2))
    {
      cout <<"\n"<< "Todos los procesos han finalizado en "<< j << " ciclos de control.\n";
      /* Grabación en el archivo usado */
      fprintf(textfile, "%s", "Todos los procesos han finalizado en ");
      fprintf(textfile, "%i", j);
      fprintf(textfile, "%s\n", "ciclos de control.");
      j = cc;
      auxfin = getch();
    }
    for (register int i=0; i<np; i++)
    {
      if (p[i].fin == 0)
      {
        cout <<"Procesador asignado al proceso: "<< p[i].identif;
        cout <<"\n";
        p[i].cuenta = p[i].cuenta + 1;
        p[i].fin = int(random(3)); // Determina próximo estado del proceso.
        // cout <<”\n” <<p[i].identif <<p[i].fin <<”\n”;
        if (p[i].fin == 1)
        cout <<"Proceso ’" <<p[i].identif <<"’ interrumpido por entrada / salida. "<< "\n";
	else
	{
	  if (p[i].fin == 2)
            cout <<"Proceso ’" <<p[i].identif <<"’ finalizado. "<< "\n";
        }
        if (p[i].fin > 0)
        { // Intercambio de contexto.
          cambio = cambio + 1;
          auxiden = p[i].identif;
          auxfin = p[i].fin;
          auxcuenta = p[i].cuenta;
          for (register int k=i; k<(np - 1); k++)
	  {
	    p[k].identif = p[k+1].identif;
            p[k].fin = p[k+1].fin;
            p[k].cuenta = p[k+1].cuenta;
          }
          p[(np - 1)].identif = auxiden;
          p[(np - 1)].fin = auxfin;
          p[(np - 1)].cuenta = auxcuenta;
        }
        i = np;
        auxfin = getch();
      }
      for (register int k=0; k<np; k++) // Determina si continúa la espera por entrada /
      {
        if (p[k].fin == 1) p[k].fin = int (random (2));
      }
    }
  }
  cout <<"\n"<< "***Se han producido "<< cambio<< "cambios de contexto.***"<<"\n";
  /* Grabación en el archivo usado */
  fprintf(textfile, "%s", "Se han simulado ");
  fprintf(textfile, "%i", np);
  fprintf(textfile, "%s\n", " procesos concurrentes.");
  fprintf(textfile, "%s", "Se han producido ");
  fprintf(textfile, "%i", cambio);
  fprintf(textfile, "%s\n", " cambios de contexto.");
  auxfin = getch();
}

void procesos::rrobin(){
auxiden = 0; auxfin = 0; auxcuenta = 0; cambio = 0;
/* Grabación en el archivo usado */
fprintf(textfile, "%s\n", "************************************************************");
fprintf(textfile, "%s", "Simulación RR - Round Robin con ");
fprintf(textfile, "%i", cc);
fprintf(textfile, "%s\n", " ciclos de control.");
cout <<"\n";
cout <<"Secuencia de selección de procesos para su ejecución según RR - Round Robin:";
cout <<"\n";
cout <<"****************************************************************************";
cout <<"\n";
cout <<"Los procesos son atendidos según su orden en la lista de procesos listos,\n";
cout <<"pero disponen de un tiempo limitado (cuantum) del procesador:";
cout <<"\n" <<"\n";
for (register int j=0; j<cc; j++) // ***Realiza ’cc’ ciclos de control***
{
  auxfin = 0;
  for (register int m=0; m<np; m++)
  {
    if (p[m].fin != 2)
    {
      auxfin = 1;
      m = np;
    }
  }
  if (auxfin == 0)
  {  
    cout <<"\n"<< "Todos los procesos han finalizado en "<< j << "ciclos de control.\n";
    /* Grabación en el archivo usado */
    fprintf(textfile, "%s", "Todos los procesos han finalizado en");
    fprintf(textfile, "%i", j);
    fprintf(textfile, "%s\n", " ciclos de control.");
    j = cc;
    auxfin = getch();
  }
  for (register int i=0; i<np; i++)
  {
    if (p[i].fin == 0)
    {
      cout <<"Procesador asignado al proceso: "<< p[i].identif;
      cout <<"\n";
      p[i].cuenta = p[i].cuenta + 1;
      p[i].fin = int(random(4)); // Determina próximo estado del proceso.
      // cout <<”\n” <<p[i].identif <<p[i].fin <<”\n”;
      if (p[i].fin == 0)
        p[i].fin = 3;
      if (p[i].fin == 1)
        cout <<"Proceso ’" <<p[i].identif <<"’ interrumpido por entrada / salida. "<< "\n";
      else
      {
        if (p[i].fin == 2)
          cout <<"Proceso ’" <<p[i].identif <<"’ finalizado. "<< "\n";
	else
	{
	  if (p[i].fin == 3)
            cout <<"Proceso ’" <<p[i].identif <<"’ interrumpido por tiempo. "<< "\n";
        }
      }
if (p[i].fin >= 0)
{ // Intercambio de contexto.
cambio = cambio + 1;
auxiden = p[i].identif;
auxfin = p[i].fin;
auxcuenta = p[i].cuenta;
for (register int k=i; k<(np - 1); k++)
{p[k].identif = p[k+1].identif;
p[k].fin = p[k+1].fin;
p[k].cuenta = p[k+1].cuenta;
}
p[(np - 1)].identif = auxiden;
p[(np - 1)].fin = auxfin;
p[(np - 1)].cuenta = auxcuenta;
}
i = np;
auxfin = getch();
}
for (register int k=0; k<np; k++) // Determina si continúa la espera por entrada /salida.
{if (p[k].fin == 1) p[k].fin = int (random (2));
}
for (register int l=0; l<np; l++) // Determina si continúa la espera por tiempo.
{if (p[l].fin == 3)
{auxfin = int (random (4));
if (auxfin == 1) auxfin = 0;
else {if (auxfin == 2) auxfin = 3;}
p[l].fin = auxfin;
}
}
}
}
cout <<"\n"<< "***Se han producido "<< cambio<< "cambios de contexto.***"<<"\n";
/* Grabación en el archivo usado */
fprintf(textfile, "%s", "Se han simulado ");
fprintf(textfile, "%i", np);
fprintf(textfile, "%s\n", " procesos concurrentes.");
fprintf(textfile, "%s", "Se han producido ");
fprintf(textfile, "%i", cambio);
fprintf(textfile, "%s\n", " cambios de contexto.");
auxfin = getch();
}
void procesos::hrn(){
auxiden = 0; auxfin = 0; auxcuenta = 0; auxpri = 0; cambio = 0;
/* Grabación en el archivo usado */
fprintf(textfile, "%s\n", "************************************************************");
fprintf(textfile, "%s", "Simulacion HRN con ");
fprintf(textfile, "%i", cc);
fprintf(textfile, "%s\n", " ciclos de control.");
cout <<"\n";
cout <<"Secuencia de selección de procesos para su ejecución según HRN:";
cout <<"\n";
cout <<"***************************************************************";
cout <<"\n";
cout <<"Los procesos son atendidos segun su prioridad en la lista de procesos listos;\n";
cout <<"la prioridad depende de la relacion de respuesta: (TE + TS) / TS, donde\n";
cout <<"TE = Tiempo de Espera y TS = Tiempo de Servicio:";
cout <<"\n" <<"\n";
for (register int j=0; j<cc; j++) // ***Realiza ’cc’ ciclos de control***
{auxfin = 0;
for (register int m=0; m<np; m++)
{auxfin = auxfin + p[m].fin;}
if (auxfin == (np * 2))
{
cout <<"\n"<< "Todos los procesos han finalizado en "<< j << " ciclos de control.\n";
/* Grabación en el archivo usado */
fprintf(textfile, "%s", "Todos los procesos han finalizado en ");
fprintf(textfile, "%i", j);
fprintf(textfile, "%s\n", " ciclos de control.");
j = cc;
auxfin = getch();
}
if (j == 0)
{for (register int z=0; z<np; z++)
{p[z].cuenta = 1;}
}
if (j < cc)
{
for (register int l=0; l<np; l++)
{p[l].pri = (j / p[l].cuenta);
}
}
if (auxpri == 1)
{
for (register int s=0; s<np; s++)
{for (register int t=s; t<(np - 1); t++)
{if (p[t+1].pri > p[t].pri)
{auxiden = p[t].identif;
auxfin = p[t].fin;
auxcuenta = p[t].cuenta;
auxpri = p[t].pri;
p[t].identif = p[t+1].identif;
p[t].fin = p[t+1].fin;
p[t].cuenta = p[t+1].cuenta;
p[t].pri = p[t+1].pri;
p[t+1].identif = auxiden;
p[t+1].fin = auxfin;
p[t+1].cuenta = auxcuenta;
p[t+1].pri = auxpri;
}
}
}
}
for (register int i=0; i<np; i++)
{if (p[i].fin == 0)
{auxpri = 0;
cout <<"Procesador asignado al proceso: "<< p[i].identif;
cout <<"\n";
p[i].cuenta = p[i].cuenta + 1;
p[i].fin = int(random(3)); // Determina próximo estado del proceso.
// cout <<”\n” <<p[i].identif <<p[i].fin <<”\n”;
if (p[i].fin == 1)
cout <<"Proceso ’" <<p[i].identif <<"’ interrumpido por entrada / salida. "<< "\n";
else {if (p[i].fin == 2)
cout <<"Proceso ’" <<p[i].identif <<"’ finalizado. "<< "\n";
}
if (p[i].fin > 0)
{ // Intercambio de contexto.
cambio = cambio + 1;
auxiden = p[i].identif;
auxfin = p[i].fin;
auxcuenta = p[i].cuenta;
auxpri = p[i].pri;
for (register int k=i; k<(np - 1); k++)
{p[k].identif = p[k+1].identif;
p[k].fin = p[k+1].fin;
p[k].cuenta = p[k+1].cuenta;
p[k].pri = p[k+1].pri;
}
p[(np - 1)].identif = auxiden;
p[(np - 1)].fin = auxfin;
p[(np - 1)].cuenta = auxcuenta;
p[(np - 1)].pri = auxpri;
auxpri = 1; // Indica que hubo intercambio de contexto y debe reordenarse la lista de procesos según prioridades.
}
i = np;
auxfin = getch();
}
for (register int k=0; k<np; k++) // Determina si continúa la espera por entrada /salida.
{if (p[k].fin == 1) p[k].fin = int (random (2));
}
}
}
for (register int y=0; y<np; y++)
{p[y].cuenta = p[y].cuenta - 1;}
cout <<"\n"<< "***Se han producido "<< cambio<< " cambios de contexto.***"<<"\n";
/* Grabación en el archivo usado */
fprintf(textfile, "%s", "Se han simulado ");
fprintf(textfile, "%i", np);
fprintf(textfile, "%s\n", "procesos concurrentes.");
fprintf(textfile, "%s", "Se han producido ");
fprintf(textfile, "%i", cambio);
fprintf(textfile, "%s\n", " cambios de contexto.");
auxfin = getch();
}
void procesos::rnm(){
auxiden = 0; auxfin = 0; auxcuenta = 0; auxpri = 0; auxnivel = 0; cambio = 0;
/* Grabación en el archivo usado */
fprintf(textfile, "%s\n", "************************************************************");
fprintf(textfile, "%s", "Simulacion RNM con ");
fprintf(textfile, "%i", cc);
fprintf(textfile, "%s\n", " ciclos de control.");
cout <<"\n";
cout <<"Secuencia de selección de procesos para su ejecución según RNM:";
cout <<"\n";
cout <<"**************************************************************";
cout <<"\n";
cout <<"Los procesos son atendidos según su nivel en la lista de procesos listos;\n";
cout <<"pero disponen de un tiempo limitado (cuantum) del procesador;\n";
cout <<"si son interrumpidos por entrada / salida permanecen en la subcola\n";
cout <<"del nivel donde están, pero si son interrumpidos por tiempo pasan a\n";
cout <<"un nivel superior, que es atendido cuando ya no hay procesos listos\n";
cout <<"en los niveles inferiores; de allí el nombre de\n";
cout <<"Retroalimentación de Niveles Múltiples:";
cout <<"\n\n";
for (register int j=0; j<cc; j++) // ***Realiza ’cc’ ciclos de control***
{auxfin = 0;
for (register int m=0; m<np; m++)
{if (p[m].fin != 2)
{auxfin = 1;
m = np;
}
}
if (auxfin == 0)
{
cout <<"\n"<< "Todos los procesos han finalizado en "<< j << " ciclos de control.\n";
/* Grabación en el archivo usado */
fprintf(textfile, "%s", "Todos los procesos han finalizado en ");
fprintf(textfile, "%i", j);
fprintf(textfile, "%s\n", " ciclos de control.");
j = cc;
auxfin = getch();
}
if (auxpri == 1)
{
for (register int s=0; s<np; s++)
{for (register int t=s; t<(np - 1); t++)
{if (p[t+1].nivel < p[t].nivel)
{auxiden = p[t].identif;
auxfin = p[t].fin;
auxcuenta = p[t].cuenta;
auxpri = p[t].pri;
auxnivel = p[t].nivel;
p[t].identif = p[t+1].identif;
p[t].fin = p[t+1].fin;
p[t].cuenta = p[t+1].cuenta;
p[t].pri = p[t+1].pri;
p[t].nivel = p[t+1].nivel;
p[t+1].identif = auxiden;
p[t+1].fin = auxfin;
p[t+1].cuenta = auxcuenta;
p[t+1].pri = auxpri;
p[t+1].nivel = auxnivel;
}
}
}
}
for (register int i=0; i<np; i++)
{if (p[i].fin == 0)
{auxpri = 0;
cout <<"Procesador asignado al proceso: "<< p[i].identif;
cout <<"\n";
p[i].cuenta = p[i].cuenta + 1;
p[i].fin = int(random(4)); // Determina próximo estado del proceso.
// cout <<”\n” <<p[i].identif <<p[i].fin <<p[i].nivel <<”\n”;
if (p[i].fin == 0) p[i].fin = 3;
if (p[i].fin == 1)
cout <<"Proceso ’" <<p[i].identif <<"’ interrumpido por entrada / salida. "<< "\n";
else {if (p[i].fin == 2)
cout <<"Proceso ’" <<p[i].identif <<"’ finalizado. "<< "\n";
else {if (p[i].fin == 3)
cout <<"Proceso ’" <<p[i].identif <<"’ interrumpido por tiempo. "<< "\n";
p[i].nivel = p[i].nivel + 1;
}
}
if (p[i].fin > 0)
{ // Intercambio de contexto.
cambio = cambio + 1;
auxiden = p[i].identif;
auxfin = p[i].fin;
auxcuenta = p[i].cuenta;
auxpri = p[i].pri;
auxnivel = p[i].nivel;
for (register int k=i; k<(np - 1); k++)
{p[k].identif = p[k+1].identif;
p[k].fin = p[k+1].fin;
p[k].cuenta = p[k+1].cuenta;
p[k].pri = p[k+1].pri;
p[k].nivel = p[k+1].nivel;
}
p[(np - 1)].identif = auxiden;
p[(np - 1)].fin = auxfin;
p[(np - 1)].cuenta = auxcuenta;
p[(np - 1)].pri = auxpri;
p[(np - 1)].nivel = auxnivel;
auxpri = 1; // Indica que hubo intercambio de contexto y debe reordenarse la lista de procesos según prioridades.
}
i = np;
auxfin = getch();
}
for (register int k=0; k<np; k++) // Determina si continúa la espera por entrada /salida.
{if (p[k].fin == 1) p[k].fin = int (random (2));
}
for (register int l=0; l<np; l++) // Determina si continúa la espera por tiempo.
{if (p[l].fin == 3)
{auxfin = int (random (4));
if (auxfin == 1) auxfin = 0;
else {if (auxfin == 2) auxfin = 3;}
p[l].fin = auxfin;
}
}
}
}
cout <<"\n\n"<< "***Se han producido "<< cambio<< " cambios de contexto.***"<<"\n";
/* Grabación en el archivo usado */
fprintf(textfile, "%s", "Se han simulado ");
fprintf(textfile, "%i", np);
fprintf(textfile, "%s\n", " procesos concurrentes.");
fprintf(textfile, "%s", "Se han producido ");
fprintf(textfile, "%i", cambio);
fprintf(textfile, "%s\n", " cambios de contexto.");
auxfin = getch();
}
void procesos::final(){
/* Cierre del archivo usado */
cout << "\nCierre del archivo resumen ’PROCESOS.TXT’.\n";
cout << "Se sugiere visualizar su contenido con el Notepad.exe de Windows.\n";
fclose(textfile);
}
void main()
{
  /* Variables */
  procesos p1;
  /* Código */
  clrscr();
  p1.inicio();
  p1.introducir_datos();
  p1.mostrar();
  p1.fifo();
  p1.mostrar();
  p1.introducir_datos();
  p1.mostrar();
  p1.rrobin();
  p1.mostrar();
  p1.introducir_datos();
  p1.mostrar();
  p1.hrn();
  p1.mostrar();
  p1.introducir_datos();
  p1.mostrar();
  p1.rnm();
  p1.mostrar();
  p1.final();
  getch();
}