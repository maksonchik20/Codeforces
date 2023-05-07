for _ in range(int(input())):
    n, m = map(int, input().split())
    sl = {}
    visited = set()
    for _ in range(m):
        u, v = map(int, input().split())
        sl[u] = [v] if sl.get(u) is None else sl[u] + [v]
        sl[v] = [u] if sl.get(v) is None else sl[v] + [u]
    t = {}
    used = set()
    for u, arr_v in sl.items():
        t[len(arr_v)] = 1 if t.get(len(arr_v)) is None else t[len(arr_v)] + 1
    ones = t[1]
    t = t.items()
    t = sorted(t, key=lambda x: x[1])
    if len(t) == 3:
        print(t[1][1], t[2][1] // t[1][1])
    else:
        print(t[0][1] - 1, t[1][1] // (t[0][1] - 1))