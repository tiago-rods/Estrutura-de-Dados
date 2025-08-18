/*
Fazer um programa em C para ler um vetor de inteiros
positivos de 15 posições, no máximo. Imprimir a quantidade
de números pares e a quantidade de múltiplos de 5
*/
#include <stdio.h>
#include <stdlib.h>

#define TAM 15

int main()
{
    int vetor[TAM];
    int tamanho;
    int contPares = 0, contMult5 = 0;

    printf("Digite o tamanho máximo do vetor (maximo 15):");
    scanf("%d",&tamanho);

    for(int i = 0; i < tamanho; i++)
    {
        printf("Numero %d: ", i + 1);
        scanf("%d",&vetor[i]);

        if(vetor[i] % 2 == 0)
        {
            contPares++;
        }
        if(vetor[i] % 5 == 0)
        {
            contMult5++;
        }
    }

    printf("\nQuantidade de números pares: %d\n", contPares);
    printf("Quantidade de múltiplos de 5: %d\n", contMult5);
    
    return 0;  
}