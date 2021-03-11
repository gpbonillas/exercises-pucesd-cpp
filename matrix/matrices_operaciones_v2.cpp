#include<iostream.h>
#include<conio.h>
void grafcuad1(int xc1);
void grafcuad2(int xc2);
void grafres(int xr);
void grafrec1(int m1, int n2);
void grafrec2(int m2, int n2);
void grafrectan(int mr, int nr);

int mat1[10][10],mat2[10][10];
int suma[10][10],resta[10][10],producto[10][10];
int i,j,cont,k,l,m,n,x,x1,x2,x3,x4,x5,y,sum, oper, opc1, k1, n1;
int sumatoria=0, y1;
char opc='n';

void main(){
do{
clrscr();
gotoxy(25,1);cout<<"OPERACIONES CON MATRICES";
gotoxy(20,2);cout<<"OPC #1:Sumar Matrices";
gotoxy(20,3);cout<<"OPC #2:Resta Matrices";
gotoxy(20,4);cout<<"OPC #3:Multiplicacion de Matrices";
gotoxy(25,6);cout<<"Elija una opcion(1-3): ";cin>>oper;
switch(oper){

case 1:
do{
clrscr();
gotoxy(32,2);cout<<"SUMA DE MATRICES";
gotoxy(1,3);cout<<"OPC #1: Matrices Cuadradas";
gotoxy(1,4);cout<<"OPC #2: Matrices Rectangulares";
gotoxy(1,6);cout<<"Elija una opcion(1-2): ";cin>>y1;
}while(y1>2);


if(y1==1){
clrscr();
gotoxy(1,1);cout<<"Ingrese dimension de matriz: ";cin>>k;
clrscr();
gotoxy(5,1);cout<<"MATRIZ #1("<<k<<"*"<<k<<") : ";
grafcuad1(k);
x=4; y=4;
for(i=0; i<k; i++){
	for(j=0; j<k; j++){
gotoxy(x,y);cin>>mat1[i][j];
x=x+4;
}
x=4;y=y+1;
}
gotoxy(32,1);cout<<"MATRIZ #2("<<k<<"*"<<k<<") : ";
grafcuad2(k);
x=31; y=4;
for(i=0; i<k; i++){
	for(j=0; j<k; j++){
gotoxy(x,y);cin>>mat2[i][j];
x=x+4;
}
x=31;y=y+1;
}
for(i=0;i<k;i++){
	for(j=0;j<k;j++){
suma[i][j]=mat1[i][j]+mat2[i][j];
}
}
gotoxy(57,2);cout<<"SUMA: ("<<k<<"*"<<k<<") : ";
grafres(k);
x=56; y=4;
for(i=0; i<k; i++){
	for(j=0; j<k; j++){
gotoxy(x,y);cout<<suma[i][j];
x=x+4;}
x=56;y=y+1;}
}

if(y1==2){
clrscr();
gotoxy(1,1);cout<<"# de filas(m) Matriz #1: ";cin>>k;
do{
gotoxy(1,2);cout<<"# de columnas(n) Matriz #1: ";cin>>n;
}while(n==k);
gotoxy(1,3);cout<<"# de filas(m1) Matriz #2: ";cin>>k1;
do{
gotoxy(1,4);cout<<"# de columnas(n1) Matriz #2: ";cin>>n1;
}while(n1==k1);
if(k==k1&&n==n1)
 {
clrscr();
gotoxy(5,1);cout<<"MATRIZ #1("<<k<<"*"<<n<<") : ";
grafrec1(k,n);
x=4; y=4;
for(i=0; i<k; i++){
	for(j=0; j<k; j++){
gotoxy(x,y);cin>>mat1[i][j];
x=x+4;
}
x=4;y=y+1;
}
gotoxy(32,1);cout<<"MATRIZ #2("<<k<<"*"<<n<<") : ";
grafrec2(k1,n1);
x=31; y=4;
for(i=0; i<k; i++){
	for(j=0; j<k; j++){
gotoxy(x,y);cin>>mat2[i][j];
x=x+4;
}
x=31;y=y+1;
}
for(i=0;i<k;i++){
	for(j=0;j<n;j++){
suma[i][j]=mat1[i][j]+mat2[i][j];
}
}
gotoxy(57,2);cout<<"SUMA: ("<<k<<"*"<<n<<") : ";
grafrectan(k,n);
x=56; y=4;
for(i=0; i<k; i++){
	for(j=0; j<n; j++){
gotoxy(x,y);cout<<suma[i][j];
x=x+4;
}
x=56;y=y+1;
}
}else{
clrscr();
gotoxy(1,2);cout<<"ERROR:No se puede realizar la suma";
}
}
break;
//iniciando el case de restas:

case 2:
do{
clrscr();
gotoxy(32,1);cout<<"RESTA DE MATRICES";
gotoxy(1,3);cout<<"OPC #1: Matrices Cuadradas";
gotoxy(1,4);cout<<"OPC #2: Matrices Rectangulares";
gotoxy(1,6);cout<<"Elija una opcion(1-2): ";cin>>y1;
}while(y1>2);

if(y1==1)
{
clrscr();
gotoxy(1,1);cout<<"Ingrese dimension de matriz: ";cin>>k;
gotoxy(5,2);cout<<"MATRIZ #1("<<k<<"*"<<k<<") : ";
grafcuad1(k);
x=4; y=4;
for(i=0; i<k; i++){
	for(j=0; j<k; j++){
gotoxy(x,y);cin>>mat1[i][j];
x=x+4;
}
x=4;y=y+1;
}
gotoxy(32,2);cout<<"MATRIZ #2("<<k<<"*"<<k<<") : ";
grafcuad2(k);
x=31; y=4;
for(i=0; i<k; i++){
	for(j=0; j<k; j++){
gotoxy(x,y);cin>>mat2[i][j];
x=x+4;
}
x=31;y=y+1;
}
for(i=0;i<k;i++){
	for(j=0;j<k;j++){
resta[i][j]=mat1[i][j]-mat2[i][j];
}
}
gotoxy(57,2);cout<<"RESTA: ("<<k<<"*"<<k<<") : ";
grafres(k);
x=56; y=4;
for(i=0; i<k; i++){
	for(j=0; j<k; j++){
gotoxy(x,y);cout<<resta[i][j];
x=x+4;}
x=56;y=y+1;}
}

if(y1==2){
clrscr();
gotoxy(1,1);cout<<"# de filas(m) Matriz #1: ";cin>>k;
do{
gotoxy(1,2);cout<<"# de columnas(n) Matriz #1: ";cin>>n;
}while(n==k);
gotoxy(1,3);cout<<"# de filas(m1) Matriz #2: ";cin>>k1;
do{
gotoxy(1,4);cout<<"# de columnas(n1) Matriz #2: ";cin>>n1;
}while(n1==k1);
if(k==k1&&n==n1)
 {                 //VALIDANDO LAS DIMENSIONES
clrscr();
gotoxy(5,2);cout<<"MATRIZ #1("<<k<<"*"<<n<<") : ";
grafrec1(k,n);
x=4; y=4;
for(i=0; i<k; i++){
	for(j=0; j<n; j++){
gotoxy(x,y);cin>>mat1[i][j];
x=x+4;
}
x=4;y=y+1;
}
gotoxy(32,2);cout<<"MATRIZ #2("<<k1<<"*"<<n1<<") : ";
grafrec2(k1,n1);
x=31; y=4;
for(i=0; i<k; i++){
	for(j=0; j<n; j++){
gotoxy(x,y);cin>>mat2[i][j];
x=x+4;
}
x=31;y=y+1;
}

for(i=0;i<k;i++){
	for(j=0;j<n;j++){
resta[i][j]=mat1[i][j]-mat2[i][j];
}
}

gotoxy(57,2);cout<<"RESTA: ("<<k<<"*"<<n<<") : ";
grafrectan(k,n);
x=56; y=4;
for(i=0; i<k; i++){
	for(j=0; j<k; j++){
gotoxy(x,y);cout<<resta[i][j];
x=x+4;
}
x=56;y=y+1;
}
}else{
clrscr();
gotoxy(1,2);cout<<"ERROR:No se puede realizar la resta";
}
}

break;

//************iniciando el case de multiplicacion

case 3:
do{
clrscr();
gotoxy(32,1);cout<<"PRODUCTO DE MATRICES";
gotoxy(1,3);cout<<"OPC #1: Matrices Cuadradas";
gotoxy(1,4);cout<<"OPC #2: Matrices Rectangulares";
gotoxy(1,6);cout<<"Elija una opcion(1-2): ";cin>>y1;
}while(y1>2);

if(y1==1){
clrscr();
gotoxy(1,1);cout<<"Ingrese dimension de matriz: ";cin>>k;
gotoxy(5,2);cout<<"MATRIZ #1("<<k<<"*"<<k<<") : ";
grafcuad1(k);
x=4; y=4;
for(i=0; i<k; i++){
	for(j=0; j<k; j++){
gotoxy(x,y);cin>>mat1[i][j];
x=x+4;
}
x=4;y=y+1;
}
gotoxy(32,2);cout<<"MATRIZ #2("<<k<<"*"<<k<<") : ";
grafcuad2(k);
x=31; y=4;
for(i=0; i<k; i++){
	for(j=0; j<k; j++){
gotoxy(x,y);cin>>mat2[i][j];
x=x+4;
}
x=31;y=y+1;
}

for(i=0; i<k; i++){
  for(cont=0; cont<k; cont++){
	 for(j=0; j<k; j++){
sumatoria=sumatoria+((mat1[i][j])*(mat2[j][cont]));
producto[i][cont]=sumatoria;
}
sumatoria=0;
  }
	  }


gotoxy(57,2);cout<<"PRODUCTO: ("<<k<<"*"<<k<<") : ";
grafres(k);
x=56; y=4;
for(i=0; i<k; i++){
	for(cont=0; cont<k; cont++){
gotoxy(x,y);cout<<producto[i][cont];
x=x+4;}
x=56;y=y+1;}

}

if(y1==2){
clrscr();
gotoxy(1,1);cout<<"# de filas(m) Matriz #1: ";cin>>k;
do{
gotoxy(1,2);cout<<"# de columnas(n) Matriz #1: ";cin>>n;
}while(n==k);
gotoxy(1,3);cout<<"# de filas(m1) Matriz #2: ";cin>>k1;
do{
gotoxy(1,4);cout<<"# de columnas(n1) Matriz #2: ";cin>>n1;
}while(n1==k1);
if(n==k1)
 {                 //VALIDANDO LAS DIMENSIONES
clrscr();
gotoxy(5,1);cout<<"MATRIZ #1("<<k<<"*"<<n<<") : ";
grafrec1(k,n);
x=4; y=4;
for(i=0; i<k; i++){
	for(j=0; j<n; j++){
gotoxy(x,y);cin>>mat1[i][j];
x=x+4;
}
x=4;y=y+1;
}
gotoxy(32,1);cout<<"MATRIZ #2("<<k1<<"*"<<n1<<") : ";
grafrec2(k1,n1);
x=31; y=4;
for(i=0; i<k1; i++){
	for(j=0; j<n1; j++){
gotoxy(x,y);cin>>mat2[i][j];
x=x+4;
}
x=31;y=y+1;
}

for(i=0; i<k; i++)
	 {
		for(cont=0; cont<n1; cont++)
		{
			 for(j=0; j<n; j++)
			 {
			 sumatoria=sumatoria+((mat1[i][j])*(mat2[j][cont]));
			 producto[i][cont]=sumatoria;
			 }
		 sumatoria=0;
		}
	 }

gotoxy(57,1);cout<<"PRODUCTO: ("<<k<<"*"<<n1<<") : ";
grafrectan(k,n1);
x=56; y=4;
for(i=0; i<k; i++){
	for(cont=0; cont<k; cont++){
gotoxy(x,y);cout<<producto[i][cont];
x=x+4;
}
x=56;y=y+1;
}
}else{
clrscr();
gotoxy(1,2);cout<<"ERROR:No se puede realizar la multiplicacion";
}
}
break;

default:
cout<<"Opcion Invalida";
break;
}//Cierre del switch

gotoxy(1,18);cout<<"¿DESEA INGRESAR NUEVAMENTE? (s/n)";cin >>opc;
}while(opc=='s'||opc=='S');



}

























