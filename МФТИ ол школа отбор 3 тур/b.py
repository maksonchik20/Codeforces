n = int(input())
lst = [int(input()) for i in range(n)]
lst = lst[::-1]
now = lst[0]
cnt = 1
for i in range(1, n):
    if lst[i] > now:
        cnt += 1
        now = lst[i]
print(cnt)