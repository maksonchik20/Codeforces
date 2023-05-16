
l, r, a = int(input()), int(input()), int(input())
from random import randint
def fast(l, r, a):
    x = r - a
    # print(x, (x-l+1))
    res = ((((r-l)//a) + ((r-x) // a)) * ((x-l+1)) // 2)
    return max(res, 0)


def slow(l, r, a):
    cnt = 0
    for i in range(l, r):
        cnt += (r-i) // a
    return cnt
print(slow(l, r, a))
# for n in range(1000):
#     l = randint(1, 20)
#     r = randint(l + 1, 25)
#     a = randint(1, 100)
#     fs = fast(l, r, a)
#     sl = slow(l, r, a)
#     if fs != sl:
#         print("Error", l, r, a, f"fast: {fs}; slow: {sl}")

