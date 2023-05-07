k = int(input())
a, x = map(int, input().split())
b, y = map(int, input().split())
sum1 = 0
sum2 = 0
if k-a > 0:
    sum1 += (k-a) * x
    if k-a-b > 0:
        sum1 += (k-a-b) * y
if k-b > 0:
    sum2 += (k-b) * y
    if k-a-b > 0:
        sum2 += (k-a-b) * x
print(max(sum1, sum2))