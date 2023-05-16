# Функция для нахождения максимального значения k
def find_maximum_k(n, p):
    max_k = 10**8
    indices = {}

    for i in range(n):
        indices[p[i]] = i + 1
    print(indices)
    for i in range(n):
        j = indices[p[i]]
        if j - i + 2 < max_k:
            max_k = min(j - i + 1, max_k)

    return max_k


# Чтение входных данных
t = int(input())

for _ in range(t):
    n = int(input())
    p = list(map(int, input().split()))

    # Вычисление и вывод результата
    max_k = find_maximum_k(n, p)
    print(max_k)
