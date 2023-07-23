s = int(input())
s = str(s)
cnt = 0
while s[-1] == "0":
    s = s[:-1]
print(s.count("0"))