m, n = map(int, input().split())
a = list(map(int, input().split()))
def fast(m, n, a):
    k = len(set(a))
    sl = {}
    for i in range(len(a)):
        if sl.get(a[i]) is None:
            sl[a[i]] = {"cnt": 1, "left": i+1, "right": i+1}
        else:
            sl[a[i]]["cnt"] += 1
            sl[a[i]]["right"] = i + 1
    # instruction = [0] * m
    # test = [0] * m
    # for el in sorted(sl.items(), key=lambda x: x[1]["right"] - x[1]["left"], reverse=True):
        # instruction.append((el[0], el[1]["left"], el[1]["right"]))
        # test[el[1]["left"]-1 : el[1]["right"]] = [el[0]] * (el[1]["right"] - el[1]["left"] + 1)
    return (k, sorted(sl.items(), key=lambda x: x[1]["right"] - x[1]["left"], reverse=True))
    # if test == a:
    #     return (k, instruction)
    # else:
    #     return -1
def check(m, n, a):
    sl = {}
    stack = []
    l = {}
    for i in range(len(a)):
        if sl.get(a[i]) is None:
            sl[a[i]] = 2
            l[a[i]] = i
            stack.append(a[i])
        elif sl[a[i]] == 2:
            for el in stack[:i]:
                if el != a[i]:
                    sl[a[i]] = 3
        elif sl[a[i]] == 3:
            print(-1)
            return False
    return True
if check(m, n, a):
    res = fast(m, n, a)
    print(res[0])
    for el in res[1]:
        print(el[0], el[1]["left"], el[1]["right"])
        

