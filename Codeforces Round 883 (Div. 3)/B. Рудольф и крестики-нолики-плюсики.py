t = int(input())

def sol(s):
    for i in range(3):
        if s[i][0] == s[i][1] == s[i][2]:
            if s[i][0] != ".":
                return s[i][0]
        if s[0][i] == s[1][i] == s[2][i]:
            if s[0][i] != '.':
                return s[0][i]
    if s[0][0] == s[1][1] == s[2][2]:
        if s[0][0] != '.':
            return s[0][0]
    if s[2][0] == s[1][1] == s[0][2]:
        if s[2][0] != ".":
            return s[2][0]
    return "DRAW"
            

for _ in range(t):
    s = [input() for _ in range(3)]
    print(sol(s))
