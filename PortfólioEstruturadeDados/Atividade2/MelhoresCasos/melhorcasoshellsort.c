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

# Gera uma lista de 50 números já ordenados
best_case_numbers = list(range(1, 51))

print("Números no melhor caso (ordenados):")
print(best_case_numbers)

# Ordena os números usando Shellsort
sorted_numbers = shellsort(best_case_numbers)

print("\nNúmeros após a execução do Shellsort (devem permanecer iguais):")
print(sorted_numbers)
