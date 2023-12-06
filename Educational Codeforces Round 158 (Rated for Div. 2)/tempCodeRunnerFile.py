t = int(input())
for _ in range(t):
    n = int(input())
    lst = list(map(int, input().split()))
    mins = min(lst)
    maxs = max(lst)
    cnt = 0
    while (maxs != mins):
        maxs = (maxs + mins) // 2
        cnt += 1
    if (cnt <= len(lst)):
        print(cnt)
        print(*([mins] * cnt))
    else:
        print(cnt)