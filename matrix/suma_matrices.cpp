#include<iostream.h>
#include<conio.h>
void main(){
int mat25[5][5], sum1=0, sum2=0, sum3=0, sum4=0, i, j, x, y;


gotoxy(2,3);cout<<"__";gotoxy(21,3);cout<<"__";
for(i=4; i<15; i++){
gotoxy(1,i);cout<<"|";
gotoxy(23,i);cout<<"|";
}
gotoxy(2,14);cout<<"__";
gotoxy(21,14);cout<<"__";
cout<<"\n\n";
gotoxy(6,2);cout<<"MATRIZ(5*5): ";
x=4;y=5;
for (i=0; i<5; i++){
  for(j=0; j<5; j++){
gotoxy(x,y);cin>>mat25[i][j];
x=x+4;
}
x=4;y=y+2;
}


for(i=0; i<5; i++){
sum1=sum1+(mat25[i][i]);
}

j=4;
for(i=0; i<5; i++){
sum2=sum2+(mat25[i][j]);
j--;
}

for(i=0; i<5; i++){
 for(j=0; j<5; j++){
sum3=sum3+(mat25[i][j]);
}
i=4;
}

for(i=0; i<5; i++){
	for(j=0; j<5; j++){
sum4=sum4+(mat25[j][i]);
}
i=4;
}


cout<<"\n\n\nSUMA DE LA DIAGONAL PRINCIPAL: ";cout<<sum1;
cout<<"\nSUMA DE LA DIAGONAL SECUNDARIA: ";cout<<sum2;
cout<<"\nSUMA DE LA PRIMERA Y ULTIMA FILA: ";cout<<sum3;
cout<<"\nSUMA DE LA PRIMERA Y ULTIMA COLUMNA: ";cout<<sum4;
}


