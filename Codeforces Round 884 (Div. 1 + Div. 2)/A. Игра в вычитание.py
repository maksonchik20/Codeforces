for _ in range(int(input())):
    a, b = map(int, input().split())
    print(min(a, b) * 2 + max(b, a) - min(a, b))