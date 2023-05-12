t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    arr.sort()
    pref_sum = [0] * (n + 1)
    for i in range(1, n + 1):
        pref_sum[i] = pref_sum[i-1] + arr[i-1]
    _max = 0
    for a in range(k + 1):
        b = k - a
        _max = max(_max, pref_sum[-b-1] - pref_sum[a*2])
    print(_max)
