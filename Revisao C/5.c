/*Dada a sequência matemática de números 2, 3, 5,8,13, 21....
Construa um programa que calcule a soma desta sequência
para os N primeiros termo onde, N é fornecido pelo usuário.
• Exemplo: N=5 S= 2+3+5+8+13 =31*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    int soma = 0, anterior = 1, atual = 2;

    printf("Digite quantos termos deseja serem somados: \n");
    scanf("%d", &N);

    if(N <= 0)
    {
        printf("Número deve ser maior que 0\n");
        exit(0);
    }

    for(int i = 0; i < N; i++)
    {
        soma += atual; 
        
        int proximo = anterior + atual;
        anterior = atual;
        atual = proximo;
    }

    printf("A soma é %d\n", soma);
    return 0;
}