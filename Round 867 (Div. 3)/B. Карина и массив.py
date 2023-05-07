for _ in range(int(input())):
    input()
    a = sorted(list(map(int, input().split())))
    _max = max(a[0] * a[1], a[-1] * a[-2])
    print(_max)
