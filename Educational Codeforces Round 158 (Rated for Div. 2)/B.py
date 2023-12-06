t = int(input())
for _ in range(t):
    n = int(input())
    v = list(map(int, input().split()))
    save = 0
    maxi = 1
    for i in range(n):
        if v[i] <= maxi:
            maxi = v[i]
        else:
            diff = v[i] - maxi
            save += diff
            maxi = v[i]
    print(save)