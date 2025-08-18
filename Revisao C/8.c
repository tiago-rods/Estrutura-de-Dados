/*Faça um algoritmo que leia uma matriz quadrada de no
máximo 3 posições e determine qual é o maior e o
menor valor da linha 2 e qual é o maior e o menor valor
da coluna 1.
*/
#include <stdio.h>

int main()
{
    int matriz[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Digite o elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    int maiorLinha = matriz[1][0];
    int menorLinha = matriz[1][0];
    int maiorColuna = matriz[0][1];
    int menorColuna = matriz[0][1];

    for(int i = 0; i < 3; i++)
    {
        if (matriz[1][i] > maiorLinha)
            maiorLinha = matriz[1][i];
        if (matriz[1][i] < menorLinha)
            menorLinha = matriz[1][i];
    }

    for(int i = 0; i < 3; i++)
    {
        if (matriz[i][1] > maiorColuna)
        {
            maiorColuna = matriz[i][1];

        }
        if (matriz[i][1] < menorColuna)
        {
            menorColuna = matriz[i][1];
        }
    }

    printf("Maior valor da linha 2: %d\n", maiorLinha);
    printf("Menor valor da linha 2: %d\n", menorLinha);
    printf("Maior valor da coluna 1: %d\n", maiorColuna);
    printf("Menor valor da coluna 1: %d\n", menorColuna);

}