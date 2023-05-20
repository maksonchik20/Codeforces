for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    if n == 1:
        print("YES")
    else:
        _min = min(a)
        search_ost = _min % 2
        _min_dr_ch = 10 ** 9 + 300
        for el in a:
            if el < _min_dr_ch and el % 2 != search_ost:
                _min_dr_ch = el
        flag = True
        for el in a:
            if el == _min or el % 2 == search_ost:
                continue
            if (el - _min) % 2 != search_ost:
                if _min_dr_ch == 10 ** 9 + 300:
                    continue
                if (el - _min_dr_ch) <= 0 or (el - _min_dr_ch) % 2 != search_ost:
                    print("NO")
                    flag = False
                    break
        if flag:
            print("YES")