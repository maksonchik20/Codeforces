library_weight = int(input())
volume_min = library_weight + 50
distance_min = 30

l_min = 6
w_min = 2
h_min = 1

while True:
    volume = (h_min-30) * w_min * l_min
    if volume >= volume_min * 1000 and h_min >= distance_min:
        print(l_min, w_min, h_min)
        break
    l_min+=6
    w_min+=2
    h_min += 1
