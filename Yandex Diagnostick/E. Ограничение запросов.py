userLimit, serviceLimit, duration = map(int, input().split())
users = {}
requests = []
oldTime = 0
while (inp := input()) != "-1":
    time, user = map(int, inp.split())
    if time - oldTime > duration:
        requests = list(filter(lambda x: time-x <= duration, requests))
        if len(requests) > 0:
            oldTime = requests[0]
    if len(requests) < serviceLimit:
        if users.get(user) is not None:
            users[user] = list(filter(lambda x: time - x <= duration, users[user]))
            if len(users[user]) < userLimit:
                users[user].append(time)
                requests.append(time)
                print("200")
            else:
                print("429")
        else:
            users[user] = [time]
            requests.append(time)
            print("200")
    else:
        if users.get(user) is not None:
            users[user] = list(filter(lambda x: time - x <= duration, users[user]))
            if len(users[user]) >= userLimit:
                print("429")
            else:
                print("503")
        else:
            print("503")
        
            