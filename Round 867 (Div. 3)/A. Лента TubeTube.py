for _ in range(int(input())):
    n, t = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    _max = 0
    res = -1
    for i in range(n):
        if i + a[i] <= t:
            if b[i] > _max:
                res = i+1
                _max = b[i]
    print(res)