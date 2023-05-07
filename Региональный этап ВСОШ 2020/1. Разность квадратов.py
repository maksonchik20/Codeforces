n = int(input())
if n == 0:
    print("YES")
    print(1, 1)
else:
    if n % 2:
        x = (n + 1) // 2
        y = x - 1
        if x ** 2 - y ** 2 == n and x != 0 and y != 0:
            print("YES")
            print(x, y)
        else:
            print("NO")
    else:
        x = (n + 4) // 4
        y = (n-4) // 4
        if x ** 2 - y**2 == n and x != 0 and y != 0:
            print("YES")
            print(x, y)
        else:
            print("NO")