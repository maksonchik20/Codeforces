from math import ceil
for _ in range(int(input())):
    n = int(input())
    s = input()
    if n % 2:
        print(-1)
        continue
    sl = {}
    flag = False
    for let in s:
        if sl.get(let) is None:
            sl[let] = 1
        else:
            sl[let] += 1
            if sl[let] > n//2:
                print(-1)
                flag = True
                break
    if flag:
        continue
    stack = []
    cnt = 0
    sl = {}
    _max = 0
    el = None
    for i in range(n//2):
        if s[i] == s[-(i+1)]:
            stack.append(s[i])
            if sl.get(s[i]) is None:
                sl[s[i]] = 1
                _max = max(_max, sl[s[i]])
                if el is None:
                    el = s[i]
            else:
                sl[s[i]] += 1
                if sl[s[i]] > _max:
                    _max = sl[s[i]]
                    el = s[i]
    print(max(ceil(len(stack)/2), _max))
