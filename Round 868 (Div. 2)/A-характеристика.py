# for _ in range(int(input())):
#     n, k = map(int, input().split())
#     cntrs = [0]
#     a = 1
#     while cntrs[-1] < k:
#         cntrs.append(cntrs[-1] + a)
#         a += 1
#     # print(cntrs)
#     flag = False
#     for cnt_m1 in range(len(cntrs) + 1):
#         for cnt_1 in range(len(cntrs) + 1):
#             # print(cnt_m1, cnt_1, cntrs[cnt_m1-1] if cnt_m1-1 >=0 else 0, cntrs[cnt_1-1] if cnt_1-1 >=0 else 0)
#             arr = []
#             if (cntrs[cnt_m1-1] if cnt_m1-1 >=0 else 0) + (cntrs[cnt_1-1] if cnt_1-1 >= 0 else 0) == k and cnt_m1 + cnt_1 == n:
#                 res = [1] * (cnt_1) + [-1] * (cnt_m1)
#                 print("YES")
#                 print(*res)
#                 flag = True
#                 break
#         if flag:
#             break
#     if not flag:
#         print("NO")

import math

def find_primes(num):
    primes = []
    i = 2
    while i <= math.sqrt(num):
        if num % i == 0:
            primes.append(i)
        while num % i == 0:
            num //= i
        i += 1
    if num > 1:
        primes.append(num)
    return primes

def find_composites(num):
    composites = []
    for i in range(2, num):
        if num % i == 0:
            composites.append(i)
    return composites

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    all_primes = set()
    for num in a:
        primes = set(find_primes(num))
        all_primes.update(primes)
    all_composites = []
    for prime in all_primes:
        composites = find_composites(prime)
        all_composites.extend(composites)
    all_composites = sorted(set(all_composites), reverse=True)
    b = []
    for x in all_composites:
        if all(num % x == 0 for num in a):
            b.append(x)
        a = [num // x for num in a]
    if len(b) > 0:
        print(len(b))
    else:
        print(0)