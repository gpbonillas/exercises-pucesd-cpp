// EJ10_03.CPP

// Funciones para medir el tiempo

#include <time.h>       // clock(), clock_t, CLK_TCK
#include <iostream.h>   // cout

typedef clock_t	*reloj;

reloj Start_Timer() {
  reloj c;

  c= new clock_t;               // Reservar memoria
  *c= clock();                  // Guardar n£mero de ticks
  return c;
}

double Get_Timer(reloj c) {
  clock_t Dif;
  Dif= clock() - *c;            // Diferencia entre Start y Stop
  return Dif / CLK_TCK;         // Pasar a segundos
}

double Stop_Timer(reloj c) {
  clock_t Dif;
  Dif= clock() - *c;            // Diferencia entre Start y Stop
  delete c;                     // Liberar memoria;
  return Dif / CLK_TCK;         // Pasar a segundos
}

long Cal= 100;

void Delay(unsigned long l) {
// Retardo de l milisegundos
  while (l--)
    for(long i= 0; i < Cal; i++);
}

void Calibrar_Delay(int s= 1) {
  reloj r;
  double d;

  r= Start_Timer();
  Delay(1000);		        // Aprox 1 segundo. Variar  mucho inicialmente
  d= Stop_Timer(r);
  Cal= int(double(Cal) / d);

  r= Start_Timer();
  s-= int(d);                   // Quitar lo que hemos tardado
  Delay(s * 1000);
  d= Stop_Timer(r);
  Cal= int(double(double(Cal) * s) / d);
}

void main() {
  reloj r1, r2;

  Calibrar_Delay(5);    // Calibremos durante unos 5 segundos la funci¢n Delay()
  Calibrar_Delay(5);    // Calibremos durante unos 5 segundos la funci¢n Delay()

  r1= Start_Timer();
  Delay(1000);
  cout << "Tiempo transcurrido 1: " << Stop_Timer(r1) << " segundos" << endl;
  r2= Start_Timer();
  Delay(5000);
  cout << "Tiempo transcurrido 2: " << Stop_Timer(r2) << " segundos" << endl;
}