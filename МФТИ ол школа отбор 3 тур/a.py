lst = [list(map(int, input().split())), list(map(int, input().split())), list(map(int, input().split()))]
lst.sort(key=lambda x: (-x[0], x[1]))
print(lst[0][0] + lst[1][0], lst[0][1] + lst[1][1])
