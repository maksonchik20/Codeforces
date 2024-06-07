t = int(input())
for _ in range(t):
    x, y = map(int, input().split())
    a = bin(x)[2:][::-1]
    b = bin(y)[2:][::-1]
    if len(a) > len(b):
        a, b = b, a
    if b.startswith(a):
        res = len(a)
        for i in range(len(a), len(b)):
            if b[i] == "0":
                res += 1
            else:
                break
        print(2 ** res)
        continue
    # print(a, b)
    ans = 0
    for i in range(1, len(a) + 1):
        # print(a[:i], b[:i])
        if a[:i] == b[:i]:
            ans = i
        else:
            break
    print(2 ** ans)
