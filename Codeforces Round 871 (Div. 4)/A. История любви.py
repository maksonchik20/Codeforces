orig = "codeforces"
for _ in range(int(input())):
    s = input()
    cnt = 0
    for i in range(len(s)):
        if s[i] != orig[i]:
            cnt += 1
    print(cnt)
