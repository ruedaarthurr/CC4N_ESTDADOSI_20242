import random

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

# Gera 50 números aleatórios entre 1 e 100
random_numbers = [random.randint(1, 100) for _ in range(50)]

print("Números antes da ordenação:")
print(random_numbers)

# Ordena os números usando Mergesort
merge_sort(random_numbers)

print("\nNúmeros depois da ordenação:")
print(random_numbers)
