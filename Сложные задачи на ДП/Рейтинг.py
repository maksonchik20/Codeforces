n = int(input())
a = list(map(int, input().split()))
dp = [[0, 0] for _ in range(n)]
dp[0][0] = 1
dp[0][1] = 1
prev = [[-1, -1] for _ in range(n)]
for i in range(1, n):
    if dp[i-1][0] + 1 > dp[i-1][1] + (1/a[i-1]):
        prev[i][0] = 0
    else:
        prev[i][0] = 1
    if dp[i-1][0] + a[i] > dp[i-1][1] + (a[i] / a[i-1]):
        prev[i][1] = 0
    else:
        prev[i][1] = 1
    dp[i][0] = max(dp[i-1][0] + 1, dp[i-1][1] + (1/a[i-1]))
    dp[i][1] = max(dp[i-1][0] + a[i], dp[i-1][1] + (a[i] / a[i-1]))
print(max(dp[-1]) - 1)
res = []
i = len(dp) - 1
flag = 0 if dp[-1][0] > dp[-1][1] else 1
while i != 0:
    res.append(a[i] if flag == 1 else 1)
    flag = prev[i][flag]
    i -= 1
res = res[::-1]
print(1, end=" ")
print(*res)

