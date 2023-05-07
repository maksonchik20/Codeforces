def bfs(graph, source):
    global a
    global visited
    bfs_traversal = list()
    queue = list()
    
    queue.append(source)
    visited.add(source)
    min_path = a[source-1]
    while queue:
        current_node = queue.pop(0)
        bfs_traversal.append(current_node)
        for neighbour_node in graph[current_node]:
            if neighbour_node not in visited:
                visited.add(neighbour_node)
                min_path = min(min_path, a[neighbour_node-1])
                queue.append(neighbour_node)
    return min_path

graph = {}
n, m = map(int, input().split())
a = list(map(int, input().split()))
for i in range(1, n+1):
    graph[i] = []
for _ in range(m):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)

visited = set()
cnt = 0
for i in range(1, n+1):
    if i not in visited:
        cnt += bfs(graph, i)
print(cnt)



