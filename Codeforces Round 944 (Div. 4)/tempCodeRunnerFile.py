def getcnt(r):
    res = 0
    y = r
    cntR = -4
    for x in range(0, r + 1):
        while (x * x + y * y > r * r):
            y -= 1
        if x * x + y * y == r * r:
            cntR += 4
        res += y
    return res * 4 + 1 - cntR
        


def solve():
    r = int(input())
    print(getcnt(r + 1) - getcnt(r))
    # print(getcnt(r + 1), getcnt(r))
    
t = int(input())
for _ in range(t):
    solve()