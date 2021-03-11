/*Captura datos del cliente y del articulo e imprime precio de compra, IVA y precio final */ 
#include <stdio.h> 
#include <conio.h>
#include<stdio.h>
#include<conio.h>
void main(){
char nom[30], dir[30], rfc[20], art[30];
int cant;
float precio, iva, total, subtotal;
clrscr();
printf("\n\nNombre del cliente: "); gets(nom);
printf("\n\nDireccion del cliente: "); gets(dir);
printf("\n\nRFC:");
gets(rfc);
printf("\n\n\nCantidad: "), scanf("%d", &cant);
printf("\n\nNombre del articulo: "), scanf("%s");
printf("\n\nPrecio: "), scanf("%f",&precio);
clrscr();
subtotal=precio * cant;
iva=subtotal*.10;
total=subtotal+iva;
printf("Nombre: %s\nDireccion: %s\nRFC: %s\nCantidad: %d\nArticulo: %s\nPrecio:%.2f\nSubtotal: %.2f\nIVA: %f\nTotal: %.2f", nom, dir, rfc, cant, art, precio, subtotal,
iva, total);
getch();
}