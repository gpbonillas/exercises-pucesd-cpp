#include<iostream.h>
#include<string.h>
int c, d, n, s;
void main(){
int c=1, n=2;
cout<<"Los 3 primeros numeros perfectos son: \n\n";
while (c<=3){
int s=0, d=1;
while (n>d){
if(n%d==0){
s=s+d;
}
d=d+1;
}

if(s==n){
cout<<n<<"\t";
c=c+1;
}
n=n+1;
}
}

