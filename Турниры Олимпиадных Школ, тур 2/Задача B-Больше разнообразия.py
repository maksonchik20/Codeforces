def get_p(n):
    from math import sqrt
    lst=[2]
    for i in range(3, n+1, 2):
        if (i > 10) and (i%10==5):
            continue
        for j in lst:
            if j > int((sqrt(i)) + 1):
                lst.append(i)
                break
            if (i % j == 0):
                break
        else:
            lst.append(i)
    return lst


from math import ceil
n = int(input())
if n == 1:
    print(1)
    print(1)
else:
    pr = get_p(ceil((10**4)))
    res = pr[:ceil(((n/2) ** (0.5)))]
    print(len(res))
    print(*res)