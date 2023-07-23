from math import sqrt
def kv_ur(a, b, c):
    D = sqrt(b * b - 4 * a * c)
    x1 = (-b - D) / (2*a)
    x2 = (-b + D) / (2*a)
    if (x1 > 0 and int(x1) == x1 and x1 * x2 * a + x1 * b + c == 0):
        return int(x1)
    else:
        return int(x2)
for _ in range(int(input())):
    n, c = map(int, input().split())
    arr_n = list(map(int, input().split()))
    cnt_a = 0
    cnt_b = 0
    cnt_c = -c
    for el in arr_n:
        cnt_a += 4
        cnt_b += el * 4
        cnt_c += el * el
    print(kv_ur(cnt_a, cnt_b, cnt_c))