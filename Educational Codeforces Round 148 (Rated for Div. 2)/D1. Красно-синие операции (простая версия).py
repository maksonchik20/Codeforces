# Функция для решения задачи
def find_max_min(n, a, q, k_values):
    # Создание массива diff
    diff = [a[i] - i for i in range(n)]
    
    # Поиск максимального значения diff
    max_diff = max(diff)
    
    # Обработка запросов
    results = []
    for k in k_values:
        # Вычисление ответа для каждого запроса
        result = max_diff + k
        results.append(result)
    
    return results


# Чтение входных данных
n, q = map(int, input().split())
a = list(map(int, input().split()))
k_values = list(map(int, input().split()))

# Вычисление и вывод результата
results = find_max_min(n, a, q, k_values)
for result in results:
    print(result)
