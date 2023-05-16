def LastGrayPrefFunc():
    stringLastGrayPrefFunc = [0, 0, 1]
    last = 1
    for i in range(3, 27):
        stringLastGrayPrefFunc.append(0)
        stringLastGrayPrefFunc.append(2 * last + 1)
        stringLastGrayPrefFunc.extend(stringLastGrayPrefFunc[1:-2])
        last = 2 * last + 1
    return stringLastGrayPrefFunc

fast_pref_func = LastGrayPrefFunc()
print("GOOD")