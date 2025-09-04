#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

/*
    PILHA (implementação com lista encadeada)

    FUNÇÕES DE MANIPULAÇÃO DE PILHA
    - Pilha* CriaPilha(void)                     // Cria a pilha (retorna NULL em erro)
    - No* inserirInicio(No* t, int a)            // Auxiliar de inserção (retorna NULL em erro)
    - void push(Pilha* p, int v)                 // Empilha (aborta em erro grave)
    - No* removerInicio(No* l)                   // Auxiliar de remoção (retorna o próximo, NULL em erro)
    - int pop(Pilha* p)                          // Desempilha e retorna o valor (aborta se vazia)
    - Pilha* liberaPilha(Pilha* p)               // Libera toda a pilha e retorna NULL
    - void imprimePilha(Pilha* p)                // Imprime a pilha do topo ao fundo
    - int vaziaPilha(Pilha* p)                   // 1 se vazia (ou p == NULL), 0 caso contrário
*/

// ======================
// Tipos
// ======================
typedef struct no {
    int info;
    struct no* prox;
} No;

typedef struct pilha {
    No* Topo;
} Pilha;

// ======================
// Protótipos
// ======================
Pilha* CriaPilha(void);
No* inserirInicio(No* t, int a);
void push(Pilha* p, int v);
No* removerInicio(No* aux);
Pilha* liberaPilha(Pilha* p);
int vaziaPilha(Pilha* p);
int pop(Pilha* p);
void imprimePilha(Pilha* p);

// ======================
// Implementações
// ======================

Pilha* CriaPilha(void)
{
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if (p == NULL) {
        printf("Erro: falha ao alocar Pilha em CriaPilha.\n");
        return NULL;
    }
    p->Topo = NULL;
    return p;
}

No* inserirInicio(No* t, int a)
{
    No* aux = (No*) malloc(sizeof(No));
    if (aux == NULL) {
        printf("Erro: falha ao alocar No em inserirInicio.\n");
        return NULL;
    }

    aux->info = a;
    aux->prox = t;
    return aux;
}

void push(Pilha* p, int v)
{
    if (p == NULL) {
        printf("Erro: pilha inexistente (NULL) em push.\n");
        exit(1);
    }

    No* novo = inserirInicio(p->Topo, v);
    if (novo == NULL) {
        printf("Erro: falha ao empilhar (malloc retornou NULL) em push.\n");
        exit(1);
    }

    p->Topo = novo;
}

No* removerInicio(No* aux)
{
    if (aux == NULL) {
        printf("Erro: no NULL passado a removerInicio.\n");
        return NULL;
    }

    No* prox = aux->prox;
    free(aux);
    return prox;
}

Pilha* liberaPilha(Pilha* p)
{
    if (p == NULL) {
        return NULL;
    }

    No* atual = p->Topo;
    while (atual != NULL) {
        atual = removerInicio(atual);
    }

    free(p);
    return NULL; // convenção: permite p = liberaPilha(p);
}

int vaziaPilha(Pilha* p)
{
    if (p == NULL) {
        return 1;
    }
    return (p->Topo == NULL) ? 1 : 0;
}

int pop(Pilha* p)
{
    if (p == NULL || p->Topo == NULL) {
        printf("\n\n\t==> Pilha VAZIA ou inexistente, impossivel continuar.\n");
        exit(1);
    }

    No* topo = p->Topo;
    int v = topo->info;
    p->Topo = removerInicio(topo); // removerInicio já faz free(topo) e retorna o próximo
    return v;
}

void imprimePilha(Pilha* p)
{
    if (p == NULL) {
        printf("\n\n\t==> PILHA: pilha inexistente (NULL).\n");
        return;
    }

    No* aux = p->Topo;
    printf("\n\n\t==> PILHA (Topo -> Base): ");
    while (aux != NULL) {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

int contaElementos(Pilha* p) {
    int contador = 0;
    No* atual = p->Topo;

    while (atual != NULL) {
        contador++;
        atual = atual->prox;
    }

    return contador;
}
Pilha *invertePilha(Pilha *p){
    if (p == NULL){
        printf("Pilha vazia\n");
        return NULL;
    }
    Pilha *pilhaInvertidaResultante = CriaPilha(); // Renomeei para maior clareza

    while (!vaziaPilha(p)){
        push(pilhaInvertidaResultante, pop(p));
    }
    return pilhaInvertidaResultante;
}

Pilha *removeElemento(Pilha *p, int elemento) {
    if (vaziaPilha(p)) {
        printf("Pilha vazia\n");
        return NULL;
    }
    Pilha *temp = CriaPilha();
    int encontradoFlag = 0;

    while(!vaziaPilha(p)){
        int valorTemp = pop(p);
        if(valorTemp == elemento && !encontradoFlag){
            encontradoFlag = 1;
        } else {
            push(temp, valorTemp);
        }
    }
    while(!vaziaPilha(temp)){
        push(p, pop(temp));
    }
    liberaPilha(temp);

    return p;
}

int comaparaPilhas(Pilha *p1, Pilha *p2){
    if(vaziaPilha(p1) || vaziaPilha(p2)){
        printf("Pilha vazia\n");
        return 0;
    }
    //se ambas tiverem a mesma quantidade de elementos, retorna 0
    //se a 1 for maior, retorna 1, se a 2 for maior, retorna 2
    int len1 = contaElementos(p1),
    len2 = contaElementos(p2);

    // Compara os tamanhos das pilhas
    //se len1 > len2, expressão vale 1, se len1 < len2, expressão vale -1 e se forem iguais, vale 0
    switch((len1 > len2) - (len1 < len2)){
        case(0):
            return 0;
            break;
        case(1):
            return 1;
            break;
        case(-1):
            return 2;
            break;
    }
}

Pilha *guardaDigitos(int num){
    Pilha *p = CriaPilha();
    while(num > 0){
        push(p, num % 10);
        num /= 10;
    }
    return p;
}

int recuperaDigitos(Pilha *p){
    int num = 0;
    while(!vaziaPilha(p)){
        num *= 10;
        num += pop(p);
    }
    return num;
}


#endif // PILHA_H_INCLUDED