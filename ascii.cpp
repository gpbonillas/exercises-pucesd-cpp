#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

void main (void)
{
 char x;
 int i,c,f;
 clrscr();
 f=1;c=1;
 for(i=0;i<256;i++)
  {
    gotoxy(c,f);
    printf("%3d %c\n",i,i);
    f=f+1;
    if(f>23)
    {
      f=1;
      c=c+6;
    }
  }

 getch();
}

