from math import inf
a, b = float(input()), float(input())
nich_min = inf
nich_max = 0
alls = 0
def req(a, b, nich=0, all=0):
    global nich_max, nich_min, alls
    if a == 0 and b == 0:
        return nich, all
    if a - 0.5 >= 0 and b - 0.5 >= 0:
        res1 = req(a-0.5, b-0.5, nich+1, all+1)
        if res1 is not False:
            nich_max = max(nich_max, res1[0])
            alls = max(alls, res1[1])
            nich_min = min(nich_min, res1[0])
    if a - 1 >= 0:
        res1 = req(a-1, b, nich, all+1)
        if res1 is not False:
            nich_max = max(nich_max, res1[0])
            alls = max(alls, res1[1])
            nich_min = min(nich_min, res1[0])
    if b - 1 >= 0:
        res1 = req(a, b-1, nich, all+1)
        if res1 is not False:
            nich_max = max(nich_max, res1[0])
            alls = max(alls, res1[1])
            nich_min = min(nich_min, res1[0])
    return False


req(a, b)
print(alls, (nich_min if nich_min != inf else 0), nich_max, sep="\n")