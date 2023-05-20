# from math import log2
# n = int(input())
# if n == 1:
#     print(1)
# else:
#     a = []
#     i = 1
#     for _ in range(n - 1):
#         pobed = int(input())
#         a.append((i, i+1, pobed))
#         i += 2
#     print(a)
#     ind = n - 2
#     for i in range(int(log2(n))):
#         if a[ind][2] == 1:
#             ind -= 2
#         else:
#             ind -= 1
#     # print(ind)
#     print(a[ind][0] if a[ind][2] == 1 else a[ind][1])

n = int(input())
def req(n, a):
    if len(a) == 1:
        print(a[0])
        return a[0]
    i = 0
    new_a = []
    for _ in range(n//2):
        pobed = int(input())
        if pobed == 1:
            new_a.append(a[i])
        else:
            new_a.append(a[i+1])
        i += 2
    req(n//2, new_a)
req(n, list(range(1, n+1)))

