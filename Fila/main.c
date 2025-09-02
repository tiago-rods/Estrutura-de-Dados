#include "Fila.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Fila* f = criaFila();

    insereFila(f, 10);
    insereFila(f, 15);
    insereFila(f, 20);
    insereFila(f, 25);
    insereFila(f, 30);

    printf("Fila original: ");
    imprimeFila(f);

    Fila* fPares;
    Fila* fImpares;
    separaParesImpares(f, &fPares, &fImpares);

    printf("Fila de pares: ");
    imprimeFila(fPares);
    printf("Fila de impares: ");
    imprimeFila(fImpares);

    Fila* fInvertida = inverteFila(f);
    printf("Fila invertida: ");
    imprimeFila(fInvertida);

    // Libera a memória
    clearFila(f);
    clearFila(fPares);
    clearFila(fImpares);
    clearFila(fInvertida);

    return 0;
}