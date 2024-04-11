s = "abcdefghijklmnopqrstuvwxyz"

t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    print(s[:k] * n)
    