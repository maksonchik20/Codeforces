def solve():
    x, y = map(int, input().split())
    print(min(x, y), max(x, y))
    


t = int(input())
for _ in range(t):
    solve()
