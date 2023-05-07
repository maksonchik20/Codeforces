from string import ascii_lowercase
d, m, w = map(int, input().split())
i, j, k = map(int, input().split())
print(ascii_lowercase[((((k-1) * m + (j-1)) * d + i) - 1) % w])