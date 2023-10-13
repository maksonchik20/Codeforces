t = int(input())
arr = ['5', '6', '7', '8', '9']
for _ in range(t):
    x = list(input())[::-1]
    x += ['0']
    j = 0
    for i in range(len(x)):
        if (x[i] >= '5'):
            x[i + 1] = str(int(x[i+1]) + 1)
            for k in range(i, j-1, -1):
                x[k] = '0'
            j = i
            
    x = x[::-1]
    if (x[0] == '0'):
        print("".join(x[1:]))
    else:
        print("".join(x))
    