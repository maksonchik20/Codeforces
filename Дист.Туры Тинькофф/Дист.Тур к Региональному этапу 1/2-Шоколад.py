n = int(input())
s1 = list(map(int, input().split()))
s2 = list(map(int, input().split()))
sl2 = {}
for i in range(n):
    sl2[s2[i]] = i
cnt = 0
for i in range(n):
    now_let_1 = s1[i]
    if sl2[now_let_1] == n-1:
        cnt += 1
    else:
        if i == n-1:
            cnt += 1
        else:
            next_s1 = s1[i+1]
            ind_s2 = sl2[now_let_1]
            if sl2[s1[i+1]] == ind_s2 + 1:
                continue
            else:
                cnt += 1
print(cnt)