void grafcuad1(int xc1){

if(xc1>2&&xc1<6){
x1=6;
x2=0;
x3=3;
x4=-2;
x5=0;}

if(xc1==2){
x1=3;
x2=0;
x3=0;
x4=0;
x5=2;}

if(xc1>=6&&xc1<8){
x1=5;
x2=4;
x3=2;
x4=-2;
x5=0;}

if(xc1>=8){
x1=8;
x2=0;
x3=5;
x4=0;
x5=2;}

gotoxy(3,2);cout<<"__";gotoxy(((3*xc1)+x1+x2+x4),2);cout<<"__";
for(i=(x1-x3); i<=(xc1+4); i++){
gotoxy(2,(i));cout<<"|";
gotoxy(((3*xc1)+x1+x2+x5),i);cout<<"|";
}
gotoxy(3,(xc1+4));cout<<"__";
gotoxy(((3*xc1)+x1+x2+x4),(xc1+4));cout<<"__";
}






void grafcuad2(int xc2){
if(xc2>2&&xc2<6){
x1=6;
x2=0;
x3=3;
x4=-2;
x5=0;}

if(xc2==2){
x1=3;
x2=0;
x3=0;
x4=0;
x5=2;}

if(xc2>=6&&(xc2<8)){
x1=5;
x2=4;
x3=2;
x4=-2;
x5=0;}

if((xc2)>=8){
x1=8;
x2=0;
x3=5;
x4=0;
x5=2;}

gotoxy(30,2);cout<<"__";gotoxy(((3*xc2)+x1+x2+x4+27),2);cout<<"__";
for(i=(x1-x3); i<=(xc2+4); i++){
gotoxy(29,(i));cout<<"|";
gotoxy(((3*xc2)+x1+x2+x5+27),i);cout<<"|";
}
gotoxy(30,(xc2+4));cout<<"__";
gotoxy(((3*xc2)+x1+x2+x4+27),(xc2+4));cout<<"__";
}



