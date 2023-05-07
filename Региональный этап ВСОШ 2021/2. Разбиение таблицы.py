from math import inf
for _ in range(int(input())):
    n, m = map(int, input().split())
    # Vertical razrez
    S_col = (2 + m*(n-1)) * n // 2
    l = 1
    r = m + 1
    min_verical = inf
    min_vertical_i = 0
    while l < r - 1:
        i = (l + r) // 2
        S_all_left = (2 * S_col + n*(i-2)) * (i-1) // 2
        S_col_right = ((2 * i) + m*(n-1))*n // 2
        S_all_right = ((2*S_col_right) + n*(m-i)) * (m-i+1) // 2
        # print(i, S_all_left, S_all_right)
        if S_all_left - S_all_right > 0:
            r = i
        else:
            l = i
        if abs(S_all_left - S_all_right) < min_verical:
            min_vertical_i = i
            min_verical = abs(S_all_left - S_all_right)
    # print(min_vertical_i, min_verical)

    # Horizontal razrez
    l = 1
    r = n + 1
    min_hor_i = 0
    min_hor = inf
    while l < r - 1:
        i = (l + r) // 2
        S_all_top = (1 + m*(i-1))*m*(i-1) // 2
        S_all_bottom = ((m*(i-1) + 1) + m*n) * (n*m - (m*(i-1) + 1) + 1) // 2
        if S_all_top - S_all_bottom > 0:
            r = i
        else:
            l = i
        if abs(S_all_top - S_all_bottom) < min_hor:
            min_hor_i = i
            min_hor = abs(S_all_top - S_all_bottom)
    # print(min_hor_i, min_hor)
    def f_hor(i):
        S_all_top = (1 + m*(i-1))*m*(i-1) // 2
        S_all_bottom = ((m*(i-1) + 1) + m*n) * (n*m - (m*(i-1) + 1) + 1) // 2
        return abs(S_all_top - S_all_bottom)
    def f_vert(i):
        S_all_left = (2 * S_col + n*(i-2)) * (i-1) // 2
        S_col_right = ((2 * i) + m*(n-1))*n // 2
        S_all_right = ((2*S_col_right) + n*(m-i)) * (m-i+1) // 2
        return abs(S_all_left - S_all_right)
    if min_verical <= min_hor:
        if min_vertical_i >= 3 and f_vert(min_vertical_i) == f_vert(min_vertical_i - 1):
            print("V", min_vertical_i - 1)
        else:
            print("V", min_vertical_i)
    else:
        if min_hor_i >= 3 and f_hor(min_hor_i) == f_hor(min_hor_i - 1):
            print("H", min_hor_i - 1)
        else:
            print("H", min_hor_i)
