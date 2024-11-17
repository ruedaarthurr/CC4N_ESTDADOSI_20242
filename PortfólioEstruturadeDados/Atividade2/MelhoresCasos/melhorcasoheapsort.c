def heapify(arr, n, i):
    largest = i  # Inicializa o maior como raiz
    left = 2 * i + 1  # Filho esquerdo
    right = 2 * i + 2  # Filho direito

    # Verifica se o filho esquerdo é maior que a raiz
    if left < n and arr[left] > arr[largest]:
        largest = left

    # Verifica se o filho direito é maior que o maior até agora
    if right < n and arr[right] > arr[largest]:
        largest = right

    # Troca e continua o heapify se a raiz não for o maior
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # Troca
        heapify(arr, n, largest)

def heapsort(arr):
    n = len(arr)

    # Constrói o heap (reorganiza a lista)
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # Extrai elementos do heap
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # Move a raiz para o final
        heapify(arr, i, 0)

# Gera uma lista já ordenada (melhor caso)
best_case_numbers = list(range(1, 51))

print("Números no melhor caso (ordenados):")
print(best_case_numbers)

# Ordena os números usando Heapsort
heapsort(best_case_numbers)

print("\nNúmeros após a execução do Heapsort (devem permanecer iguais):")
print(best_case_numbers)
