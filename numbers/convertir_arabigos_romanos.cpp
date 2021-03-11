#include<stdio.h>
#include<string.h>
#include<conio.h>

int main()
{
    int M,C,D,U;
    int numero;
    char unidad[5];
    char decena[5];
    char centena[5];
    char millar[4];
    printf("\nPrograma conversor");
    printf("\n==================");
    printf("\nDe numeros arabigos---> a numeros Romanos");
    do
    {
    printf("\n\nIntroduce tu numero[Del 1 al 3999]:");
    scanf("%i",&numero);
    if(numero>3999)
    printf("\nTe dije que introducieras un numero entre el 1 y el 3999");
    }while(numero>3999);
    U=numero%10;
    D=(numero%100)/10;
    C=(numero/100)%10;
    M=numero/1000;
    switch(U)
    {
       case 1:
       strcpy(unidad,"I");
       break;
       case 2:
       strcpy(unidad,"II");
       break;
       case 3:
       strcpy(unidad,"III");
       break;
       case 4:
       strcpy(unidad,"IV");
       break;
       case 5:
       strcpy(unidad,"V");
       break;
       case 6:
       strcpy(unidad,"VI");
       break;
       case 7:
       strcpy(unidad,"VII");
       break;
       case 8:
       strcpy(unidad,"VIII");
       break;
       case 9:
       strcpy(unidad,"IX");
       break;
       default:
       strcpy(unidad,"\0");
    }
    switch(D)
    {
       case 1:
       strcpy(decena,"X");
       break;
       case 2:
       strcpy(decena,"XX");
       break;
       case 3:
       strcpy(decena,"XXX");
       break;
       case 4:
       strcpy(decena,"XL");
       break;
       case 5:
       strcpy(decena,"L");
       break;
       case 6:
       strcpy(decena,"LX");
       break;
       case 7:
       strcpy(decena,"LXX");
       break;
       case 8:
       strcpy(decena,"LXXX");
       break;
       case 9:
       strcpy(decena,"XC");
       break;
       default:
       strcpy(decena,"\0");
    }
    switch(C)
    {
       case 1:
       strcpy(centena,"C");
       break;
       case 2:
       strcpy(centena,"CC");
       break;
       case 3:
       strcpy(centena,"CCC");
       break;
       case 4:
       strcpy(centena,"CD");
       break;
       case 5:
       strcpy(centena,"D");
       break;
       case 6:
       strcpy(centena,"DC");
       break;
       case 7:
       strcpy(centena,"DCC");
       break;
       case 8:
       strcpy(centena,"DCCC");
       break;
       case 9:
       strcpy(centena,"CM");
       break;
       default:
       strcpy(centena,"\0");
    }
    switch(M)
    {
       case 1:
       strcpy(millar,"M");
       break;
       case 2:
       strcpy(millar,"MM");
       break;
       case 3:
       strcpy(millar,"MMM");
       break;
       default:
       strcpy(millar,"\0");
    }
    printf("El numero: %i convertido a romanos es: %s%s%s%s",numero,&millar,&centena,&decena,&unidad);
	 getch();
}
