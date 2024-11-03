#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

// Função para ordenar o vetor usando SelectionSort
void selectionSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;

        // Encontra o menor elemento no sub-vetor não ordenado
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }

        // Troca o menor elemento com o primeiro elemento do sub-vetor não ordenado
        if (minIndex != i) {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}

// Função para imprimir o vetor
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[SIZE];
    srand(time(NULL));  // Inicializa o gerador de números aleatórios

    // Preenche o vetor com valores aleatórios de 0 a 99
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 100;
    }

    printf("Vetor original:\n");
    printArray(array, SIZE);

    // Ordena o vetor usando SelectionSort
    selectionSort(array, SIZE);

    printf("\nVetor ordenado com SelectionSort:\n");
    printArray(array, SIZE);

    return 0;
}
