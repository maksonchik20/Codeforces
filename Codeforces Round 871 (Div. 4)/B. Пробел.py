for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    res = 0
    cnt = 0
    for el in a:
        if el == 0:
            cnt += 1
        else:
            res = max(res, cnt)
            cnt = 0
    if cnt != 0:
        res = max(res, cnt)
    print(res)