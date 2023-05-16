from math import inf
class SegmentTree():
    def __init__(self, n):
        self.size = 1
        while self.size < n:
            self.size *= 2
        self.tree = [(inf, 0)] * (2*self.size - 1)
    
    def set_num(self, i, v, x=0, lx=0, rx=None):
        if rx is None:
            rx = self.size
        if rx - lx  == 1:
            self.tree[x] = (v, 1)
            return
        m = (lx + rx) // 2
        if i < m:
            self.set_num(i, v, 2*x+1, lx, m)
        else:
            self.set_num(i, v, 2*x+2, m, rx)
        if self.tree[2*x + 1][0] < self.tree[2*x + 2][0]:
            self.tree[x] = self.tree[2*x + 1]
        elif self.tree[2*x + 2][0] < self.tree[2*x + 1][0]:
            self.tree[x] = self.tree[2*x + 2]
        else:
            self.tree[x] = (self.tree[2*x+1][0], self.tree[2*x+1][1] + self.tree[2*x+2][1])
    
    def get_sum(self, l, r, x=0, lx=0, rx=None):
        if rx is None:
            rx = self.size
        if l >= rx or lx >= r:
            return (inf, 0)
        if lx >= l and rx <= r:
            return self.tree[x]
        m = (lx + rx) // 2
        s1 = self.get_sum(l, r, 2*x+1, lx, m)
        s2 = self.get_sum(l, r, 2*x+2, m, rx)
        if s1[0] < s2[0]:
            return s1[0], s1[1]
        elif s1[0] > s2[0]:
            return s2[0], s2[1]
        else:
            return (s1[0], s2[1] + s1[1])

n, m = map(int, input().split())
st = SegmentTree(n)
x = list(map(int, input().split()))
for i in range(n):
    st.set_num(i, x[i])
for t in range(m):
    c, a, b = map(int, input().split())
    if c == 1:
        st.set_num(a, b)
    else:
        print(*st.get_sum(a, b))
    