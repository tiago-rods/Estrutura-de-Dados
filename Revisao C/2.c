/*
Construa um programa que leia vários números inteiros
positivos. O programa será encerrado quando um número
NÃO positivo for digitado e irá calcular:
• A quantidade de números lidos
• A soma dos números que são múltiplos de 3 maiores que
10
• A quantidade de múltiplos de 3
• O percentual de múltiplos de 7
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, cont = 0, div3 = 0, soma = 0, mult7 = 0;
    float percentualDiv7;

    printf("Digite números inteiros positivos (número não positivo para sair):\n");

    do {
        printf("Digite um número: ");
        scanf("%d", &num);

        // Se número não é positivo, encerra o loop
        if(num <= 0) {
            break;
        }

        // Conta o número lido
        cont++;

        // Verifica se é múltiplo de 3
        if(num % 3 == 0) {
            div3++;
            // Se múltiplo de 3 E maior que 10, soma
            if(num > 10) {
                soma += num;
            }
        }

        // Verifica se é múltiplo de 7
        if(num % 7 == 0) {
            mult7++;
        }

    } while(num >= 0);

    // Exibe os resultados apenas se foram lidos números
    if(cont > 0) {
        percentualDiv7 = (float)mult7 / cont * 100;

        printf("\n=== RESULTADOS ===\n");
        printf("Quantidade de números lidos: %d\n", cont);
        printf("Soma dos múltiplos de 3 maiores que 10: %d\n", soma);
        printf("Quantidade de múltiplos de 3: %d\n", div3);
        printf("Percentual de múltiplos de 7: %.2f%%\n", percentualDiv7);
    } else {
        printf("Nenhum número positivo foi digitado.\n");
    }

    return 0;
}