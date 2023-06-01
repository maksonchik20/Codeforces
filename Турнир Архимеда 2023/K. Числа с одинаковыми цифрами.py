n, d = int(input()), int(input())
if n < d:
    print(-1)
else:
    dp = [d]
    while dp[-1] < n and len(dp) < len(str(n)):
        dp.append(dp[-1] * 10 + d)
    i = len(dp) - 1
    cnt = 0
    res = []
    while n != 0 and i >= 0:
        prev_res = [str(dp[i])] * (n // dp[i])
        cnt += n // dp[i]
        res += prev_res
        i -= 1
        n = n - (dp[i+1] * (n // dp[i+1]))
    s = "+".join(res)
    if n == 0:
        print(cnt)
        print(s)
    else:
        print(-1)

