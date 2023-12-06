# def check(x, a):
#     damage = x
#     n = len(a)

#     for i in range(1, n):
#         if damage <= 0:
#             return False
#         if (a[i] > damage - 1):
#             return False
#         damage -= 1

#     return True

# def min_spell_power(n, a):
#     left, right = 1, 10**18

#     while left < right:
#         mid = (left + right) // 2
#         if check(mid, a):
#             right = mid
#         else:
#             left = mid + 1

#     return left

# # Чтение входных данных
# n = int(input())
# a = list(map(int, input().split()))

# # Вывод результата
# print(min_spell_power(n, a))

# Чтение входных данных
n = int(input())
a = list(map(int, input().split()))
ans = a[0]
for i in range(1, n):
    ans = max(a[i], ans + 1)
print(ans)
