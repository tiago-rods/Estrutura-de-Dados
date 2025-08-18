// Elabore um programa que crie uma estrutura com as
// seguintes informações de um produto:
// • Código do produto – inteiro de 3 dígitos
// • Quantidade em estoque - inteiro
// • Valor de compra - real
// • Valor de Venda - real
// O programa deverá ler a informação de 10 produtos e
// determinar
// • O código do produto com maior quantidade de estoque
// • O quantidade de estoque do produto que proporciona o
// maior lucro
#include <stdio.h>
#include <stdlib.h>
#define TAM 3

typedef struct produto {
    int codigo[3];
    int quantidadeEstoque;
    float valorCompra;
    float valorVenda;
} Produto;

void lerProdutos(Produto *produtos, int n);
void maiorLucro(Produto *produtos, int n);
void maiorEstoque(Produto *produtos, int n);
void mostrarProdutos(Produto *produtos, int n);

int main()
{
    Produto produtos[TAM];
    lerProdutos(produtos, TAM);
    
    maiorLucro(produtos, TAM);

    maiorEstoque(produtos, TAM);

    mostrarProdutos(produtos, TAM);
    return 0;
}

void lerProdutos(Produto *produtos, int n)
{
    for (int i = 0; i < TAM; i++)
    {
        printf("Digite o codigo de três digitos do Produto \n");
        for (int j = 0; j < 3; j++) {
            do {
                scanf("%1d", &produtos[i].codigo[j]);
            } while (produtos[i].codigo[j] < 0 || produtos[i].codigo[j] > 9);
        }

        printf("Digite a quantidade em estoque do produto \n");
        do {
            scanf("%d", &produtos[i].quantidadeEstoque);
        } while (produtos[i].quantidadeEstoque < 0);

        printf("Digite o valor de compra do produto \n");
        do {
            scanf("%f", &produtos[i].valorCompra);
        } while (produtos[i].valorCompra < 0);

        printf("Digite o valor de venda do produto \n");
        do {
            scanf("%f", &produtos[i].valorVenda);
        } while (produtos[i].valorVenda < 0);
    }
}

void maiorLucro(Produto *produtos, int n){
    float maiorLucro = 0;
    int maiorQuantidadeEstoque;
    for (int i = 0; i < n; i++){
        float lucro = produtos[i].valorVenda - produtos[i].valorCompra;
        if (lucro > maiorLucro) {
            maiorLucro = lucro;
            maiorQuantidadeEstoque= produtos[i].quantidadeEstoque;
        }
    }
    printf("Quantidade de estoque que proporciona o maior lucro: %d\n", maiorQuantidadeEstoque);
}

void maiorEstoque(Produto *produtos, int n){
    int maiorEstoque = 0;
    int codigoMaiorEstoque[3];
    for (int i = 0; i < n; i++){
        if(produtos[i].quantidadeEstoque > maiorEstoque){
            maiorEstoque = produtos[i].quantidadeEstoque;
            codigoMaiorEstoque[0] = produtos[i].codigo[0];
            codigoMaiorEstoque[1] = produtos[i].codigo[1];
            codigoMaiorEstoque[2] = produtos[i].codigo[2];
        }
    }
    printf("Codigo do produto com maior estoque: %d%d%d\n", codigoMaiorEstoque[0], codigoMaiorEstoque[1], codigoMaiorEstoque[2]);
}


void mostrarProdutos(Produto *produtos, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Produto %d:\n", i + 1);
        printf("Codigo: %d%d%d\n", produtos[i].codigo[0], produtos[i].codigo[1], produtos[i].codigo[2]);
        printf("Quantidade em estoque: %d\n", produtos[i].quantidadeEstoque);
        printf("Valor de compra: %f\n", produtos[i].valorCompra);
        printf("Valor de venda: %f\n", produtos[i].valorVenda);
    }
}