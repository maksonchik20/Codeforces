from math import gcd

n, p, q = map(int, input().split())
result = []
for chisl in range(1, n + 1):
    for znam in range(1, n + 1):
        if gcd(chisl, znam) != 1:
            continue
        if q < (znam / chisl) < p:
            result.append((chisl / znam, chisl, znam))
result.sort(key=lambda x: x[0])
for el in result:
    print(f"{el[1]}/{el[2]}")

