#include<iostream.h>
#include<string.h>
#include<conio.h>

void main(){
char nombre1[20], nombre2[20];
int i=0, n=0,c=0;
clrscr();
cout<<"Ingrese su nombre: ";cin>>nombre1;
n=strlen(nombre1);
for(i=0; i<=n; i++){
if (nombre1[i]==' '){
i++;
}
nombre2[c]=nombre1[i];
c++;
}
cout<<"\n"<<nombre1<<"\n"<<nombre2;cout<<"\n";
int v=0;
for (i=n; i>=0; i--){
if (nombre2[i]==nombre1[c])
{v++;}
c++;}
if (v==n){
cout<<"\n\nEs palindromo";}
else
{cout<<"\n\nNo es palindromo";}
getch();
}
