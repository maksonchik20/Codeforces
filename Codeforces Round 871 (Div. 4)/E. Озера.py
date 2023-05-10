def not_null_get_sosedi(i, j, a):
    global n, m
    arr = []
    if i+1 < n and a[i+1][j] != 0:
        arr.append((i+1, j))
    if i-1 >= 0 and a[i-1][j] != 0:
        arr.append((i-1, j))
    if j+1 < m and a[i][j+1] != 0:
        arr.append((i, j+1))
    if j-1 >= 0 and a[i][j-1] != 0:
        arr.append((i, j-1))
    return arr

def dfs(start_i, start_j, a, cnt=0):
    global visited
    visited.add((start_i, start_j))
    cnt += a[start_i][start_j]
    for path in not_null_get_sosedi(start_i, start_j, a):
        if path not in visited:
            cnt += dfs(*path, a)
    return cnt


for _ in range(int(input())):
    n, m = map(int, input().split())
    data = [list(map(int, input().split())) for _ in range(n)]
    visited = set()
    _max = 0
    for i in range(n):
        for j in range(m):
            if (i, j) not in visited and data[i][j] != 0:
                _max = max(_max, dfs(i, j, data))
    print(_max)