n = int(input())
m = int(input())
k = int(input())
for _ in range(k):
    t = int(input()) % n
    m = (m + t) % (n + 1)
    if m == 0:
        m = 1
print(m)