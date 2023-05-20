from math import inf

n = int(input())
a, b, c = int(input()), int(input()), int(input())
def two_bin_search(i):
    if i == 1:
        return min(c, a)
    l = i
    r = 0
    _min = inf
    def f(j):
        return j*a - (i*c+((i-j-1)*b))
    while r + 1 != l:
        j = (l + r) // 2
        if a>b:
            if j*a - (i*c+((i-j-1)*b)) > 0:
                l = j
            else:
                r = j
        else:
            if j*a - (i*c+((i-j-1)*b)) > 0:
                l = j
            else:
                r = j
    if abs(f(l)) < abs(f(r)):
        # print(l, f(l), max(l*a, (i*c+((i-l-1)*b))))
        return max(l*a, (i*c+((i-l-1)*b)))
    else:
        # print(r, f(r), max(r*a, (i*c+((i-r-1)*b))))
        return max(r*a, (i*c+((i-r-1)*b)))
        # _min = min(abs(f(l)), abs(f(r)))
        # print(_min)
        # return min(abs(f(l)), abs(f(r)))
    # print(two_bin_search(4))
    # print(max(two_bin_search(5), (n - 5) * a))
_min = inf
for i in range(1, n+1):
        # print(i, max(two_bin_search(i), (n - i) * a + i*c))
        # print(i, two_bin_search(i), (n - i) * a + i*c)
    _min = min(_min, max(two_bin_search(i), (n - i) * a + i*c))
print(_min)