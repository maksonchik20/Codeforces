n = int(input())
sum_horizontal = 0
sum_vertical = 0
all_sum = 0
sl = {}
parallel_sums = {}
for _ in range(n):
    inp = list(map(int, input().split()))
    if inp[0] == 1:
        _, a, b, c, q = inp
        if a == 0 and b != 0:
            sum_horizontal += q
            all_sum += q
        elif a != 0 and b == 0:
            sum_vertical += q
            all_sum += q
        else:
            parallel_sums[a/b] = q if parallel_sums.get(a/b) is None else parallel_sums[a/b] + q
            sum_vertical += q
            sum_horizontal += q
            all_sum += q
        sl[(a, b, c)] = q if sl.get((a, b, c)) is None else sl.get((a, b, c)) + q
    else:
        _, a, b, c = inp
        if sl.get((a, b, c)) is not None:
            if sl.get((a, b, c)) == 0:
                print(0)
            else:
                print('inf') 
            continue     
        elif sl.get((-a, -b, -c)) is not None:
            if sl.get((-a, -b, -c)) == 0:
                print(0)
            else:
                print("inf")
            continue
        if a == 0 and b != 0:
            print(sum_vertical)
        elif b == 0 and a != 0:
            print(sum_horizontal)
        else:
            parallel__sum = parallel_sums.get(a/b, 0)
            print(all_sum - parallel__sum)