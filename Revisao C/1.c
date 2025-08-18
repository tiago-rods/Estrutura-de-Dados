//Elabore um programa em C que leia um número inteiro e
// determine quantos dígitos 7 possui esse número

#include <stdio.h>
#include <stdlib.h>


int main()
{
    int num, cont = 0, orig;

    printf("Digite um número:");
    scanf("%i", &num);

    orig = num;

    if(num<10 && num==7){
        cont == 1;
    }
    else
    {
        while(num>0)
        {
            if(num%10==7) {
                cont++;
            }
            num/=10;
        }
    }
    printf("o numero %d de digitos iguais a 7 é %d digitos \n",orig, cont);

    return 0;
}

