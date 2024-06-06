t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    a, b = list(map(int, input().split())), list(map(int, input().split()))
    ac, bc = a.copy(), b.copy()
    
    ni, mi = 0, 0
    n += 1
    for i in range(n + m + 1):
        if ni < n and (a[i] > b[i] or mi >= m):
            ni += 1
            if ni == n:
                nextni = i
        else:
            mi += 1
    n -= 1

    ni, mi = 0, 0
    m += 1
    for i in range(n + m + 1):
        if ni < n and (a[i] > b[i] or mi >= m):
            ni += 1
        else:
            mi += 1
            if mi == m:
                nextmi = i
    m -= 1
    
    ans = 0
    ni, mi = 0, 0
    for i in range(n + m):
        if ni < n and (a[i] > b[i] or mi >= m):
            ni += 1
            ans += a[i]
            bc[i] = 0
        else:
            mi += 1
            ans += b[i]
            ac[i] = 0
    
    #print(ac)
    #print(bc)
    #print(nextni + 1, nextmi + 1)
    for i in range(n + m):
        ansc = ans
        if ac[i] != 0:
            ansc -= a[i]
            if nextni == n + m:
                # last
                ansc += a[nextni]
            else:
                ansc -= b[nextni]
                ansc += a[nextni]
                ansc += b[-1]
        else:
            ansc -= b[i]
            if nextmi == n + m:
                # last
                ansc += b[nextmi]
            else:
                ansc -= a[nextmi]
                ansc += b[nextmi]
                ansc += a[-1]
        print(ansc, end=" ")
    print(ans)