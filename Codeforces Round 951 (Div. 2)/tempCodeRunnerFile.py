def solve():
    import math

    t = int(input().strip())

    results = []

    for _ in range(t):

        n = int(input().strip())

        k = list(map(int, input().strip().split()))

        x = 1

        for val in k:
            y = math.gcd(x, val)
            y = val // y
            x = x * y
        print(x)
        sum_val = 0
        ans = []
        for val in k:
            div_val = x // val
            sum_val += div_val
            ans.append(div_val)
        if sum_val >= x:
            results.append("-1")
        else:
            results.append(" ".join(map(str, ans)))
    for result in results:
        print(result)
solve()