// Faça um algoritmo que leia uma matriz de no máximo 4
// linhas e 4 colunas. O programa deverá:
// • Elaborar a matriz transposta
// • Trocar os valores da coluna 0 com a coluna 3
// • Determinar quantos números pares tem essa matriz
// • A soma dos valores da diagonal principal
// • O maior valor da diagonal secundária
// • Determine a soma de cada linha desta matriz, coloque o
// resultado em um vetor
// • Determine o maior valor de cada coluna dessa matriz,
// coloque o resultado em um vetor
// • A cada item, a matriz resultante deverá ser impressa

#include <stdio.h>

// Protótipos das funções
void imprimirMatriz(int matriz[][4], int tamanho);
void transporMatriz(int matriz[][4], int tamanho);
void trocarColunas(int matriz[][4], int tamanho);
int contarPares(int matriz[][4], int tamanho);
int somaDiagonalPrincipal(int matriz[][4], int tamanho);
int maiorDiagonalSecundaria(int matriz[][4], int tamanho);
void somaLinhas(int matriz[][4], int tamanho, int vetor[]);
void maiorColunas(int matriz[][4], int tamanho, int vetor[]);

int main()
{
    int matriz[4][4];
    int i, j;
    int somaLinhasVetor[4];
    int maiorColunasVetor[4];

    // Leitura da matriz
    printf("=== LEITURA DA MATRIZ 4x4 ===\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("Digite o elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // 1. Impressão da matriz original
    printf("\n=== MATRIZ ORIGINAL ===\n");
    imprimirMatriz(matriz, 4);

    // 2. Elaborar a matriz transposta
    printf("\n=== TRANSPONDO A MATRIZ ===\n");
    transporMatriz(matriz, 4);
    imprimirMatriz(matriz, 4);

    // 3. Trocar os valores da coluna 0 com a coluna 3
    printf("\n=== TROCANDO COLUNA 0 COM COLUNA 3 ===\n");
    trocarColunas(matriz, 4);
    imprimirMatriz(matriz, 4);

    // 4. Determinar quantos números pares tem essa matriz
    int pares = contarPares(matriz, 4);
    printf("\n=== NÚMEROS PARES ===\n");
    printf("Quantidade de números pares: %d\n", pares);
    imprimirMatriz(matriz, 4);

    // 5. A soma dos valores da diagonal principal
    int somaDiag = somaDiagonalPrincipal(matriz, 4);
    printf("\n=== SOMA DA DIAGONAL PRINCIPAL ===\n");
    printf("Soma da diagonal principal: %d\n", somaDiag);
    imprimirMatriz(matriz, 4);

    // 6. O maior valor da diagonal secundária
    int maiorDiagSec = maiorDiagonalSecundaria(matriz, 4);
    printf("\n=== MAIOR VALOR DA DIAGONAL SECUNDÁRIA ===\n");
    printf("Maior valor da diagonal secundária: %d\n", maiorDiagSec);
    imprimirMatriz(matriz, 4);

    // 7. Determine a soma de cada linha desta matriz
    printf("\n=== SOMA DE CADA LINHA ===\n");
    somaLinhas(matriz, 4, somaLinhasVetor);
    printf("Vetor com soma das linhas: ");
    for (i = 0; i < 4; i++) {
        printf("%d ", somaLinhasVetor[i]);
    }
    printf("\n");
    imprimirMatriz(matriz, 4);

    // 8. Determine o maior valor de cada coluna dessa matriz
    printf("\n=== MAIOR VALOR DE CADA COLUNA ===\n");
    maiorColunas(matriz, 4, maiorColunasVetor);
    printf("Vetor com maior valor das colunas: ");
    for (i = 0; i < 4; i++) {
        printf("%d ", maiorColunasVetor[i]);
    }
    printf("\n");
    imprimirMatriz(matriz, 4);

    return 0;
}

// Função para imprimir matriz
void imprimirMatriz(int matriz[][4], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para transpor matriz
void transporMatriz(int matriz[][4], int tamanho) {
    int temp;
    
    for (int i = 0; i < tamanho; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            // Troca elementos matriz[i][j] com matriz[j][i]
            temp = matriz[i][j];
            matriz[i][j] = matriz[j][i];
            matriz[j][i] = temp;
        }
    }
}

// Função para trocar coluna 0 com coluna 3
void trocarColunas(int matriz[][4], int tamanho) {
    int temp;
    
    for (int i = 0; i < tamanho; i++) {
        temp = matriz[i][0];
        matriz[i][0] = matriz[i][3];
        matriz[i][3] = temp;
    }
}

// Função para contar números pares
int contarPares(int matriz[][4], int tamanho) {
    int contador = 0;
    
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (matriz[i][j] % 2 == 0) {
                contador++;
            }
        }
    }
    
    return contador;
}

// Função para somar diagonal principal
int somaDiagonalPrincipal(int matriz[][4], int tamanho) {
    int soma = 0;
    
    for (int i = 0; i < tamanho; i++) {
        soma += matriz[i][i];
    }
    
    return soma;
}

// Função para encontrar maior valor da diagonal secundária
int maiorDiagonalSecundaria(int matriz[][4], int tamanho) {
    int maior = matriz[0][tamanho-1]; // Primeiro elemento da diagonal secundária
    
    for (int i = 1; i < tamanho; i++) {
        if (matriz[i][tamanho-1-i] > maior) {
            maior = matriz[i][tamanho-1-i];
        }
    }
    
    return maior;
}

// Função para calcular soma de cada linha
void somaLinhas(int matriz[][4], int tamanho, int vetor[]) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = 0;
        for (int j = 0; j < tamanho; j++) {
            vetor[i] += matriz[i][j];
        }
    }
}

// Função para encontrar maior valor de cada coluna
void maiorColunas(int matriz[][4], int tamanho, int vetor[]) {
    for (int j = 0; j < tamanho; j++) {
        vetor[j] = matriz[0][j]; // Primeiro elemento da coluna
        for (int i = 1; i < tamanho; i++) {
            if (matriz[i][j] > vetor[j]) {
                vetor[j] = matriz[i][j];
            }
        }
    }
}