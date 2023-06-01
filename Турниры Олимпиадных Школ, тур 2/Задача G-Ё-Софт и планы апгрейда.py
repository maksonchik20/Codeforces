def max_efficiency(N, K, products):
    dp = [(0, {}) for _ in range(K+1)]

    for i in range(1, K + 1):
        for j in range(N):
            p, e = products[j]
            if p <= i:
                sl = dp[i-1][1]
                if dp[i - 1][0] > dp[i][0]:
                    dp[i] = (max(dp[i][0], dp[i - 1][0]), sl)
            if p <= i and dp[i - p][1].get(j) is None:
                sl = dp[i-p][1].copy()
                if dp[i - p][0] + e > dp[i][0]:
                    sl[j] = True
                    dp[i] = (max(dp[i][0], dp[i - p][0] + e), sl)

    return dp

N, K = map(int, input().split())

products = []
for i in range(N):
    p, e = map(int, input().split())
    products.append((p, e))
result = max_efficiency(N, K, products)
for i in range(1, K + 1):
    print(result[i][0], end=" ")
