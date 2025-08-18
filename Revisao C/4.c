//Escreva um programa que calcule e imprima o valor de S:

#include <stdio.h>
#include <stdlib.h>

int sqr(int num);

int main()
{
    float soma = 0;
    int sinal = 1; 
    
    for(int i = 1; i <= 10; i++)
    {
        soma += sinal * (float)i / sqr(i);
        sinal = -sinal; 
    }

    printf("O resultado da soma é: %.6f\n", soma);
    return 0;
}

int sqr(int num)
{
    return num * num;
}