n, k = map(int, input().split())
flag = True
for l in range(3, n):
    if (n - l) * (l - 2) == k:
        print(1, l)
        flag = False
        break
if flag:
    print(-1)