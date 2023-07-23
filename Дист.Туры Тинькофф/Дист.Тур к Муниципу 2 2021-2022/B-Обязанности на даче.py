p1, n1, t1 = map(int, input().split())
p2, n2, t2 = map(int, input().split())
if p1 + n1*t1 <= p2 + n2*t2:
    print(1, p1 + n1*t1)
else:
    print(2, p2 + n2*t2)
