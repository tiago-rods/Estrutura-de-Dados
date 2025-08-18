/*
O quadrado de um número natural N é dado pela soma dos N
primeiros números ímpares consecutivos. Por exemplo:
3² = 1+3+5=9
4² = 1+3+5+7=16
Elabore um programa que leia um número natural N e calcule
o seu quadrado usando o cálculo acima.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, soma = 0;
    printf("Digite um número para receber seu quadrado: ");
    scanf("%d", &num);

    if(num < 0) num = -num;

    if(num == 0) {
        soma = 0;
    }
    else {
        // Soma os N primeiros números ímpares
        for(int i = 1; i <= 2 * num - 1; i += 2) { 
            soma += i; 
        }
    }

    printf("O quadrado de %d é %d\n", num, soma);
    return 0;
}