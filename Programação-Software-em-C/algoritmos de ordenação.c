#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Algoritmo Bubble Sort O(n²)
void bubbleSort(int array[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

// Function usada pro Merge
void merge(int array[], int l, int m, int r) {
    int i, j, k;
    int num1 = m - l + 1;
    int num2 = r - m;

    int L[num1], R[num2];

    for (i = 0; i < num1; i++)
        L[i] = array[l + i];
    for (j = 0; j < num2; j++)
        R[j] = array[m + 1+ j];

    while (i < num1 && j < num2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    i = 0;
    j = 0;
    k = l;

    while (i < num1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < num2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

// Algoritmo Merge Sort O(n log n)
void mergeSort(int array[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);

        merge(array, l, m, r);
    }
}

//Função para Calcular o Tempo de Execução
double calculateTime(void (*sortFunction)(int[], int), int array[], int n) {
    clock_t inicio, fim;
    inicio = clock();
    sortFunction(array, n);
    fim = clock();
    return ((double) (fim - inicio)) / CLOCKS_PER_SEC;
}

//Função para Calcular o Tempo de Execução específicamente do Merge Sort
double calculateTimeMergeSort(void (*sortFunction)(int[], int, int), int array[], int l, int r) {
    clock_t inicio, fim;
    inicio = clock();
    sortFunction(array, l, r);
    fim = clock();
    return ((double) (fim - inicio)) / CLOCKS_PER_SEC;
}

int main() {

    //Definições
    int tamanhos[] = {1000, 10000, 100000, 1000000};
    int alocacao = sizeof(tamanhos) / sizeof(tamanhos[0]);

    //Iniciando o Procedimento
    for (int i = 0; i < alocacao; i++) {
        int n = tamanhos[i];
        int* array = (int*)malloc(n * sizeof(int));
        int* arrayCopy = (int*)malloc(n * sizeof(int));

        //Gerando os Números Aleatórios
        for (int j = 0; j < n; j++) {
            array[j] = rand() % 1000000;
        }

        //Copiando o Array para ser usado no Merge Sort
        for (int j = 0; j < n; j++) {
            arrayCopy[j] = array[j];
        }

        //Informando o Tamanho do Array utilizado no Momento
        printf("\nTamanho do Array: %d\n", n);

        // Medindo o Tempo de Execução do Bubble Sort
        double timeBubbleSort = calculateTime(bubbleSort, array, n);
        printf("Tempo de Execução do Bubble Sort: %f segundos\n", timeBubbleSort);

        // Medindo o Tempo de Execução do Merge Sort
        double timeMergeSort = calculateTimeMergeSort(mergeSort, arrayCopy, 0, n - 1);
        printf("Tempo de Execução do Merge Sort: %f segundos\n", timeMergeSort);

        //Limpando a Memória
        free(array);
        free(arrayCopy);
    }

    return 0;
}
