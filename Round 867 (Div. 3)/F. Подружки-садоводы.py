def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)

    print(start)

    for next in graph[start] - visited:
        dfs(graph, next, visited)
    return visited


graph = {1: {4, 6, 5},
         2: {6, 3},
         3: {2},
         4: {1},
         5: {1},
         6: {1, 2}
         }

dfs(graph, 3)