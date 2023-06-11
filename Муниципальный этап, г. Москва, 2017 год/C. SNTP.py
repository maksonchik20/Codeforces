from math import ceil, floor
h1, m1, s1 = map(int, input().split(":"))
h2, m2, s2 = map(int, input().split(":"))
h3, m3, s3 = map(int, input().split(":"))

all_s1 = 3600 * h1 + 60 * m1 + s1
all_s2 = 3600 * h2 + 60 * m2 + s2
all_s3 = 3600 * h3 + 60 * m3 + s3
zad = abs(all_s3 - all_s1) / 2
if zad - int(zad) != 0:
    if zad - int(zad) < 0.5:
        zad = int(floor(zad))
    else:
        zad = int(ceil(zad))
res_s = all_s2 + zad
h = (res_s // 3600) % 24
res_h = str(int(h)) if len(str(int(h))) == 2 else f"0{int(h)}"
res_m = str(int(res_s % 3600 // 60)) if len(str(int(res_s % 3600 // 60))) == 2 else f"0{(res_s % 3600 // 60)}"
if res_s % 3600 % 60 - int(res_s % 3600 % 60) != 0:
    if res_s % 3600 % 60 - int(res_s % 3600 % 60) < 0.5:
        res_sec_okr = int(floor(res_s % 3600 % 60))
    else:
        res_sec_okr = int(ceil(res_s % 3600 % 60))
else:
    res_sec_okr = int(res_s % 3600 % 60)
res_s = str(int(res_sec_okr)) if len(str(int(res_sec_okr))) == 2 else f"0{int(res_sec_okr)}"
print(f"{res_h}:{res_m}:{res_s}")