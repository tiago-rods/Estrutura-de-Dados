#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Definição da estrutura da lista encadeada */
typedef struct lista {
    int info;
    struct lista* prox;
} lista;

/* Protótipos das funções pedidas */
lista *inicializa(void);
lista *inserir(lista *recebido, int valor);               // insere no início
lista *removeElemento(lista *rm);                         // remove do início
void imprimeLista(const lista *lt);                       // imprime a lista
bool buscaElemento(lista *busca, int num);                // retorna true/false
bool verificaVazia(lista *verif);                         // retorna true se vazia
int quantidadeParametros(lista *aux);                     // quantidade de elementos
int somaParametros(lista *lt);                            // soma dos elementos
lista *apagaLista(lista *aux);                            // apaga toda a lista
int lerInteiro(const char *mensagem);


int main() {
    lista *lt = inicializa();
    int opcao;

    do {
        printf("\n===== MENU LISTA ENCADEADA =====\n");
        printf("1 - Inserir no início\n");
        printf("2 - Remover do início\n");
        printf("3 - Imprimir lista\n");
        printf("4 - Buscar elemento (retorna 1/0)\n");
        printf("5 - Verificar se a lista está vazia (retorna 1/0)\n");
        printf("6 - Quantidade de elementos\n");
        printf("7 - Somar elementos\n");
        printf("8 - Apagar toda a lista\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");

        if (scanf("%d", &opcao) != 1) {
            // limpar buffer e continuar
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Opção inválida. Tente novamente.\n");
            continue;
        }

        switch (opcao) {
            case 1: {
                int valor = lerInteiro("Digite o valor a inserir: ");
                lt = inserir(lt, valor);
                printf("Inserido %d no início.\n", valor);
            } break;

            case 2: {
                lt = removeElemento(lt);
            } break;

            case 3: {
                printf("Lista: ");
                imprimeLista(lt);
            } break;

            case 4: {
                int num = lerInteiro("Digite o valor a buscar: ");
                bool achou = buscaElemento(lt, num);
                printf("%d\n", achou ? 1 : 0);
            } break;

            case 5: {
                bool vazia = verificaVazia(lt);
                printf("%d\n", vazia ? 1 : 0);
            } break;

            case 6: {
                int qtd = quantidadeParametros(lt);
                printf("Quantidade de elementos: %d\n", qtd);
            } break;

            case 7: {
                int soma = somaParametros(lt);
                printf("Soma dos elementos: %d\n", soma);
            } break;

            case 8: {
                lt = apagaLista(lt);
                printf("Lista apagada.\n");
            } break;

            case 0: {
                // Sair: liberar memória antes
                lt = apagaLista(lt);
                printf("Encerrando...\n");
            } break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}

/* Implementações */
lista *inicializa(void) {
    return NULL;
}

lista *inserir(lista *recebido, int valor) {
    lista *novo = (lista*)malloc(sizeof(lista));
    if (!novo) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    novo->info = valor;
    novo->prox = recebido;  // novo aponta para o antigo início
    return novo;            // novo passa a ser a nova cabeça
}

lista *removeElemento(lista *rm) {
    if (rm == NULL) {
        printf("A lista já está vazia. Nada a remover.\n");
        return NULL;
    }
    lista *novoInicio = rm->prox;
    free(rm);
    return novoInicio;
}

lista *apagaLista(lista *aux) {
    lista *temp;
    while (aux != NULL) {
        temp = aux;
        aux = aux->prox;
        free(temp);
    }
    return NULL;
}

void imprimeLista(const lista *lt) {
    if (lt == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    const lista *temp = lt;
    while (temp != NULL) {
        printf("%d", temp->info);
        if (temp->prox != NULL) printf("->");
        temp = temp->prox;
    }
    printf("\n");
}

bool buscaElemento(lista *busca, int num) {
    for (lista *p = busca; p != NULL; p = p->prox) {
        if (p->info == num) {
            return true;  // encontrado
        }
    }
    return false;         // não encontrado
}

bool verificaVazia(lista *verif) {
    return verif == NULL; // true se vazia, false caso contrário
}

int quantidadeParametros(lista *aux) {
    int cont = 0;
    for (lista *p = aux; p != NULL; p = p->prox) {
        cont++;
    }
    return cont;
}

int somaParametros(lista *lt) {
    int soma = 0;
    for (lista *p = lt; p != NULL; p = p->prox) {
        soma += p->info;
    }
    return soma;
}

/* Função auxiliar para ler um inteiro com verificação simples */
int lerInteiro(const char *mensagem) {
    int valor;
    int lidos;
    do {
        printf("%s", mensagem);
        lidos = scanf("%d", &valor);
        if (lidos != 1) {
            // limpar buffer em caso de entrada inválida
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Entrada inválida. Tente novamente.\n");
        }
    } while (lidos != 1);
    return valor;
}
