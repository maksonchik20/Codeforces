# from sys import setrecursionlimit
# setrecursionlimit(10**2)
# i = int(input())

# def req(n):
#     if n == 8848:
#         return True
#     if n > 8848:
#         return False
#     if n % 2 == 0:
#         return req(n//2)
#     else:
#         return req(3*n + 1)
# # print(req(i)) 
# for i in range(1, 8849):
#     try:
#         r = req(i)
#         if r:
#             print(i)
#     except:
#         pass
# dp = [0] * 8848
# stack = [8848]
# good_v = [8848]
# while stack != []:
#     j = stack.pop()
#     if j % 4 == 0:
#         stack.append(j//2)
#         if j//2 not in good_v:
#             good_v.append(j//2)
#     if (j-1) // 3 > 2:
#         stack.append((j-1) // 3)
#         if (j-1) // 3 not in good_v:
#             good_v.append((j-1) // 3)
# print(sorted(good_v))
i = int(input())
if i == 1:
    print(2949)
elif i == 2:
    print(5898)
elif i == 3:
    print(8848)
else:
    print(-1)
# s = [2949, 5898, 8848]