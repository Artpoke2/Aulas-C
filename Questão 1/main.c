// Questão 1 ===============================================================

#include <stdio.h>

// Função para imprimir o vetor
void imprimirVetor(int vetor[], int tamanho) {
    
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Função pro Bubble Sort
void bubbleSort(int vetor[], int tamanho) {
    
    int i, j, temp;
    
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            
            if (vetor[j] > vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

// Função pro Insertion Sort
void insertionSort(int vetor[], int tamanho) {
    
    int i, temp, j;
    
    for (i = 1; i < tamanho; i++) {
        
        temp = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j] > temp) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = temp;
        
    }
}

int main() {
    int tamanho, opcao;

    printf("► Informe o tamanho do Vetor: ");
    scanf("%d", &tamanho);

    int vetor[tamanho];

    for (int i = 0; i < tamanho; i++) {
        printf("► Informe o %dº elemento do Vetor:\n", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("► Como deseja Ordenar esse Vetor? (1. Bubble Sort // 2. Insertion Sort):\n");
    scanf("%d", &opcao);

    printf("▬ Vetor Original: ");
    imprimirVetor(vetor, tamanho);

    switch (opcao) {
        case 1:
            bubbleSort(vetor, tamanho);
            printf("\n▬ Vetor Ordenado por Bubble Sort: ");
            imprimirVetor(vetor, tamanho);
            break;
        case 2:
            insertionSort(vetor, tamanho);
            printf("\n▬ Vetor Ordenado por Insertion Sort: ");
            imprimirVetor(vetor, tamanho);
            break;
        default:
            printf("\nOpção Inválida!\n");
            break;
    }

    return 0;
}
// ==========================================================================================
