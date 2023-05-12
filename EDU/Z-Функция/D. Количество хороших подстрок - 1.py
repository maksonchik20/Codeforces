for _ in range(int(input())):
    cnt = 0
    l = 0
    r = 1
    s, t = input(), input()
    while r <= len(s):
        if r - l < len(t):
            print(s[l:r])
            cnt += 1
            r += 1
            continue
        if t not in s[l:r]:
            cnt += 1
            print(s[l:r])
            r += 1
        else:
            l += 1
            r = l + 1
    r = len(s)
    if l != r:
        while l != r - 1:
            l += 1
            if r - l < len(t):
                cnt += 1
                print(s[l:r])
            else:
                if t not in s[l:r]:
                    cnt += 1
                    print(s[l:r])
    print(cnt)
    # s, t = input(), input()
    # for i in range(len(s)):
    #     for j in range(i + 1, len(s) + 1):
    #         print(i, j, s[i:j])
    #         if t not in s[i:j]:
    #             cnt += 1
    #         else:
    #             break
    # print(cnt)