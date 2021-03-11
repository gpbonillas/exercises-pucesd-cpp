#include<iostream.h>
#include<stdio.h>
#include<conio.h>
void recursiva(int n);

void main()
{
  int num;
  cout<<"Ingrese un numero: ";cin>>num;
  recursiva(num);
  getch();
}

void recursiva(int n){
  if(n!=0)
  {
    cout<<n<<endl;
    recursiva(n-1);
  }
}


















      	   























