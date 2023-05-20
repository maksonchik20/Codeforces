for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    new_a = [0] * n
    for i in range(n):
        new_a[i] = (a[i], i)
    new_a = sorted(new_a, key=lambda x: x[0])
    b.sort()
    res = [0] * n
    for i in range(n):
        res[new_a[i][1]] = b[i]
    print(*res)
