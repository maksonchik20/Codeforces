n = int(input())
s = list(map(int, input().split()))
x = sum(s)
if (x % 4 != 0):
    print(0)
    exit(0)
x //= 4
ps = [0] * (n + 1)
for i in range(1, n + 1):
    ps[i] = ps[i - 1] + s[i - 1]
# print(sums)

def get_sum(l, r): # в 0 индексации
    l += 1
    r += 1
    return ps[r] - ps[l - 1]

res = 0
s1 = 0
s2 = 0

for i in range(1, n):
    if (ps[i] == 3 * x):
        res += s2
    if (ps[i] == 2 * x):
        s2 += s1
    if (ps[i] == x):
        s1 += 1
    # print(i, s1, s2, res)
print(res)