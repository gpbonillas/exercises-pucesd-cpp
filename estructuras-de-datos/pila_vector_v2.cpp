#include <iostream.h>

  // Pila hecha con un vector fijo de 50 posiciones
class Pila {
 int vector[50];
  // indicePila:  -1 -> pila vacia     0 -> posicion del dato
 int indicePila;
public:
 Pila() {   indicePila = -1; }; // constructor
  // funciones analizadoras
 void mostrarDatos();
 int cuantosDatos();
  // funciones modificadoras
 void entrarDato(int dato);
 int sacarDato();
};

 // Esta función sale del cuerpo de la clase porque usa un ciclo. 
void Pila::mostrarDatos() {
 cout << endl << "DATOS EN LA PILA" << endl;
 for (int i=0; i<=indicePila; i++)
  cout << "Dato No. " << i << " : " << vector[i] << endl;
 cout << endl;
}

int Pila::cuantosDatos() {
 return indicePila + 1;
}

void Pila::entrarDato(int dato) {
 if (indicePila < 49) {
  indicePila ++;
  vector[indicePila] = dato;
 } else
  cout << "Pila desbordada: no se añadio valor" << endl;
}

int Pila::sacarDato() {
 if (indicePila > -1) {
  indicePila --;
  return vector[indicePila + 1];
 }
 return -1;
}

int menu() {
 cout << endl << endl;
 cout << "Bienvenido al programa manejador de Pila de enteros" << endl;
 cout << "Escoja una opción" << endl;
 cout << "**************************************" << endl;
 cout << "0. Salir del Programa" << endl;
 cout << "1. Adicionar entero" << endl;
 cout << "2. Sacar entero" << endl;
 cout << "3. Ver cuantos datos tiene la pila" << endl;
 cout << "4. Mostrar datos en la pila" << endl;
 cout << "**************************************" << endl;
 int opcion;
 cin >> opcion;
 return opcion;
}

main () {
 Pila pila1;
 int respuesta,opcion;
 opcion = -1;
 while (opcion != 0) {
  opcion = menu();
  switch (opcion) {
  case 0:
   cout << "Gracias por usar nuestro software" << endl;
   break;
  case 1:
   cout << "indique valor a entrar:"; 
   cin >> respuesta;
   pila1.entrarDato(respuesta);
   break;
  case 2: 
   cout << "Dato obtenido:" << pila1.sacarDato() << endl;
   break;
  case 3: 
   cout << "Hay " << pila1.cuantosDatos() << " en la pila" << endl;
   break;
  case 4:
   pila1.mostrarDatos();
  }
 }
 return 0;
}