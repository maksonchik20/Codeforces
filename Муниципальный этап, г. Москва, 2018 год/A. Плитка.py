m, x, y, w, h = int(input()), int(input()), int(input()), int(input()), int(input())
dx = ((x+w) - ((x//m) + (1 if x % m != 0 else 0)) * m) // m
if x % m != 0:
    dx += 1
if (x + w) % m != 0:
    dx += 1
dy = ((y+h) - ((y//m + (1 if y % m != 0 else 0)) * m)) // m
if y % m != 0:
    dy += 1
if (y + h) % m != 0:
    dy += 1
print(dx*dy)