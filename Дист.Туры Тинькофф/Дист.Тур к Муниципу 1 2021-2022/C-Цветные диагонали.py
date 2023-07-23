from string import ascii_lowercase
import collections

def get_sosedi(x, y):
    global n
    result = []
    if x >= 1:
        result.append((x-1, y))
    if y >= 1:
        result.append((x, y-1))
    if x <= n - 2:
        result.append((x+1, y))
    if y <= n - 2:
        result.append((x, y+1))
    return result

def bfs(matrix, roots): 
    global alphabet, now_alphabet
    visited, queue = set(), collections.deque([*roots])
    for root in roots:
        visited.add(root)
    queue_prev = []
    while queue: 
        vertex = queue.popleft()
        for neighbour in get_sosedi(*vertex): 
            if neighbour not in visited:
                visited.add(neighbour)
                queue_prev.append(neighbour)
                matrix[neighbour[0]][neighbour[1]] = alphabet[now_alphabet % 26]
        if not queue:
            now_alphabet += 1
            for el in queue_prev:
                queue.append(el)
            queue_prev = []
        
n = int(input())
alphabet = ascii_lowercase
now_alphabet = 1
matrix = [[0] * n for _ in range(n)]
roots = []
i = 0
j = 0
while i != n:
    roots.append((i, i))
    roots.append((j, n - j - 1))
    matrix[i][i] = alphabet[0]
    matrix[j][n-j-1] = alphabet[0]
    j += 1
    i += 1
bfs(matrix, roots)
for i in range(n):
    print(*matrix[i], sep="")