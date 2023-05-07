from math import inf
for _ in range(int(input())):
    n = int(input())
    min_t_1 = inf
    min_t_2 = inf
    min_t_1_and_2 = inf
    for i in range(n):
        m, s = input().split()
        m = int(m)
        a1 = int(s[0])
        a2 = int(s[1])
        if a1 == 1 and a2 == 1:
            min_t_1_and_2 = min(min_t_1_and_2, m)
        if a1 == 1:
            min_t_1 = min(min_t_1, m)
        if a2 == 1:
            min_t_2 = min(min_t_2, m)
    print(min(min_t_1 + min_t_2, min_t_1_and_2) if min(min_t_1 + min_t_2, min_t_1_and_2) != inf else -1)