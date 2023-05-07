for _ in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    for k in range(n + 1):
        cnt_l = 0
        flag = True
        for i in range(n):
            if l[i] > k:
                cnt_l += 1
        if cnt_l == k:
            print(k)
            flag = False
            break
    if flag:
        print(-1)
        