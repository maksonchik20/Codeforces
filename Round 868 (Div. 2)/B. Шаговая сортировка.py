for _ in range(int(input())):
    n, k = map(int, input().split())
    p = list(map(int, input().split()))
    ans = 0
    for i in range(len(p)):
        if p[i] % k != (i+1) % k:
            ans += 1
    if ans == 0:
        print(0)
    elif ans == 2:
        print(1)
    else:
        print(-1)