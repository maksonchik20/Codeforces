N = int(input())
M = int(input())
house = [input() for i in range(N)]
water = [input() for i in range(N)]
ans = 0
for dx in range(-N, N + 1):
    for dy in range(-M, M + 1):
        count = 0
        for house_x in range(N):
            for house_y in range(M):
                if house[house_x][house_y] == "H":
                    water_x = house_x + dx
                    water_y = house_y + dy
                    if 0 <= water_x < N and 0 <= water_y < M and water[water_x][water_y] == "W":
                        count = -10 ** 9
                    for neigh_x, neigh_y in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                        water_x = house_x + dx + neigh_x
                        water_y = house_y + dy + neigh_y
                        if 0 <= water_x < N and 0 <= water_y < M and water[water_x][water_y] == "W":
                            count += 1
        ans = max(ans, count)
print(ans)
