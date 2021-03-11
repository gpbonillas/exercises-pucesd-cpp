#include<iostream.h>
int num;
int rec(int c);
int c=0;
void main(){
  int res=0;
  cin>>num;
  res=rec (c);
}

int rec(int c){
  if(c<=num){
    cout<<c;
    return rec(c++);
  } else{
    return 0;
  }
}
