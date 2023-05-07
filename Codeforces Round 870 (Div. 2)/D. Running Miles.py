t = int(input())
for _ in range(t):
    n = int(input())
    beauty = list(map(int, input().split()))

    l = r = 0
    sum_beauty = beauty[0]
    max_beauty = [0, 0, 0]
    ans = sum_beauty - (r - l)
    
    while r < n - 1:
        r += 1
        sum_beauty += beauty[r]
        max_beauty.append(beauty[r])
        max_beauty.sort(reverse=True)
        sum_beauty -= max_beauty.pop()
        while l < r and r - l + 1 > 3:
            sum_beauty -= beauty[l]
            l += 1
        ans = max(ans, sum_beauty - (r - l))

    print(ans)