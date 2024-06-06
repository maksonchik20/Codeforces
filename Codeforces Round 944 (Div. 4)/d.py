def solve():
    s = input()
    cnt = 1
    now = s[0]
    for i in range(1, len(s)):
        if (s[i] == now):
            continue
        else:
            now = s[i]
            cnt += 1
    # print(cnt)
    if "0" in s:
        ind = s.index("0")
        # print(s[ind:])
        if ("1" in s[ind:]):
            cnt -= 1
    print(cnt)

    


    
t = int(input())
for _ in range(t):
    solve()