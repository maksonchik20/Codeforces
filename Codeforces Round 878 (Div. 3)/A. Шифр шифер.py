for _ in range(int(input())):
    input()
    s = input()
    left = 0
    right = 1
    res = ""
    while left != len(s):
        while right <= len(s) - 1 and s[right] != s[left]:
            right += 1
        res += s[left]
        left = right + 1
        right = left + 1
    print(res)
