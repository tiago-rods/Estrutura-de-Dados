//Elabore uma função recursiva que determina o elemento
//máximo de um vetor
#include <stdio.h>

void lerVetor(int *vetor, int len);
int maxVetor(int *vetor, int len);

int main(){
    int vetor[10];

    lerVetor(vetor,10);
    int max = maxVetor(vetor,10);
    printf("O elemento máximo do vetor é: %d\n", max);
}

void lerVetor(int *vetor, int len){
    for(int i = 0; i < len; i++){
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
}

int maxVetor(int *vetor, int len){
    if(len == 1)
    return vetor[0];
    else {
        int maxRestante = maxVetor(vetor + 1, len -1);
        if(vetor[0] > maxRestante)
            return vetor[0];
        else
            return maxRestante;
    }
}