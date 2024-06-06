def solve():
    n, k, q = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    a.insert(0, 0)
    b.insert(0, 0)
    ans = []
    for i in range(q):
        d = int(input())
        left = 0
        right = k
        # a[left] <= d
        # a[right] > d
        while (left + 1 != right):
            mid = (left + right) // 2
            # print("mid=", mid)
            if (a[mid] <= d):
                left = mid
            else:
                right = mid
        if (a[left] == d):
            ans.append(b[left])
            # print(b[left])
        else:
            # v = (a[left + 1] - a[left]) / (b[left + 1] - b[left])
            ans.append(int(b[left] + (d - a[left]) * (b[left + 1] - b[left]) / (a[left + 1] - a[left])))
            # print(int(b[left] + (d - a[left]) / v))
    print(*ans)

    
t = int(input())
for _ in range(t):
    solve()