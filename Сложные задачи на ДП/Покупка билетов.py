n = int(input())
dp = [0] * n
a = [tuple(map(int, input().split())) for _ in range(n)]
if n >= 3:
    dp[0] = a[0][0]
    dp[1] = min(a[0][0] + a[1][0], a[0][1])
    dp[2] = min(a[0][0] + a[1][0] + a[2][0], a[0][1] + a[2][0], a[0][0] + a[1][1], a[0][2])
    for i in range(3, n):
        dp[i] = min(dp[i-3] + a[i-2][2], dp[i-2] + a[i-1][1], dp[i-1] + a[i][0])
    print(dp[-1])
else:
    if n == 1:
        print(a[0][0])
    elif n == 2:
        print(min(a[0][0] + a[1][0], a[0][1]))