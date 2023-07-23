t = int(input())

for _ in range(t):
    n = int(input())
    cnt = 0
    for _ in range(n):
        a, b = map(int, input().split())
        if a - b > 0:
            cnt += 1
    print(cnt)
