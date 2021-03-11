# include <iostream.h>
# include <stdio.h>
# include <conio.h>
# include <string.h>
# include <fstream.h>

float pi=3.14159265;

class figura {
	protected:
	char nombre[10];
	public: figura (){
		strcpy(nombre,"circulo");
	}
}; 

class circulo : public figura {
	public:
	float radio;
	public: circulo (){
		radio= 0.0;
	}

	public: void ingresar () {
		cout <<"Ingrese nombre de la figura: "; cin >>nombre; cout <<endl;
		cout <<"INgrese radio: "; cin >>radio; cout <<endl;
	
	}

	public: void presentar (){
		cout <<"Nombre: "<<nombre <<endl;
		cout <<"Area: "<<(pi*radio*radio)<<endl;
		cout <<"Longitud: "<<(pi*2*radio)<<endl;
	}

};


void main () {
	circulo c = circulo();
        c.ingresar();
	c.presentar();
	getche();
}

