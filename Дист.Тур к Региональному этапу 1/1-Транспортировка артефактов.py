a1, b1, a2, b2, a3, b3 = int(input()), int(input()), int(input()), int(input()), int(input()), int(input())
if a1<b1:
    a1, b1 = b1, a1
if a2<b2:
    a2, b2 = b2, a2
if a3<b3:
    a3, b3 = b3, a3
f = [[a1, b1, a1*b1], [a2, b2, a2*b2], [a3, b3, a3*b3]]
f.sort(key=lambda x:x[2])
# print(f)
next = []
# if (f[0][0] + f[1][0]) * (max(f[0][1], f[1][1])) < (f[0][1] + f[1][1]) * (max(f[0][0], f[1][0])):
next.append([f[0][0] + f[1][0], max(f[0][1], f[1][1]), (f[0][0] + f[1][0]) * max(f[0][1], f[1][1])])
next.append([f[0][1] + f[1][1], max(f[0][0], f[1][0]), max(f[0][0], f[1][0])*(f[0][1] + f[1][1])])
next.append([f[0][1] + f[1][0], max(f[1][1], f[0][0]), (f[0][1] + f[1][0]) * max(f[1][1], f[0][0])])
next = sorted(next, key=lambda x: x[2])
mins = []
for el in next:
    # if (el[0] + f[2][0]) * (max(el[1], f[2][1])) < (el[1] + f[2][1]) * (max(el[0], f[2][0])):
    mins.append((el[0] + f[2][0]) * max(el[1], f[2][1]))
    # else:
    mins.append((el[1] + f[2][1]) * max(el[0], f[2][0]))
    if el[0] < el[1]:
        el[0], el[1] = el[1], el[0]
    if el[0] < el[1]:
        el[0], el[1] = el[1], el[0]
    mins.append((el[0] + f[2][0]) * max(el[1], f[2][1]))
    mins.append((el[1] + f[2][1]) * max(el[0], f[2][0]))
print(min(mins))