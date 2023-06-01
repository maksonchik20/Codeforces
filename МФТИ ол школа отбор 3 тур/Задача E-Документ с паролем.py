import re
s = input()
n = int(input())
cnt = 0 
now = ""
for a in range(10):
    for b in range(10):
        for c in range(10):
            for d in range(10):
                new_s = ""
                for let in s:
                    if let == 'a':
                        new_s += str(a)
                    elif let == 'b':
                        new_s += str(b)
                    elif let == 'c':
                        new_s += str(c)
                    elif let == 'd':
                        new_s += str(d)
                    else:
                        new_s += let
                new_s = re.sub(r'0*([1-9][0-9]*|0)',r'\1',new_s)
                res = eval(new_s)
                if res == n:
                    cnt += 1
                    now = f"{a}{b}{c}{d}"
print(cnt)
if cnt == 1:
    print(now)