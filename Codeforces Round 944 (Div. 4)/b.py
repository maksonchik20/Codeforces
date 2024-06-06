def solve():
    s = input()
    alph = list(set(s))
    if (len(alph) == 1):
        print("NO")
    else:
        print("YES")
        a = s.index(alph[0])
        b = s.index(alph[1])
        s = list(s)
        s[a], s[b] = s[b], s[a]
        print("".join(s))
    


t = int(input())
for _ in range(t):
    solve()
