n = int(input())
m = int(input())

cnt = (n // m) if n % m != 0 else ((n // m) - 1)

ar = ((1 + cnt) * cnt) // 2
print(((n // m) * m) + (n % m) + ar)