void grafres(int xr){

if(xr>2&&xr<6){
x1=6;
x2=0;
x3=3;
x4=-2;
x5=0;}

if(xr==2){
x1=3;
x2=0;
x3=0;
x4=0;
x5=2;}

if((xr>=6)&&(xr<8)){
x1=5;
x2=4;
x3=2;
x4=-2;
x5=0;}

if(xr>=8){
x1=8;
x2=0;
x3=5;
x4=0;
x5=2;}

gotoxy(55,2);cout<<"__";gotoxy(((3*xr)+x1+x2+x4+52),2);cout<<"__";
for(i=(x1-x3); i<=(xr+4); i++){
gotoxy(54,(i));cout<<"|";
gotoxy(((3*xr)+x1+x2+x5+52),i);cout<<"|";
}
gotoxy(55,(xr+4));cout<<"__";
gotoxy(((3*xr)+x1+x2+x4+52),(xr+4));cout<<"__";
}



void grafrec1(int m1, int n1){
if(n1>m1){
x2=3;
x1=4;
x3=2;
x4=7;
x5=0;
if(n1-m1==4){
x1=6;
x2=16;
x3=3;
x4=4;
x5=3;}
if(n1-m1==4&&n1<6){
x1=6;
x2=13;
x3=3;
x4=4;
x5=3;}
if(n1-m1==3){
x1=6;
x2=13;
x3=3;
x4=4;
x5=2;}
if(n1-m1==3&&n1<6){
x1=6;
x2=10;
x3=3;
x4=4;
x5=2;}
if(n1-m1==2){
x1=6;
x2=10;
x3=3;
x4=4;
x5=1;}
if(n1-m1==2&&n1<6){
x1=6;
x2=7;
x3=3;
x4=4;
x5=1;}
if(n1-m1==1&&n1<6){
x1=8;
x2=1;
x3=5;
x4=6;}
if(n1-m1==1&&n1>=6)
{x1=9;
x3=6;}
gotoxy(3,2);cout<<"__";gotoxy(((3*m1)+x2+x4),2);cout<<"__";
for(i=(x1-x3); i<=((n1+3)-x5); i++){
gotoxy(2,i);cout<<"|";
gotoxy(((3*m1)+x1+x2),i);cout<<"|";
}
gotoxy(3,((n1+3)-x5));cout<<"__";
gotoxy(((3*m1)+x2+x4),((n1+3)-x5));cout<<"__";
}//CIERRE DEL n1>m1
if(m1>n1){
x2=2;
x1=3;
x3=1;
if(m1-n1==5){
x1=1;
x3=-2;}
if(m1-n1==4){
x1=2;
x3=-1;}
if(m1-n1==3){
x1=3;
x3=0;}
if(m1-n1==2){
x1=4;
x3=1;}
if(m1-n1==1&&m1<6){
x1=5;
x3=2;}
if(m1-n1==1&&m1>=6)
{x1=5;
x3=2;}
gotoxy(3,2);cout<<"__";gotoxy(((3*n1)+x1),2);cout<<"__";
for(i=(x1-x3); i<=(m1+4); i++){
gotoxy(2,i);cout<<"|";
gotoxy(((3*n1)+x1+x2),i);cout<<"|";
}
gotoxy(3,(m1+4));cout<<"__";
gotoxy(((3*n1)+x1),(k+4));cout<<"__";
}//CIERRE DEL m1>n1
}



