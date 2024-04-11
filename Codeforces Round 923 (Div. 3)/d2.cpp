/* 
Code By maksonchik20
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll MOD = (ll) 1e9 + 7;
const ld EPS = 0.00000000001;
const ll INF = (ll) 1e18;
const ld PI = 3.141592653589793238462643383279502884;

struct Node {
    ll min;
    ll max;
    ll indMin;
    ll indMax;
    Node() {
        min = -1;
        max = -1;
        indMin = -1;
        indMax = -1;
    }
};

vector<Node> t;
vector<ll> a;
void build(int v, int l, int r) {
    if (l + 1 == r) {
        t[v].min = a[l];
        t[v].max = a[l];
        t[v].indMax = l;
        t[v].indMin = l;
        return;
    }
    int m = (l + r) / 2;
    build(2 * v + 1, l, m);
    build(2 * v + 2, m, r);
    t[v] = t[2 * v + 1];
    if (t[2 * v + 2].min < t[v].min) {
        t[v].min = t[2 * v + 2].min;
        t[v].indMin = t[2 * v + 2].indMin;
    }
    if (t[2 * v + 2].max > t[v].max) {
        t[v].max = t[2 * v + 2].max;
        t[v].indMax = t[2 * v + 2].indMax;
    }
}

tuple<ll, ll, ll, ll> get(int v, int l, int r, int ql, int qr) { // {min, max, indMin, indMax}
    if (r <= ql || l >= qr) {
        return {INF, -INF, -1, -1};
    }
    if (l >= ql && r <= qr) {
        return {t[v].min, t[v].max, t[v].indMin, t[v].indMax};
    }
    int m = (l + r) / 2;
    auto fi = get(2 * v + 1, l, m, ql, qr);
    auto se = get(2 * v + 2, m, r, ql, qr);
    int mnmn;
    int mnInd;
    int mxmx;
    int mxInd;
    if (get<0>(fi) <= get<0>(se)) {
        mnmn = get<0>(fi);
        mnInd = get<2>(fi);
    } else if (get<0>(fi) > get<0>(se)) {
        mnmn = get<0>(se);
        mnInd = get<2>(se);
    }
    if (get<1>(fi) >= get<1>(se)) {
        mxmx = get<1>(fi);
        mxInd = get<3>(fi);
    } else if (get<1>(fi) < get<1>(se)) {
        mxmx = get<1>(se);
        mxInd = get<3>(se);
    }
    return {mnmn, mxmx, mnInd, mxInd};
}


void solve() {
    int n;
    cin >> n;
    a.resize(n);
    t.resize(4 * n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    build(0, 0, n);
    // cout << "GOOD" << endl;
    // auto[min, max, indMin, indMax] = get(0, 0, n, 0, n);
    // cout << min << " " << max << " " << indMin << ' ' << indMax << endl;
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        auto [min, max, indMin, indMax] = get(0, 0, n, l - 1, r);
        // cout << min << " " << max << " " << indMin << " " << indMax << endl;
        if (min != max) {
            cout << indMin + 1 << ' ' << indMax + 1 << "\n";
        } else {
            cout << -1 << ' ' << -1 << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    // t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}