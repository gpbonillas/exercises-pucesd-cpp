# include<stdio.h>
int main()
{
int i;
printf("Los Caracteres ASCII son: \n");
for(i=32;i<=164;i++)  {
    if(i<97 || i>122)
        printf("%c %d \t",i,i);
    }
return 0;
}