t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    # cnts[0] - max dist, cnts[1] - 
    cnts = [[-1, 0, 0] for _ in range(k)]
    for i in range(n):
        ind = arr[i]-1
        if cnts[ind][0] == -1:
            cnts[ind][0] = i
        elif cnts[ind][0] != -1:
            cnts[ind][1] = min(cnts[ind][0], i - cnts[ind][2] - 1)
            cnts[ind][0] = max(cnts[ind][0], i - cnts[ind][2] - 1)
        cnts[ind][2] = i
    for i in range(k):
        arr = [cnts[i][1], cnts[i][0], n - cnts[i][2] - 1]
        arr.sort()
        cnts[i][1] = arr[1]
        cnts[i][0] = arr[2]
    # print(cnts)
    res = 10 ** 18
    for i in range(k):
        res = min(res, max(cnts[i][0] // 2, cnts[i][1]))
    print(res)
