s = input()
t = input()
def prefix_func(s):
    n = len(s)
    pi = [0] * n
    for i in range(1, n):
        j = pi[i-1]
        while j > 0 and s[i] != s[j]:
            j = pi[j-1]
        if s[i] == s[j]:
            j += 1
        pi[i] = j
    return pi
def fast():
    pr = prefix_func(t + "$" + s)[len(t) + 1:]
    for i in range(len(pr)):
        if pr[i] == len(t):
            if not (len(s) - i - 1) % 2 and not (i - len(t) + 1) % 2:
                return "YES"
    return "NO"
print(fast())
