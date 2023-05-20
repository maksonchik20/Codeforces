for _ in range(int(input())):
    n = int(input())
    s = input()
    st = set()
    cnt = 0
    for i in range(n - 1):
        if s[i:i+2] not in st:
            cnt += 1
            st.add(s[i:i+2])
    print(cnt)
