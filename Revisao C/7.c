/*Preencher um vetor de 8 elementos inteiros. Mostrar o vetor
e informar quantos números são maiores que 30.
*/
#include <stdio.h>

#define TAM 8

int main()
{
    int vetor[TAM];

    for(int i = 0; i < TAM; i++)
    {
        printf("Digite o %dº elemento do vetor: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    printf("Vetor: ");
    for(int i = 0; i < TAM; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    int contador = 0;
    for(int i = 0; i < TAM; i++)
    {
        if(vetor[i] > 30)
        {
            contador++;
        }
    }
    printf("Quantidade de elementos maiores que 30: %d\n", contador);

    return 0;
}