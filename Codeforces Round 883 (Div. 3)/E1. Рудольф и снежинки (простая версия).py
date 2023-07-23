import math

t = int(input())

for _ in range(t):
    n = int(input())

    exists = False
    for k in range(2, int(math.sqrt(n)) + 1):
        if (n - 1) % (k) == 0:
            left = 0
            right = n // k + k
            mid = 100
            while (k * (k**mid - 1)) // (k - 1) + 1 < n:
                right *= 2
                mid = (left + right) // 2
            for _ in range(70):
                mid = (left + right) // 2
                f = (k * (k**mid - 1)) // (k - 1) + 1
                if f == n:
                    exists = True
                    break
                elif f > n:
                    right = mid
                else:
                    left = mid
            if exists:
                print("YES")
                break
    if not exists:
        print("NO")