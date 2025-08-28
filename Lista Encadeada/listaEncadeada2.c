#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct lista {
    int info;
    struct lista* prox;
} lista;

// Protótipos das funções
lista *inicializa();
lista *criaLista(int valor);
void insereFinal(lista **head, int valor);
void retiraFinal(lista **head);
int quantidadeImpares(lista *lt);
lista *uniaoLista(lista *lt1, lista *lt2);
int contemElemento(lista *list, int valor);
void imprimeLista(const lista *lt);
lista *apagaLista(lista *aux); 
void menu();


int main(){
    menu();
    return 0;
}


lista *inicializa(){
    return NULL;
}

lista *criaLista(int valor){ //funcao para criar novo no
    lista *temp = (lista*)malloc(sizeof(lista)); //aloca o tamanho de lista
    if(temp == NULL){
        printf("erro ao alocar memória\n"); // Verifica se a alocação foi bem-sucedida
        exit(-1);
    }
    temp->info = valor;
    temp->prox = NULL; //o proximo no do novo no e inicialmente NULL
    return temp;
}

void insereFinal(lista **head, int valor){
    lista *novaLista = criaLista(valor);

    //caso 1, lista vazia
    //O novo nó se torna a cabeça da lista
    if(*head == NULL){
        *head = novaLista;
        printf("Elemento %d inserido com sucesso na lista vazia.\n", valor);
        return;
    }

    //caso 2, lista não está vazia
    //Percorre a lista até o ultimo nó
    lista *atual = *head; //começa pelo primeiro no
    while(atual->prox != NULL){
        atual = atual->prox;
    }
    atual->prox = novaLista;
    printf("Elemento %d inserido com sucesso no final.\n", valor);
}

void retiraFinal(lista **head){
    // CORREÇÃO: Usar *head para verificar se a lista está vazia
    if (*head == NULL) {
        printf("A lista já está vazia. Nada a remover.\n");
        return; // É void, não retorna nada
    }

    //caso a lista tenha somente um elemento
    if((*head)->prox == NULL){ //verifica se o proximo elemento é NULL
        printf("Removendo o único elemento (%d). Lista agora vazia.\n", (*head)->info);
        free(*head); //libera o espaço do unico no
        *head = NULL; //lista agora, vazia
        return;
    }

    //caso a lista tenha multiplos elementos
    lista *atual = *head;//começa no primeiro elemento
    lista *anterior = NULL;

    while(atual->prox != NULL){
        anterior = atual; //anterior se torna o atual
        atual = atual->prox; //atual vai ao proximo
    }
    //apos o loop, atual estara apontando para o ultimo no
    //anterior para o penultimo no
    printf("Removendo o último elemento (%d).\n", atual->info);
    anterior->prox = NULL;
    free(atual);
}

int quantidadeImpares(lista *lt){
    int cont = 0;
    if (lt == NULL) {
        printf("Lista vazia!\n"); // Melhor imprimir aqui, pois a função pode ser chamada sem retorno de main
        return 0;
    }

    for(lista *p = lt; p != NULL; p = p->prox){
        // Usar != 0 é mais robusto para ímpares (inclui negativos como -3 % 2 = -1)
        if(p->info % 2 != 0){
            cont++;
        }
    }
    return cont;
}

int contemElemento(lista *list, int valor){
    lista *atual = list;
    while(atual != NULL){
        if(atual->info == valor){
            return 1; //elemento encontrado
        }
        atual = atual->prox;
    }
    return 0;//elemento nao encontrado
}

// Corrigido o loop da segunda lista e o retorno
lista *uniaoLista(lista *lt1, lista *lt2){
    lista *uniao = NULL; //inicializa a lista de uniao vazia;

    //processar a primeira lista
    lista *atual1 = lt1;
    while(atual1 != NULL){
        if(!contemElemento(uniao, atual1->info)){ //verifica se elemento existena lista de uniao
            insereFinal(&uniao, atual1->info); //se nao existir, insere ao final da lista
        }
        atual1 = atual1->prox;
    }

    //processar a segunda lista
    lista *atual2 = lt2;
    while(atual2 != NULL){ 
        if(!contemElemento(uniao, atual2->info)){
            insereFinal(&uniao, atual2->info);
        }
        atual2 = atual2->prox; // <<--- Incremento dentro do loop
    }
    return uniao; // <<--- Retorno adicionado
}

