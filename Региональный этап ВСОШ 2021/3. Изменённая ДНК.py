from math import inf
s = input()
let = ["A", "C", "G", "T"]

def fast(s):
    data = []
    cnt = ""
    def get_symb_insert(symb):
        if symb != "A":
            return "A"
        if symb != "C":
            return "C"
        if symb != "G":
            return "G"
        return "T"

    for i in s:
        if i.isdigit():
            cnt += i
        else:
            if cnt == "":
                data.append((1, i))
            else:
                data.append((int(cnt), i))
            cnt = ""

    min_len = len(s)
    cmd_min = (2, 1)
    max_len = len(s)
    cmd_max = None
    now_simv = 0
    for i in range(len(data)):
        now_simv += data[i][0]
        # ищем min
        if data[i][0] == 1:
            if i >= 1 and i <= len(data) - 2 and data[i-1][1] == data[i+1][1]:
                if len(s) - 2 - len((str(data[i-1][0]) if data[i-1][0] != 1 else "") + (str(data[i+1][0]) if data[i+1][0] != 1 else "")) + len(str(data[i-1][0] + data[i+1][0])) < min_len:
                    min_len = len(s) - 2 - len((str(data[i-1][0]) if data[i-1][0] != 1 else "") + (str(data[i+1][0]) if data[i+1][0] != 1 else "")) + len(str(data[i-1][0] + data[i+1][0]))
                    cmd_min = (2, now_simv)
            else:
                if len(s) - 1 < min_len:
                    min_len = len(s) - 1
                    cmd_min = (2, now_simv)
        elif data[i][0] == 2:
            if len(s) - 1 < min_len:
                min_len = len(s) - 1
                cmd_min = (2, now_simv)
        if data[i][0] == 10 ** (len(str(data[i][0])) - 1):
            if len(s) - 1 < min_len:
                min_len = len(s) - 1
                cmd_min = (2, now_simv)
        # max len
        if data[i][0] == int("9" * len(str(data[i][0]))):
            if len(s) + 1 > max_len:
                max_len = len(s) + 1
                cmd_max = (1, now_simv, data[i][1])
        if data[i][0] == 1:
            if len(s) + 1 > max_len:
                max_len = len(s) + 1
                cmd_max = (1, now_simv, data[i][1])
        if data[i][0] == 2:
            if len(s) + 1 > max_len:
                max_len = len(s) + 1
                cmd_max = (1, now_simv - 1, get_symb_insert(data[i][1]))
        if data[i][0] == 3:
            if len(s) + 2 > max_len:
                max_len = len(s) + 2
                cmd_max = (1, now_simv - 1, get_symb_insert(data[i][1]))
        if data[i][0] > 3:
            a = data[i][0] // 2
            if len(s) - len(str(data[i][0])) + 2 + (len(str(a))) + len(str(data[i][0] - a)) > max_len:
                max_len = len(s) - len(str(data[i][0])) + 2 + (len(str(a))) + len(str(data[i][0] - a))
                cmd_max = (1, now_simv - data[i][0] + a, get_symb_insert(data[i][1]))
        if data[i][0] >= 11:
            a = int("1" + "0" * (len(str(data[i][0])) - 1))
            two = data[i][0] - a
            if len(s) - len(str(data[i][0])) + 2 + (len(str(a))) + len(str(two)) > max_len:
                max_len = len(s) - len(str(data[i][0])) + 2 + (len(str(a))) + len(str(data[i][0] - a))
                cmd_max = (1, now_simv - two, get_symb_insert(data[i][1]))

    print(*cmd_min)
    print(*cmd_max)
fast(s)