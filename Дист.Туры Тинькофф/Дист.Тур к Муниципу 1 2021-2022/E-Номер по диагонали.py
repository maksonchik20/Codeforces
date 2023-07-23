N, M, q = map(int, input().split())
queries = list(map(int, input().split()))
matrix = [[None for _ in range(M)] for _ in range(N)]
number = 1
sl = {}
for i in range(N + M - 1):
    x , y = 0, i
    for j in range(y, -1, -1):
        if x >= N:
            break
        if y >= M:
            offset = i - M + 1
            x, y = x + offset, y - offset
        matrix[x][y] = number
        sl[number] = (x + 1, y + 1)
        number += 1
        x, y = x + 1, y - 1
from pprint import pprint
pprint(matrix)
for el in queries:
    print(*sl[el])