void grafrec2(int m2, int n2){
if(n2>m2){
x2=3;
x1=4;
x3=2;
x4=7;
x5=0;
if(n2-m2==4){
x1=6;
x2=16;
x3=3;
x4=4;
x5=3;}

if(n2-m2==4&&n2<6){
x1=6;
x2=13;
x3=3;
x4=4;
x5=3;}

if(n2-m2==3){
x1=6;
x2=13;
x3=3;
x4=4;
x5=2;}

if(n2-m2==3&&n2<6){
x1=6;
x2=10;
x3=3;
x4=4;
x5=2;}

if(n2-m2==2){
x1=6;
x2=10;
x3=3;
x4=4;
x5=1;}

if(n2-m2==2&&n2<6){
x1=6;
x2=7;
x3=3;
x4=4;
x5=1;}

if(n2-m2==1&&n2<6){
x1=8;
x2=1;
x3=5;
x4=6;}

if(n2-m2==1&&n2>=6)
{x1=9;
x3=6;}

gotoxy(30,2);cout<<"__";gotoxy(((3*m2)+x2+x4+27),2);cout<<"__";
for(i=(x1-x3); i<=((n2+3)-x5); i++){
gotoxy(29,i);cout<<"|";
gotoxy(((3*m2)+x1+x2+27),i);cout<<"|";
}
gotoxy(30,((n2+3)-x5));cout<<"__";
gotoxy(((3*m2)+x2+x4+27),((n2+3)-x5));cout<<"__";
}
if(m2>n2){
x2=2;
x1=3;
x3=1;
if(m2-n2==5){
x1=1;
x3=-2;}
if(m2-n2==4){
x1=2;
x3=-1;}
if(m2-n2==3){
x1=3;
x3=0;}
if(m2-n2==2){
x1=4;
x3=1;}
if(m2-n2==1&&m2<6){
x1=5;
x3=2;}
if(m2-n2==1&&m2>=6)
{x1=5;
x3=2;}
gotoxy(30,2);cout<<"__";gotoxy(((3*n2)+x1+27),2);cout<<"__";
for(i=(x1-x3); i<=(m2+4); i++){

gotoxy(29,i);cout<<"|";
gotoxy(((3*n2)+x1+x2+27),i);cout<<"|";
}
gotoxy(30,(m2+4));cout<<"__";
gotoxy(((4*n2)+x1+27),(m2+4));cout<<"__";
}
}

