#include <iostream.h>
#include <alloc.h>
#include <math.h>

double det(double **m, int b){
	double determinante = 0, aux = 0;
	int c;
	if(b==2)
		return m[0][0]*m[1][1] - m[1][0]*m[0][1];
	else{
		for(int j=0; j<b; j++){
			double **menor = (double **)malloc(sizeof(double)*(b-1));
			for(int h=0; h<(b-1); h++) menor[h] = (double *)malloc(sizeof(double)*(b-1));
			for(int k=1; k<b; k++){
				c = 0;
				for(int l=0; l<b; l++){
					if(l!=j){
						menor[k-1][c] = m[k][l];
						c++;
					}
				}
			}
			aux = pow(-1, 2+j)*m[0][j]*det(menor, b-1);
			determinante += aux;
			for(int q = 0; q<(b-1); q++)
				free(menor[q]);
			free(menor);
		}
		return determinante;
	}
}

int main(){
	int n;  // n = numero de renglones = numero de columnas
	double **m=NULL;
	cout<<"Elija el numero de renglones o columnas que tiene su matriz: \n";
	cin>>n;

	// Se crea la matriz de forma dinamica
	m = (double **)malloc(sizeof(double)*n);
	for(int i=0; i<n; i++) m[i]=(double *)malloc(sizeof(double)*n);

	// Pide el valor de cada elemento de la matriz
	for(int y=0; y<n; y++)
		for(int w=0; w<n; w++){
			cout<<"Introduzca el valor de matriz[\"<<y<<\"][\"<<w<<\"]: \n";
			cin>>m[y][w];
		}

	// Despliego el resultado de la funcion det
	cout<<"nDeterminante: \n"<<det(m, n);

   // Libero la memoria utilizada por la matriz
	for(int r=0; r<n; r++) free(m[r]);
	free(m);

   return 0;
}