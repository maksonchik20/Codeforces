t = int(input())

for i in range(t):
    n, m = map(int, input().split())

    if n == 1:
        print("YES")
    elif m == 1:
        print("YES")
    elif n > m:
        print("YES")
    else:
        unique_votes = min(n, m - n + 1)
        if unique_votes == m:
            print("YES")
        else:
            print("NO")