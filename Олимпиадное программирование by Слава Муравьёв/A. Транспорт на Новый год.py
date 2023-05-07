n, t = map(int, input().split())
a = list(map(int, input().split()))

now = 1
while now != n and now < t:
    now = now + a[now-1]
if now == t:
    print("YES")
else:
    print("NO")