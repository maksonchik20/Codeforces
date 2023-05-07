# def predpodschet(n):
#     sl = {}
#     sl[1] = []
#     for i in range(2, n + 1):
#         if sl.get(i) is None:
#             sl[i] = []
#         if i % 2 == 0:
#             if sl.get(i + i//2) is None:
#                 sl[i + i//2] = [i, i//2] + sl[i] + sl[i//2]
#             else:
#                 sl[i + i//2] += sl[i] + sl[i//2]

#     return sl

from functools import lru_cache

@lru_cache(maxsize=None)
def req(n, m):
    if n == m:
        return True
    if n % 3 == 0:
        if req(n * 2 // 3, m) is True:
            return True
        if req(n - (n * 2 // 3), m) is True:
            return True
    return False

for _ in range(int(input())):
    n, m = map(int, input().split())
    if m > n:
        print("NO")
    else:
        if req(n, m):
            print("YES")
        else:
            print("NO")
