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

# Gera uma lista em ordem decrescente (pior caso para o Shellsort)
worst_case_numbers = list(range(50, 0, -1))

print("Números no pior caso (ordem decrescente):")
print(worst_case_numbers)

# Ordena os números usando Shellsort
sorted_numbers = shellsort(worst_case_numbers)

print("\nNúmeros após a execução do Shellsort (devem estar ordenados):")
print(sorted_numbers)
