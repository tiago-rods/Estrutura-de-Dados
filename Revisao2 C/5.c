// Faça uma função recursiva que permita somar os
// elementos de um vetor de inteiros.
#include <stdio.h>

#define TAM 5


void lerVetor(int *vetor);
int somaVetorRecursivo(int *vetor, int tamanho);

int main()
{
    int vetor[TAM], len = TAM ;
    lerVetor(vetor);
    int soma = somaVetorRecursivo(vetor, len);
    printf("A soma dos elementos do vetor é: %d\n", soma);
    return 0;
}


void lerVetor(int *vetor)
{
    for(int i = 0; i < TAM; i++)
    {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
}

int somaVetorRecursivo(int *vetor, int tamanho)
{   
    if (tamanho <= 0) {
        return 0;
    }
    return vetor[0] + somaVetorRecursivo(vetor + 1, tamanho - 1);
}