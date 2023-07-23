def sol(a, b, k):
    flag = True
    for _ in range(k):
        x, y = map(int, input().split())
        if (abs(x - a) + abs(y - b)) % 2 == 0:
            flag = False
    return flag

for _ in range(int(input())):
    n, m, k = map(int, input().split())
    a, b = map(int, input().split())
    print("YES" if sol(a, b, k) else "NO")