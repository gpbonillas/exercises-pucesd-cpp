#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>

#define Verdadero 1
#define Falso 0
#define Max 10


void OrdenarVector(int V[])
{int Inc,tmp,j;
	Inc=Max/2;
	do{
		for(int i=Inc;i<Max;i++)
		{
			tmp=V[i];
			j=i-Inc;
			while((j>=0)&&(tmp<V[j]))
			{
				V[j+Inc]=V[j];
				j-=Inc;
			}
			V[j+Inc]=tmp;
		}
		Inc/=2;
	}while(Inc!=0);

}


void Generar(int V[])
{	randomize();
	for(int i=0;i<Max;i++)
		V[i]=random(101);
	cout<<endl<<"Vector generado...";
	cout<<endl<<"Presione una tecla para continuar";
	OrdenarVector(V);
	getch();
}


void MostrarVector(int V[], int M)
{
	for(int i=0;i<M;i++)
		cout<<endl<<V[i];
	cout<<endl<<"Presione una tecla para continuar";
	getch();
}


int Busqueda(int V[])
{int Inf,Sup,Cen,Dato;
 int NoEncontrado;
	cout<<endl<<"Ingrese dato a buscar: ";
	cin>>Dato;
	Inf=0;
	Sup=Max-1;
	NoEncontrado=Verdadero;
	while(Inf<=Sup && NoEncontrado==Verdadero)
	{	Cen=(Inf+Sup)/2;
		if(V[Cen]==Dato)
			NoEncontrado=Falso;
		else
			if(V[Cen]<Dato)
				Inf=Cen+1;
			else
				Sup=Cen -1;
	}
	if(NoEncontrado)
		return -1;
	else
		return Cen;
}

int Repeticiones (int V[])
{       int Dato,c;
	cout<<endl<<"Ingrese dato a buscar repeticiones: ";
	cin>>Dato;
	c=0;
	for(int i=0;i<Max;i++)
		if(V[i]==Dato)
			c++;
	return c;
}

int ParImpar(int V[],int VA[],int Caso)
{int c,i;
	c=0;
	switch(Caso)
	{
		case 1: for(i=0;i<Max;i++)
				if(V[i]%2==0)
				{
					VA[c]=V[i];
					c++;
				}
			break;
		case 2: for(i=0;i<Max;i++)
				if(V[i]%2!=0)
				{
					VA[c]=V[i];
					c++;
				}
	}
	return c;
}

char Menu()
{       char R;
	clrscr();
	cout<<endl<<"         Men£       ";
	cout<<endl<<"---------------------";
	cout<<endl<<"[G]. Generar vector";
	cout<<endl<<"[M]. Mostrar Vector";
	cout<<endl<<"[B]. B£squeda";
	cout<<endl<<"[R]. Repeticiones";
	cout<<endl<<"[P]. Pares/Impares";
	cout<<endl<<"[S]. Salir";
	cout<<endl<<"Opcion: ";
	do{
		cin>>R;
		R=toupper(R);
	}while(R!='G' && R!='M' && R!='B' && R!='R' && R!='P' && R!='S');
	return R;
}
int MenuParImpar()
{       char R;
	clrscr();
	cout<<endl<<"     Men£ Par/Impar    ";
	cout<<endl<<"-----------------------";
	cout<<endl<<"[P]. Ejecutar Pares";
	cout<<endl<<"[I]. Ejecutar impares";
	cout<<endl<<"[V]. Ver Vector pares";
	cout<<endl<<"[W]. Ver vector impares";
	cout<<endl<<"[S]. Salir";
	cout<<endl<<"Opcion: ";
	do{
		cin>>R;
		R=toupper(R);
	}while(R!='P' && R!='I' && R!='V' && R!='W' && R!='S');
	return R;
}
void main()
{int V[Max],Par[Max],Impar[Max];
 int NI, NP,x;
 char R, R2;

	do{
		R=Menu();
		switch(R)
		{
			case 'G' : Generar(V);break;
			case 'M' : MostrarVector(V,Max);break;
			case 'B' : x=Busqueda(V);
				   if(x>=0)
					cout<<endl<<"Encontrado en posici¢n: "<<x;
				   else
					cout<<"No Encontrado";
				   cout<<endl<<"Presione una tecla para continuar";
				   getch();
				   break;
			case 'R' : x=Repeticiones(V);
				   cout<<endl<<"Se repite "<<x<<" veces";
				   cout<<endl<<"Presione una tecla para continuar";
				   getch();
				   break;
			case 'P' : do{
					R2=MenuParImpar();
					switch(R2)
					{
						case 'P' : NP=ParImpar(V,Par,1);break;
						case 'I' : NI=ParImpar(V,Impar,2);break;
						case 'V' : MostrarVector(Par,NP);break;
						case 'W' : MostrarVector(Impar,NI);break;
					}
				   }while(R2!='S');
		}



	}while(R!='S');
}