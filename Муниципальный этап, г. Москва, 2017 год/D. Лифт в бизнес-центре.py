k = int(input())
n = int(input())
data = [0] * (n + 1)
flag = True
cnt = 0
now = 0
for i in range(1, n + 1):
    data[i] = int(input())
    cnt += data[i]
    now = i if data[i] != 0 else now
time = now
now_k = k
while now != 0:
    # time += now
    if data[now] > now_k:
        time += 2*now
        data[now] -= now_k
        # if now_k != k:
        #     now_k = k
    elif data[now] == now_k:
        # time += now
        data[now] -= now_k
        while now != 0 and data[now] == 0:
            now -= 1
            time += 1
        time += 2*now
    else:
        # time += now
        now_k -= data[now]
        data[now] = 0
        while now != 0 and data[now] == 0:
            if data[now] == 0:
                now -= 1 
                time += 1
            if data[now] != 0:
                if data[now] >= now_k:
                    time += now if data[now] == now_k else 2 * now
                    data[now] -= now_k
                    now_k = k
                    break
                else:
                    data[now] = 0
                    now_k -= data[now]
print(time)
        
        



