A, B, C, k = map(int, input().split())

now_all_k = 0
for a in range(10 ** (A - 1), 10 ** A):
    min_b = max(10 ** (C-1) - a, 1)
    max_b = 10 ** B - 1
    # if len(str(min_b)) != B or len(str(max_b)) != B:
    #     continue
    now_all_k += max_b - min_b + 1
    print(a, max_b - min_b + 1)