void imprimeLista(const lista *lt) {
    if (lt == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    const lista *temp = lt;
    printf("Lista: "); // Adicionado "Lista: "
    while (temp != NULL) {
        printf("%d", temp->info);
        if (temp->prox != NULL) printf(" -> "); // Mais legível
        temp = temp->prox;
    }
    printf(" -> NULL\n"); // Adicionado " -> NULL" no final
}

// Função para apagar/liberar a memória da lista
lista *apagaLista(lista *aux) {
    lista *temp;
    if (aux == NULL) { // Se já é NULL, não precisa fazer nada
        return NULL;
    }
    while (aux != NULL) {
        temp = aux;
        aux = aux->prox;
        free(temp);
    }
    printf("Lista liberada.\n");
    return NULL; // Retorna NULL para indicar que a lista está vazia
}

void menu(){
    lista *listaA = inicializa();
    lista *listaB = inicializa();
    lista *listaUniao = inicializa(); // Variável para armazenar a lista de união

    int escolha;
    int valor;

    do{
        printf("\n\t=== Menu de Operações com Listas Encadeadas ===\n");
        printf("\t1. Inserir elemento no final da Lista A\n");
        printf("\t2. Inserir elemento no final da Lista B\n");
        printf("\t3. Remover elemento do final da Lista A\n");
        printf("\t4. Remover elemento do final da Lista B\n");
        printf("\t5. Contar números ímpares na Lista A\n");
        printf("\t6. Contar números ímpares na Lista B\n");
        printf("\t7. Realizar União de Lista A e Lista B (sem repetições)\n");
        printf("\t8. Imprimir Lista A\n");
        printf("\t9. Imprimir Lista B\n");
        printf("\t10. Imprimir Lista União\n");
        printf("\t0. Sair\n");
        printf("\tEscolha uma opção: ");
        // Verifica se a leitura foi bem-sucedida
        if (scanf("%d", &escolha) != 1) {
            printf("Entrada inválida. Por favor, digite um número.\n");
            // Limpa o buffer de entrada para evitar loop infinito em caso de entrada não-numérica
            while (getchar() != '\n');
            continue; // Pula para a próxima iteração do loop do-while
        }

        switch(escolha){
            case 1:
                printf("Digite o valor a ser inserido na Lista A: ");
                scanf("%d", &valor);
                insereFinal(&listaA, valor);
                break;
            case 2:
                printf("Digite o valor a ser inserido na Lista B: ");
                scanf("%d", &valor);
                insereFinal(&listaB, valor);
                break;
            case 3:
                retiraFinal(&listaA);
                break;
            case 4:
                retiraFinal(&listaB);
                break;
            case 5:
                printf("Quantidade de ímpares na Lista A: %d\n", quantidadeImpares(listaA));
                break;
            case 6:
                printf("Quantidade de ímpares na Lista B: %d\n", quantidadeImpares(listaB));
                break;
            case 7:
                // Libera a lista união anterior, se houver
                if(listaUniao != NULL){
                    listaUniao = apagaLista(listaUniao); // <<--- CORREÇÃO AQUI
                }
                listaUniao = uniaoLista(listaA, listaB);
                printf("União das listas realizada com sucesso.\n"); // <<--- Feedback visual
                imprimeLista(listaUniao); // <<--- Imprime a lista de união imediatamente
                break;
            case 8:
                printf("Conteúdo da Lista A:\n");
                imprimeLista(listaA);
                break;
            case 9:
                printf("Conteúdo da Lista B:\n");
                imprimeLista(listaB);
                break;
            case 10:
                printf("Conteúdo da Lista União:\n");
                imprimeLista(listaUniao);
                break;
            case 0:
                printf("Saindo do programa. Liberando memória...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                // Limpa o buffer de entrada para evitar loop infinito em caso de entrada não-numérica
                while (getchar() != '\n');
                break;
        }
    } while (escolha != 0);

    // Libera a memória de todas as listas antes de sair
    listaA = apagaLista(listaA);
    listaB = apagaLista(listaB);
    listaUniao = apagaLista(listaUniao);
    printf("Todas as listas foram liberadas. Encerrando!\n");
}