from math import inf
n = int(input())
sl = {}
for _ in range(n):
    s = input().split()
    if "Sun" in s:
        for el in s:
            if el != "Sun":
                sl[el] = 1
            else:
                sl[el] = 0
    else:
        check = None
        for el in s:
            if sl.get(el) is not None:
                check = (el, sl[el])
                break
        if check is None:
            for el in s:
                sl[el] = -1
            continue
        for el in s:
            if el != check[0]:
                sl[el] = check[1] + 1
for el in sorted(sl.items(), key=lambda x:x[0]):
    print(*el)