void grafrectan(int mr, int nr){
if(nr>mr){
x2=3;
x1=4;
x3=2;
x4=7;
x5=0;
if(nr-mr==4){
x1=6;
x2=16;
x3=3;
x4=4;
x5=3;}
if(nr-mr==4&&nr<6){
x1=6;
x2=13;
x3=3;
x4=4;
x5=3;}
if(nr-mr==3){
x1=6;
x2=13;
x3=3;
x4=4;
x5=2;}
if(nr-mr==3&&nr<6){
x1=6;
x2=10;
x3=3;
x4=4;
x5=2;}
if(nr-mr==2){
x1=6;
x2=10;
x3=3;
x4=4;
x5=1;}
if(nr-mr==2&&nr<6){
x1=6;
x2=7;
x3=3;
x4=4;
x5=1;}
if(nr-mr==1&&nr<6){
x1=8;
x2=1;
x3=5;
x4=6;}
if(nr-mr==1&&nr>=6)
{x1=9;
x3=6;}
gotoxy(55,2);cout<<"__";gotoxy(((3*mr)+x2+x4+52),2);cout<<"__";
for(i=(x1-x3); i<=((nr+3)-x5); i++){
gotoxy(54,i);cout<<"|";
gotoxy(((3*mr)+x1+x2+52),i);cout<<"|";
}
gotoxy(55,((nr+3)-x5));cout<<"__";
gotoxy(((3*mr)+x2+x4+52),((nr+3)-x5));cout<<"__";
}

if(mr>nr){
x2=2;
x1=3;
x3=1;
if(mr-nr==5){
x1=1;
x3=-2;}
if(mr-nr==4){
x1=2;
x3=-1;}
if(mr-nr==3){
x1=3;
x3=0;}
if(mr-nr==2){
x1=4;
x3=1;}
if(mr-nr==1&&mr<6){
x1=5;
x3=2;}
if(mr-nr==1&&mr>=6)
{x1=5;
x3=2;}
gotoxy(55,2);cout<<"__";gotoxy(((3*nr)+x1+52),2);cout<<"__";
for(i=(x1-x3); i<=(mr+4); i++){

gotoxy(54,i);cout<<"|";
gotoxy(((3*nr)+x1+x2+52),i);cout<<"|";
}
gotoxy(55,(mr+4));cout<<"__";
gotoxy(((3*nr)+x1+52),(mr+4));cout<<"__";
}
}

