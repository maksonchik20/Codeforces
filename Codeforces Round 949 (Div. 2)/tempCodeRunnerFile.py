from math import log2
def solve():
    n, m = map(int, input().split())
    to = n + m
    step = int(log2(to))
    print(step)
    if 2 ** step != to:
        step += 1
    print(2 ** step - 1)


t = int(input())
for _ in range(t):
    solve()