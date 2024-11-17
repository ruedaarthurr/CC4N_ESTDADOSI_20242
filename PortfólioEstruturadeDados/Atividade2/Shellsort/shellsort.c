import random

def shellsort(arr):
    n = len(arr)
    gap = n // 2  # Inicializa o intervalo

    # Loop para reduzir o intervalo
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            # Realiza a ordenação no intervalo atual
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2  # Reduz o intervalo

    return arr

# Gera 50 números aleatórios entre 1 e 100
random_numbers = [random.randint(1, 100) for _ in range(50)]

print("Números antes da ordenação:")
print(random_numbers)

# Ordena os números usando Shellsort
sorted_numbers = shellsort(random_numbers)

print("\nNúmeros depois da ordenação:")
print(sorted_numbers)
