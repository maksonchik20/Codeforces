def solution(s):
    if len(s) == 2:
        return "NO"
    sl = {}
    for el in s:
        if sl.get(el) is None:
            sl[el] = 1
        else:
            sl[el] += 1
    if len(s) % 2 == 0:
        if len(sl.items()) >= 2:
            return ("YES")
        else:
            return ("NO")
    else:
        if len(sl.items()) == 1:
            return "NO"
        else:
            sred = s[len(s) // 2]
            ones = None
            for el in sl.items():
                if el[1] >= 2:
                    if ones is None:
                        ones = (el[0], el[1])
                    else:
                        return "YES"
    return "NO"
                

        

for _ in range(int(input())):
    s = input()
    print(solution(s))