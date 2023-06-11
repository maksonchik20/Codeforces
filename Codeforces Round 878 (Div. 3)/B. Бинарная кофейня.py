for _ in range(int(input())):
    n, k = map(int, input().split())
    k = min(k, 30)
    print(min(2**k, n+1))