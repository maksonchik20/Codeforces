from collections import defaultdict
import heapq

# graph = {
#     '1': [('4', 1), ('2', 1)],
#     '2': [('5', 1), ('1', 1)],
#     '3': [('6', 1)],
#     '4': [],
#     '5': [],
#     '6': [('2', 1), ('3', 1)]
# }
# У каждого два друга.

def get_sosedi(x, y):
    arr = []
    _min = 0
    _max = 10**10
    if x+2 <= 10**10 and y+1 <= 10**10:
        arr.append((x+2, y+1, 1))
    if x+1 <= 10**10 and y+2 <= 10**10:
        arr.append((x+1, y+2, 1))
    if x-1 >= 0 and y+2 <= 10**10:
        arr.append((x-1, y+2, 1))
    if x+2 <= 10**10 and y-1 >= 0:
        arr.append((x+2, y-1, 1)) 
    if x+1 <= 10**10 and y-2 >= 0:
        arr.append((x+1, y-2, 1))
    if x-2 >= 0 and y+1 <= 10**10:
        arr.append((x-2, y+1, 1))
    if x-1 >= 0 and y-2 >= 0:
        arr.append((x-1, y-2, 1))
    if x-2 >=0 and y-1 >= 0:
        arr.append((x-2, y-1, 1))
    return arr

def dijkstra(start: str):
    result_map = defaultdict(lambda: float('inf'))
    result_map[start] = 0

    visited = set()

    queue = [(0, start)]

    while queue:
        weight, v = heapq.heappop(queue)
        visited.add(v)
        for u, v, w in get_sosedi(*v):
            if u not in visited:
                result_map[(u, v)] = min(w + weight, result_map[(u, v)])
                heapq.heappush(queue, [w + weight, (u, v)])
            if (u, v) == (x, y):
                return result_map[(u, v)]
            print(result_map)
    return result_map
x, y = int(input()) + 10**5, int(input()) + 10**5
print(dijkstra(start=(10**5, 10**5)))


