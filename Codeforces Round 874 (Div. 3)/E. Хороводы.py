def dfs(graph, start):
    global visited, components
    visited[start] = True

    components[-1].append(start)
    for path in graph[start]:
        if visited.get(path) is None:
            dfs(graph, path)

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    graph = {}
    for i in range(1, n + 1):
        graph[i] = []
    for i in range(1, len(a)+1):
        graph[i].append(a[i-1])
        graph[a[i-1]].append(i)
    visited = {}
    cnt = 0
    _min = 0
    components = []
    for i in range(1, n + 1):
        if graph[i] != [] and visited.get(i) is None:
            components.append([])
            dfs(graph, i)
            cnt += 1
    for comp in components:
        ...
    print(components)
    print(_min, cnt)
