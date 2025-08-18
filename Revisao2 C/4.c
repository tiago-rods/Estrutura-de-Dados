/*Determine um algoritmo iterativo e recursivo que calcule
a some de N números ímpares*/

#include <stdio.h>
#include <stdlib.h>

int somaImparesIterativo(int n);
int somaImparesRecursivo(int n);

int main()
{
    int n;
    printf("Digite um numero positivo: ");
    scanf("%d", &n);

    printf("Soma dos %d primeiros numeros impares (iterativo): %d\n", n, somaImparesIterativo(n));
    printf("Soma dos %d primeiros numeros impares (recursivo): %d\n", n, somaImparesRecursivo(n));
}

int somaImparesIterativo(int n)
{
    if(n<=0){
    return 0;
    }
    int soma = 0;
    int impar = 1;
    for (int i = 1; i <= n; i ++)
    {
        soma += impar;
        impar += 2;
    }
    return soma;    
}

int somaImparesRecursivo(int n)
{
    if (n <= 0) return 0;
    return (2 * n - 1) + somaImparesRecursivo(n - 1);
}
