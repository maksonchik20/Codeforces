# Функция для решения задачи
def find_ideal_array(n):
    a = [0] * n
    s = 0
    for i in range(1, n + 1):
        a[i - 1] = i
        s += i
    if s % n != 0:
        a[-1] += (n - s % n)
    while sum(a) % n != 0 or a[-1] % n != 0:
        a = list(map(lambda x:x*2, a))
    return a
# Чтение входных данных
t = int(input())

for _ in range(t):
    n = int(input())

    # Вычисление и вывод результата
    ideal_array = find_ideal_array(n)
    print(*ideal_array)
