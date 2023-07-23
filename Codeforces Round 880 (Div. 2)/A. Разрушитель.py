# def sol(n, l):
#     sl = {}
#     _max = 0
#     for el in l:
#         sl[el] = sl.get(el, 0) + 1
#         _max = max(_max, el)
#     s = sorted(sl.items(), key=lambda x: x[0])
#     lst = [s[0][0]]
#     for i in range(len(s) - 1):
#         lst.append(s[i+1][0])
#         if s[i][1] < s[i+1][1]:
#             return "NO"
#     if lst != list(range(len(s))):
#         return "NO"
#     return "YES"

# for _ in range(int(input())):
#     n = int(input())
#     l = list(map(int, input().split()))
#     print(sol(n, l))
