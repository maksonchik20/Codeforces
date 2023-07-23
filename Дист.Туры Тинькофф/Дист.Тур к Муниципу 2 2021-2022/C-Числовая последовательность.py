d, k = map(int, input().split())
def oper(num):
    if num < 10:
        return (num**5) * 20
    else:
        return num//10 + ((num%10)**5) * 20

_max = d
for _ in range(k):
    res = oper(d)
    _max = max(_max, res)
    d = res
print(_max)