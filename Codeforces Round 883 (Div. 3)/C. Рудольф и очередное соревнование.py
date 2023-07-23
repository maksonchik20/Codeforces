t = int(input())
for _ in range(t):
    n, m, h = map(int, input().split())
    arr = [0] * n
    first = None
    for i in range(n):
        lst = sorted(list(map(int, input().split())))
        schtraf = 0
        now_time = 0
        cnt = 0
        for el in lst:
            if now_time + el <= h:
                cnt += 1
                now_time += el
                schtraf += now_time
        if first == None:
            first = (cnt, schtraf)
        arr[i] = (cnt, schtraf)
    print(sorted(arr, key=lambda x: (-x[0], x[1])).index(first) + 1)

