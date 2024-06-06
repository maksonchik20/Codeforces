def count_points_in_circle(radius):
    cnt = 0
    x0 = 1
    x1 = radius
    for y in range(radius):
        while x1 ** 2 + y**2 > radius ** 2:
            x1 -=1
        cnt += x1 - x0
    return cnt
R = int(input())
count = count_points_in_circle(R)
print(4*R + 4*count + 1)