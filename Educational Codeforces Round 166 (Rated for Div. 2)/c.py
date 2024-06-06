t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    indn, indm, indn1, indm1 = -1, -1, -1, -1
    nown = 0
    nowm = 0
    sums = 0
    for i in range(n + m + 1):
        if a[i] > b[i]:
            if nown == n and indn1 == -1:
                indn1 = i
            if nown < n:
                nown += 1
                sums += a[i]
            if nown == n and indn == -1:
                indn = i
        else:
            ...
        



