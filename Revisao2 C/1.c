/*Elabore um programa que contenha uma função recebe 3
valores float (n1, n2, n3) e retornar o (x*x)+y+z. Os valores
devem ser lidos no programa principal, o resultado também
deve ser impresso no principal.
• Construa essa função de duas maneiras diferentes,
respeitando os cabeçalhos abaixo:
a. float calculo(float x,float y, float z)
b. void calculo(float x, float y, float z, float *r)*/

#include <stdio.h>
#include <stdlib.h>

float calculoParametro(float x, float y, float z);
void calculoReferencia(float x, float y, float z, float *r);

int main()
{
    float n1, n2, n3, resultado;
    printf("Digite o primeiro numero: ");
    scanf("%f", &n1);
    printf("Digite o segundo numero: ");
    scanf("%f", &n2);
    printf("Digite o terceiro numero: ");
    scanf("%f", &n3);

    resultado = calculoParametro(n1, n2, n3);
    printf("Resultado (parametro): %f\n", resultado);

    calculoReferencia(n1, n2, n3, &resultado);
    printf("Resultado (referencia): %f\n", resultado);

    return 0;
}

float calculoParametro(float x, float y, float z) {
    return (x * x) + y + z;
}
void calculoReferencia(float x, float y, float z, float *r) {
    *r = (x * x) + y + z;
}