data = []
for _ in range(int(input())):
    time, x, y = input().split()
    x, y = int(x), int(y)
    h, m, s = map(int, time.split(":"))
    time = 3600 * h + 60 * m + s
    data.append((time, x, y))
data.sort(key=lambda x: x[0])
min_speed = 10 ** 9
max_speed = -(10 ** 9)
for i in range(1, len(data)):
    now = data[i]
    prev = data[i-1]
    time = now[0] - prev[0]
    s = ((now[1] - prev[1]) ** 2 + (now[2] - prev[2]) ** 2) ** 0.5
    speed = s / time
    min_speed = min(min_speed, speed)
    max_speed = max(max_speed, speed)
print(min_speed, max_speed)

