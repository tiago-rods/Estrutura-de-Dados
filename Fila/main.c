#include "Fila.h"
#include "Pilha.h" // Se Pilha não for usada, pode remover
#include <stdio.h>
#include <stdlib.h>

// Sua função pilhasMaiorQue20 (apenas para referência, estava comentada)
void pilhasMaiorQue20(Fila* f, Pilha** pMaior, Pilha** pMenor) {
    *pMaior = CriaPilha();
    *pMenor = CriaPilha();
    if (vaziaFila(f)) return;

    while(!vaziaFila(f)){
        int valor = retiraFila(f);
        if(valor > 20){
            push(*pMaior, valor);
        } else {
            push(*pMenor, valor);
        }
    }
}

int main(){
    Fila* f = criaFila();

    insereFila(f, 10);
    insereFila(f, 15);
    insereFila(f, 20);
    insereFila(f, 25);
    insereFila(f, 30);


    printf("Fila original: ");
    imprimeFila(f); // Fila: [10, 15, 20, 25, 30]

    Fila* fPares;
    Fila* fImpares;
    separaParesImpares(f, &fPares, &fImpares); // 'f' continua [10, 15, 20, 25, 30]

    printf("Fila de pares: ");
    imprimeFila(fPares);
    printf("Fila de impares: ");
    imprimeFila(fImpares);

    
    inverteFila(f); // 'f' agora é [30, 25, 20, 15, 10]
    printf("Fila invertida (a fila original 'f' agora esta invertida): ");
    imprimeFila(f); // Imprime a fila 'f' invertida


    clearFila(f);
    clearFila(fPares);
    clearFila(fImpares);


    return 0;
}