x = input()
k = int(input())
def get_str(s):
    arr = []
    for i in range(len(s)):
        for j in range(10):
            s_copy = str(s)
            s_copy = s_copy[:i] + str(j) + s_copy[i+1:]
            arr.append(int(s_copy))
    return arr
def fast(x, k):
    if k == 0:
        _max = int(x[0])
        flag = True
        arr = []
        for i in range(1, 10):
            arr.append(int(len(x) * str(i)))
            if int(len(x) * str(i)) >= int(x):
                print(int(len(x) * str(i)))
                flag = False
                break
        if flag:
            print("1" + "0"*len(x))
    else:
        flag = True
        arr = []
        for i in range(10):
            arr.extend(get_str(str(i) * len(x)))
        arr.sort()
        for el in arr:
            if int(el) >= int(x):
                print(el)
                flag = False
                break
fast(x, k)