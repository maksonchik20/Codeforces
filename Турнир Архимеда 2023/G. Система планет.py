from sys import exit
n, k = map(int, input().split())
x = list(map(int, input().split()))
left = 0
right = 10**9+1
def good(m):
    cnt = 0
    for el in x:
        if el <= m:
            cnt += 1
    if cnt == k:
        print(m)
        exit()
    if cnt > k:
        return True
    else:
        return False
while left + 1 != right:
    m = (left + right) // 2
    if good(m):
        right = m
    else:
        left = m
print(-1)