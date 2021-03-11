//Ej20_05.cpp

#include <utility>
#include <iostream>
#include <conio.h>

using namespace std;

pair<char,char> conversion(int a)
{char M,m;
    if (a>=65 && a<=90) 
	{M=char(a);
	 m=char(a+32);
	}
	else
	{m=char(a);
	 M=char(a-32);
	}
	return pair<char,char>(M,m);
}
void main()
{	pair<char,char> p;
    int n;
    
    do {
    cout<<"Introduce un numero entre 65...90 o 97...122 ";
    cin>>n;
	} while (n<65 || (n>90 && n<97) || n>122);
	
	p=conversion(n);
	cout<<"Mayuscula "<<p.first<<endl;
	cout<<"Minuscula "<<p.second<<endl;
	getch();
}
