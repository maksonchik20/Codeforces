def fast(a, b, c):
    cnt = 0
    flag = True
    if c > a and c > b:
        return 0
    if c == 1:
        return b - a + 1
    if a % c == 0 and b % c == 0:
        return (b - a) // c + 1
    if a % c == 0 or b % c == 0:
        return (b - a) // c + 1
    if a % c != 0 and b % c != 0:
        first_a = (a // c + 1) * c
        first_b = (b // c) * c
        return (first_b - first_a) // c + 1
a, b, c = int(input()), int(input()), int(input())
print(fast(a, b, c))