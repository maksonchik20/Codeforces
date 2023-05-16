from sys import setrecursionlimit

setrecursionlimit(10**8)
t = int(input())
n = int(input())
one_to_two = [("one", int(input()), int(input())) for _ in range(n)]
m = int(input())
two_to_one = [("two",int(input()), int(input())) for _ in range(m)]
all = sorted(one_to_two + two_to_one, key=lambda x: x[1])
cnt = 0
sl = {"one": "two", 'two': 'one'}
def search(search_time, serch=None):
    for i in range(len(all)):
        if len(all) != 0 and all[i][1] >= search_time and all[i][0] == serch:
            search_time_now = all[i][2] + t
            serch = sl[all[i][0]]
            all.pop(i)
            if len(all) != 0:
                return search(search_time_now, serch)

while all != []:
    search_time = all[0][2] + t
    serch = sl[all[0][0]]
    all.pop(0)
    if len(all) != 0:
        search(search_time, serch)
    cnt += 1
print(cnt)