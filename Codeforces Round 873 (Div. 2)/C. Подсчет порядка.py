MOD = 10**9 + 7

# Функция для вычисления факториала
def factorial(n):
    fact = 1
    for i in range(1, n+1):
        fact = (fact * i) % MOD
    return fact

# Функция для подсчета количества перестановок
def count_permutations(n, a, b):
    counts = [0] * n

    for i in range(n):
        for j in range(n):
            if a[i] > b[j]:
                counts[i] += 1

    total_permutations = factorial(n)

    for count in counts:
        total_permutations = (total_permutations * count) % MOD

    return total_permutations

# Чтение входных данных
t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    # Вычисление и вывод результата
    permutations = count_permutations(n, a, b)
    print(permutations)
