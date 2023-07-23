n, h = map(int, input().split())
mh = list(map(int, input().split()))
mw = list(map(int, input().split()))
data = list(zip(mh, mw))
data.sort(key=lambda x: x[0])
pref_sum_w = [0] * n
pref_sum_w[0] = data[0][1]
for i in range(1, n):
    pref_sum_w[i] = pref_sum_w[i-1] + data[i][1]

class SegmentTreeMax:
    def __init__(self, a):
        self.a = a
        self.tree = [0] * 4 * len(a)
        self.build(0, 0, len(a))

    def build(self, v, l, r):
        if l + 1 == r:
            self.tree[v] = self.a[l]
            return
        m = (l + r) // 2
        self.build(2*v+1, l, m)
        self.build(2*v+2, m, r)
        self.tree[v] = max(self.tree[2*v+1], self.tree[2*v+2])
    
    def get(self, v, l, r, ql, qr):
        if r <= ql or l >= qr:
            return 0
        if ql <= l and qr >= r:
            return self.tree[v]
        m = (l + r) // 2
        return max(self.get(2*v+1, l, m, ql, qr), self.get(2*v+2, m, r, ql, qr))

razn_h = [0] * n
for i in range(1, n):
    razn_h[i] = abs(data[i][0] - data[i-1][0])
segTree = SegmentTreeMax(razn_h)
right = 0
result = 10**9 + 5
for i in range(n):
    if i > 0:
        while right < n and pref_sum_w[right] - pref_sum_w[i-1] < h:
            right += 1
    else:
        while right < n and pref_sum_w[right] < h:
            right += 1
    if right == n:
        break
    result = min(result, segTree.get(0, 0, len(razn_h), i + 1, right + 1))
print(result)