n = int(input())
data = [int(input()) for _ in range(n)]
data.sort()
res = 0
max_i = 0
for i in range(n):
    if data[i] * (n - i) > res * (n - max_i):
        max_i = i
        res = data[i]
print(n - max_i, res)