#include<iostream.h>
#include<conio.h>

void main(){
int mat1[10][10],mat2[10][10];
int suma[10][10],resta[10][10],producto[10][10];
int i,j,cont,k,l,m,n,x,x1,y,sum, oper;
char y1='n', opc='n';

do{
clrscr();
gotoxy(25,1);cout<<"OPERACIONES CON MATRICES";
gotoxy(20,2);cout<<"OPC #1:Sumar";
gotoxy(20,3);cout<<"OPC #2:Resta";
gotoxy(20,4);cout<<"OPC #3:Multiplicacion";
gotoxy(25,6);cout<<"Elija una opcion: ";cin>>oper;

switch(oper){
case 1:
clrscr();
gotoxy(1,1);cout<<"Ingrese dimension de matriz: ";cin>>k;
x=3; y=6;
for(i=0; i<k; i++){
  for(j=0; j<k; j++){
gotoxy(x,y);cin>>matriz[i][j];
x=x+4;
}
x=3;y=y+2;
}

clrscr();
gotoxy(3,1);cout<<"MATRIZ INGRESADA ("<<k<<"*"<<k<<") : ";
if(k>4){
gotoxy(3,2);cout<<"__";gotoxy(((4*k)+1),2);cout<<"__";
for(i=3; i<((2*k)); i++){
gotoxy(2,i);cout<<"|";
gotoxy(((4*k)+3),i);cout<<"|";
}
gotoxy(3,((2*k)-1));cout<<"__";
gotoxy(((4*k)+1),((2*k)-1));cout<<"__";
}else{
if(k==2){
gotoxy(3,2);cout<<"__";gotoxy(((4*k)+1),2);cout<<"__";
for(i=3; i<((3*k)+1); i++){
gotoxy(2,i);cout<<"|";
gotoxy(((4*k)+3),i);cout<<"|";
}
gotoxy(3,(3*k));cout<<"__";
gotoxy(((4*k)+1),(3*k));cout<<"__";
}else{
gotoxy(3,2);cout<<"__";gotoxy(((4*k)+1),2);cout<<"__";
for(i=3; i<((2*k)+2); i++){
gotoxy(2,i);cout<<"|";
gotoxy(((4*k)+3),i);cout<<"|";
}
gotoxy(3,((2*k)+1));cout<<"__";
gotoxy(((4*k)+1),((2*k)+1));cout<<"__";
}
}
cout<<"\n\n";
x=4; y=4;
for(i=0; i<k; i++){
	for(j=0; j<k; j++){
gotoxy(x,y);cout<<matriz[i][j];
x=x+4;
}
x=4;y=y+1;
}
cout<<"\n\n\n";






for(i=0;i<k;i++)
  {
		 for(j=0;j<l;j++)
		 {
  suma[i][j]=mat1[i][j]+mat2[i][j];
		 }
  }
x=2;y=17;x1=22;
for(i=0;i<k;i++)
{
	for(j=0;j<l;j++)
	{
	gotoxy(x,y);cout<<suma[i][j];
	gotoxy(x1,y);cout<<resta[i][j];
	x=x+4;
	x1=x1+4;
	}
x=2;x1=22;y++;
}
}
//INTERRUPTOR
if(k==m && l==n)
{y1='n';}
else
{y1='s';}

//MULTIPLICACION
if(l==m){
if(y1=='s'){
clrscr();
gotoxy(5,1);cout<<"Matriz ("<<k<<"*"<<l<<") :";


x=4; y=3;
for(i=0; i<k; i++)
 {
 for(j=0; j<l; j++)
 {
 gotoxy(x,y);cin>>mat1[i][j];
 x=x+4;
 }
 x=4;y=y+1;
 }

gotoxy(34,1);cout<<"Matriz ("<<m<<"*"<<n<<") :";


x=34;y=3;
for(i=0;i<m;i++)
  {
  for(j=0;j<n;j++)
  {
  gotoxy(x,y);cin>>mat2[i][j];
  x=x+4;
  }
  x=34;
  y=y+1;
  }
//MULTIPLICACION
for(i=0; i<k; i++)
	 {
		for(cont=0; cont<n; cont++)
		{
			 for(j=0; j<l; j++)
			 {
			 sum=sum+((mat1[i][j])*(mat2[j][cont]));
			 producto[i][cont]=sum;
			 }
		 sum=0;
		}
	 }

gotoxy(1,12);cout<<"ERROR: Dimensiones Invalidas para la suma y la resta";
//IMPRIMIR PRODUCTO
gotoxy(25,15);cout<<"PRODUCTO ("<<k<<"*"<<n<<"):";
x=24;y=17;
for(i=0;i<k;i++)
{
  for(j=0;j<n;j++)
  {

  gotoxy(x,y);cout<<producto[i][j];
  x=x+5;
  }
x=24;y=y+1;
}
}//FINAL DEL IF(y1=='s')

for(i=0; i<k; i++)
	 {
		for(cont=0; cont<n; cont++)
		{
			 for(j=0; j<l; j++)
			 {
			 sum=sum+((mat1[i][j])*(mat2[j][cont]));
			 producto[i][cont]=sum;
			 }
		 sum=0;
		}
	 }


if(y1=='n'){
//IMPRIMIR PRODUCTO
gotoxy(49,15);cout<<"PRODUCTO ("<<k<<"*"<<n<<"):";
x=48;y=17;
for(i=0;i<k;i++)
{
  for(j=0;j<n;j++)
  {

  gotoxy(x,y);cout<<producto[i][j];
  x=x+5;
  }
x=48;y=y+1;
}
}
}
else
{
clrscr();

for(i=2;i<47;i++){
gotoxy(i,2);cout<<"*";
gotoxy(i,8);cout<<"*";}

for(i=2;i<9;i++){
gotoxy(2,i);cout<<"*";
gotoxy(47,i);cout<<"*";}

gotoxy(5,4);cout<<"ERROR: DIMENSIONES INVALIDAS";
gotoxy(5,6);cout<<"NO SE PUEDE REALIZAR NINGUNA OPERACION";
}
gotoxy(2,23);cout<<"DESES VOLVER A INGRESAR(s/n): ";cin>>opc;
}while(opc=='s'||opc=='S');

}




gotoxy(1,15);cout<<"¿DESEA SEGUIR? (s/n)";cin >>opc;
}while(opc=='s'||opc=='S');











