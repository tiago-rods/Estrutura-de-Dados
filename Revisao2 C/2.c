// Elabore um programa que leia 3 números inteiros. Este
// programa deverá ter uma função que retorne o fatorial de um
// número. Use essa função, para calcular o fatorial dos números
// lidos (imprima no programa principal)

#include <stdio.h>
#include <stdlib.h>

int fatorial(int fat);

int main()
{
    int x, y ,z;
    printf("Digite o números os quais o fatorial será calculado:");
    scanf("%d",&x);
    scanf("%d",&y);
    scanf("%d",&z);
    printf("Fatorial de %d = %d\n", x, fatorial(x));
    printf("Fatorial de %d = %d\n", y, fatorial(y));
    printf("Fatorial de %d = %d\n", z, fatorial(z));
}

int fatorial(int fat)
{
    if (fat == 0)
        return 1;
    else
        return fat * fatorial(fat - 1);
}