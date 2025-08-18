/*Escreva uma função recursiva, ImprimeSerie(i,j,k: inteiro),
que imprime na tela a série de valores do intervalo [i,j],
com incremento k.*/

#include <stdio.h>
#include <stdlib.h>

void imprimeSerie(int i, int j, int k);

int main()
{
    int i, j, k;
    printf("Digite os valores de i, j e k: ");
    scanf("%d %d %d", &i, &j, &k);
    imprimeSerie(i, j, k);
    return 0;
}

void imprimeSerie(int i, int j, int k)
{
    if (i <= j)
    {
        printf("%d ", i);
        imprimeSerie(i + k, j, k);
    }
}
