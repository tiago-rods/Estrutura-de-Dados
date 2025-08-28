//Conte os Elementos da Pilha

#include <stdio.h>
#include "Pilhas.h"

int contaElementos(Pilha* p);

int main(){
    Pilha *p1 = CriaPilha();
    push(p1, 10);
    push(p1, 20);
    push(p1, 30);
    printf("Total de elementos na pilha: %d\n", contaElementos(p1));

    Pilha *p2 = CriaPilha();
    push(p2, 1);
    push(p2, 2);
    push(p2, 3);
    imprimePilha(p2);
    Pilha *pInvertida = invertePilha(p2);
    imprimePilha(pInvertida);
    
    Pilha *p3 = CriaPilha();
    push(p3, 100);
    push(p3, 200);
    push(p3, 300);
    imprimePilha(p3);
    removeElemento(p3, 200);
    imprimePilha(p3);

    Pilha p4 = *CriaPilha();
    Pilha p5 = *CriaPilha();
    push(&p4, 1);
    push(&p4, 2);
    push(&p4, 3);
    push(&p5, 4);
    push(&p5, 5);
    push(&p5, 6);
    push(&p5, 7);
    printf("Resultado da comparação: %d\n", comaparaPilhas(&p4, &p5));

    int num = 458;
    Pilha *p8 = guardaDigitos(num);
    imprimePilha(p8);

    int recuperado = recuperaDigitos(p8);
    printf("Número recuperado: %d\n", recuperado);

    return 0;
}


