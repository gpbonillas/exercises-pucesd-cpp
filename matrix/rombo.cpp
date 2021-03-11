#include<iostream.h>
#include<conio.h>
void main(){
int i, j, k,d;
cout<<"INGRESE DIMENSION DEL ROMBO: ";cin>>d;
clrscr();
for(i=0;i<=d;i++)
{
 for(j=0; j<=(2*d-2*i);j++)
 {cout<<" ";}
 //cout<<j;
 for(k=j; k<2*d; k++)
 {
  cout<<"*";
  cout<<" ";
 }
 cout<<"\n";
}

for(i=(d-1);i>=0;i--)
{
  for(j=0;j<=(2*d-2*i);j++)
  {cout<<" ";}
  //cout<<j;
  for(k=j;k<2*d;k++)
  {
   cout<<"*";
   cout<<" ";
  }
  cout<<"\n";
}
}

