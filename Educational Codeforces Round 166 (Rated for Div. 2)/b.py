t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    res = 0
    mini = 10**18
    for i in range(n):
        res += abs(a[i] - b[i])
        if (a[i] <= b[-1] <= b[i]) or (a[i] >= b[-1] >= b[i]):
            mini = min(1, mini)
        else:
            if a[i] - b[-1] + 1 >= 1:
                mini = min(mini, a[i] - b[-1] + 1)
            if b[-1] - a[i] + 1 >= 1:
                mini = min(mini, b[-1] - a[i] + 1)
            if b[i] - b[-1] + 1 >= 1:
                mini = min(mini, b[i] - b[-1] + 1)
            if b[-1] - b[i] + 1 >= 1:
                mini = min(mini, b[-1] - b[i] + 1)
            # if b[-1] < a[i]:
            #     mini = min(mini, a[i] - b[-1] + 1)
            # else:
            #     mini = min(mini, b[-1] - a[i] + 1)
    print(res + mini)
