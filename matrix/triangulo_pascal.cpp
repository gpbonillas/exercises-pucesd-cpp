#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

void main() {
int i, j, *puntero, dibujar[14], anterior[14];
gotoxy (25,1); cout <<"T R I A N G U L O   D E   P A S C A L\n\n\n";
for(i = 0; i < 14; i++){
	dibujar[i] = 0;
	anterior[i] = 0;
}
anterior[7] = 1;
for(j = 1; j < 14; j++){
	if(anterior[j]!= 0){
	    cout <<anterior[j];}
        else {
	cout <<" ";
	}
}
cout <<"\n";
for(i = 0; i < 6; i++){
	for(j= 1; j < 14; j++){
	    dibujar[j] = anterior[j-1] + anterior[j+1];
	    *puntero=dibujar[j];
	    if(*puntero!= 0){
		cout << *puntero;}
            else {
		cout <<" ";
	    }
	}
        cout <<"\n";
        for(j=1; j<14; j++){
	    anterior[j] = dibujar[j];
	}
    }
}
