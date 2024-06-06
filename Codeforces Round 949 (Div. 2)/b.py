lst = [i for i in range(19198 - 10, 19198 + 10 + 1)]
res = 0
for el in lst:
    res |= el
print(res)
