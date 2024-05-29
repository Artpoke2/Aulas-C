#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Algoritmo Bubble Sort O(n²)
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function usada pro Merge
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Algoritmo Merge Sort O(n log n)
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

//Função para Calcular o Tempo de Execução
double calculateTime(void (*sortFunc)(int[], int), int arr[], int n) {
    clock_t start, end;
    start = clock();
    sortFunc(arr, n);
    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

//Função para Calcular o Tempo de Execução específicamente do Merge Sort
double calculateTimeMergeSort(void (*sortFunc)(int[], int, int), int arr[], int l, int r) {
    clock_t start, end;
    start = clock();
    sortFunc(arr, l, r);
    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
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

        for (int j = 0; j < n; j++) {
            array[j] = rand() % 1000000;
        }

        //Copiando o Array para ser usado no Merge Sort
        for (int j = 0; j < n; j++) {
            arrayCopy[j] = array[j];
        }

        //Informando o Tamanho do Array utilizado no Momento
        printf("Tamanho do Array: %d\n", n);

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
