#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

// Função para ordenar o vetor usando InsertSort
void insertSort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;
        
        // Move os elementos do array[0..i-1] que são maiores que a chave
        // para uma posição à frente de sua posição atual
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
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

    printf("Vetor desordenado:\n");
    printArray(array, SIZE);

    // Ordena o vetor usando o InsertSort
    insertSort(array, SIZE);

    printf("\nVetor ordenado:\n");
    printArray(array, SIZE);

    return 0;
}
