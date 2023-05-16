from math import inf
a, b, n, m = int(input()), int(input()), int(input()), int(input())
t_one = n+((n-1)*a)
t_two = m+((m-1)*b)
ones = list(range(t_one, t_one+(2*a+1)))
twos = list(range(t_two, t_two+(2*b+1)))
_min = inf
_max = -inf
lst = list(set(ones) & set(twos))
if len(lst) == 0:
    print(-1) 
else:
    for el in lst:
        _min = min(_min, el)
        _max = max(_max, el)
    print(_min, _max)