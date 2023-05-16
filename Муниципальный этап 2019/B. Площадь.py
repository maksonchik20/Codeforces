n, m = int(input()), int(input())
t = int(input())
l = 0
r = (min(n, m) // 2 + 1) if min(n, m) % 2 != 0 else (min(n, m ) // 2)
res = 0
while r - l != 1:
    p = (l + r) // 2
    sred = (n - (2*p)) * (m-(2*p))
    if n*m - sred <= t:
        l = p
        res = max(res, p)
    else:
        r = p
print(res)
    
    