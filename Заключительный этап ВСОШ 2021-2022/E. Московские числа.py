from string import ascii_uppercase
sl = {
    "A": 1,
    "B": 5,
    "C": 10,
    "D": 50,
    "E": 100,
    "F": 500,
    "G": 1000,
    "H": 5000,
    "I": 10000,
    "J": 50000,
    "K" : 10**5,
    "L": 5 * (10 ** 5),
    "M": 10 ** 6,
    "N": 5 * (10**6),
    "O": 10 ** 7,
    "P": 5 * (10 ** 7),
    "Q": 10 ** 8,
    "R": 5 * (10 ** 8),
    "S": 10 ** 9,
    "T": 5 * (10 ** 9),
    "U": 10 ** 10,
    "V": 5 * (10 ** 10),
    "W": 10 ** 11,
    "X": 5 * (10 ** 11),
    "Y": 10 ** 12,
    "Z": 5 * (10 ** 12)
}
sl_reverv = {}
for el, num in sl.items():
    sl_reverv[num] = el

def solve(s):
    rev_s = s[::-1]
    vpr = []
    def solve_good_str(rev_s):
        now_max = 0
        res = 0
        for let in rev_s:
            if sl[let] >= now_max:
                now_max = sl[let]
                res += sl[let]
            else:
                res -= sl[let]
        return res
    for i in range(len(rev_s)):
        if rev_s[i] == "?":
            vpr.append(i)
    if len(vpr) == 0:
        return (solve_good_str(rev_s), s)
    max_res = 0
    max_res_str = ""
    for bukv in ascii_uppercase:
        for bukv2 in ascii_uppercase:
            for bukv3 in ascii_uppercase:
                if len(vpr) == 1:
                    rev_s = rev_s[:vpr[0]] + bukv + rev_s[vpr[0] + 1:]
                    sgs = solve_good_str(rev_s)
                    if sgs > max_res:
                        max_res = sgs
                        max_res_str = rev_s
                elif len(vpr) == 2:
                    rev_s = rev_s[:vpr[0]] + bukv + rev_s[vpr[0]+1:]
                    rev_s = rev_s[:vpr[1]] + bukv2 + rev_s[vpr[1]+1:]
                    sgs = solve_good_str(rev_s)
                    if sgs > max_res:
                        max_res = sgs
                        max_res_str = rev_s
                elif len(vpr) == 3:
                    rev_s = rev_s[:vpr[0]] + bukv + rev_s[vpr[0]+1:]
                    rev_s = rev_s[:vpr[1]] + bukv2 + rev_s[vpr[1]+1:]
                    rev_s = rev_s[:vpr[2]] + bukv3 + rev_s[vpr[2]+1:]
                    sgs = solve_good_str(rev_s)
                    if sgs > max_res:
                        max_res = sgs
                        max_res_str = rev_s
    return (max_res, max_res_str[::-1])

def fast(s):
    rev_s = s[::-1]
    dp = [[[0, ""] for _ in range(26)] for _ in range(len(s))]
    res = ""
    for i in range(26):
        if rev_s[0] == "?":
            for j in range(26):
                dp[0][i] = [sl[ascii_uppercase[j]], ascii_uppercase[j]]
        else:
            dp[0][i] = [sl[rev_s[0]], rev_s[0]]
            # res += rev_s[0]
    for i in range(1, len(s)):
        for j in range(len(ascii_uppercase)):
            if rev_s[i] != "?":
                dp[i][j] = [dp[i-1][j][0], dp[i-1][j][1] + rev_s[i]]
                if sl[rev_s[i]] >= sl[ascii_uppercase[j]]:
                    dp[i][j][0] += sl[rev_s[i]]
                else:
                    dp[i][j][0] -= sl[rev_s[i]]
            else:
                dp[i][j] = dp[i-1][j]
                _max = -5 * (10**12) - 10
                max_let = ""
                for k in range(26):
                    if sl[ascii_uppercase[k]] >= sl[ascii_uppercase[j]]:
                        if sl[ascii_uppercase[k]] > _max:
                            _max = max(_max, sl[ascii_uppercase[k]])
                            max_let = ascii_uppercase[k]
                    else:
                        if sl[ascii_uppercase[k]] > _max:
                            _max = max(_max, -sl[ascii_uppercase[k]])
                            max_let = ascii_uppercase[k]
                dp[i][j][0] += _max
                dp[i][j][1] = dp[i][j-1][1] + max_let
    print(dp[0])
fast(input())

# t = int(input())
# for _ in range(t):
#     s = input()
#     if s == "????":
#         print(20000000000000)
#         print("ZZZZ")
#     else:
#         print(*solve(s), sep="\n")