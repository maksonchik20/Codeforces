now = int(input())
if now != -1:
    if now == 5:
        print(3)
    elif now == 7:
        print(1)
        inp = int(input())
        while inp != -1:
            print(3)
            inp = int(input())
    elif now == 2:
        print(9)
        inp = int(input())
        while inp != -1:
            print(9)
            inp = int(input())
    elif now == 3:
        print(7)
        inp = int(input())
        if inp == 9:
            print(7)
            inp = int(input())
        if inp == 3:
            print(3)
            inp = int(input())
            if inp == 9:
                print(3)
                inp = int(input())
            if inp == 7:
                while inp != -1:
                    print(9)
                    inp = int(input())
        elif inp == 9:
            print(7)
            inp = int(input())
