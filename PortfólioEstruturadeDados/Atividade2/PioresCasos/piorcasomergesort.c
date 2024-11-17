def merge_sort(arr):
    if len(arr) > 1:
        # Divide o array ao meio
        mid = len(arr) // 2
        left_half = arr[:mid]
        right_half = arr[mid:]

        # Chamada recursiva para as duas metades
        merge_sort(left_half)
        merge_sort(right_half)

        # Índices para percorrer as sublistas
        i = j = k = 0

        # Mescla as sublistas na lista original
        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1

        # Copia os elementos restantes de left_half, se houver
        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1

        # Copia os elementos restantes de right_half, se houver
        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1

# Gera uma lista em ordem decrescente (pior caso)
worst_case_numbers = list(range(50, 0, -1))

print("Números no pior caso (ordem decrescente):")
print(worst_case_numbers)

# Ordena os números usando Mergesort
merge_sort(worst_case_numbers)

print("\nNúmeros após a execução do Mergesort (devem estar ordenados):")
print(worst_case_numbers)
