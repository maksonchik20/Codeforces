t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    a = []
    b = []
    flag = True
    for i in range(len(s)):
        if s[i].isalpha():
            a.append(s[i])
        elif s[i].isdigit():
            b.append(s[i])
        if i + 1 < len(s) and s[i].isalpha() and s[i + 1].isdigit():
            flag = False
    if a == sorted(a) and b == sorted(b) and flag:
        print("YES")
    else:
        print("NO")