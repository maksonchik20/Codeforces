ans = []
def solve():
    a, b, c, d = map(int, input().split())
    if (a > b):
        a, b = b, a
    if (c > d):
        c, d = d, c
    # c выше d ниже или наоборот
    cnt = 0
    if (c > a and c < b):
        cnt += 1
    if (d > a and d < b):
        cnt += 1
    if (cnt == 1):
        ans.append("YES")
        # print("YES")
    else:
        ans.append("NO")
        # print("NO")
    # if (c <= a or c >= b) and (d <= b):
    #     ans.append("YES")
    #     return
    # c, d = d, c
    # if (c <= a or c >= b) and (d <= b):
    #     ans.append("YES")
    #     return
    # ans.append("NO")

    # lst = [0] * 13 # 1...12
    # for i in range(c, d + 1):
    #     lst[i] = True
    # flag = False
    # for j in range(a, b + 1):
    #     flag |= lst[j]
    # if (flag):
    #     print("YES")
    # else:
    #     print("NO")
    


    
t = int(input())
for _ in range(t):
    solve()
for el in ans:
    print(el)
