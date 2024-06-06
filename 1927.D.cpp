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

const int MAXN = (int) 3e5;
int p[MAXN];
int sz[MAXN];

void makeSet(int v) {
    sz[v] = 1;
    p[v] = v;
}

int getSet(int v) {
    if (p[v] == v) {
        return v;
    }
    return p[v] = getSet(p[v]);
}

vector<vector<int>> g;
vector<bool> used;
void dfs(int v) {

}

bool unite(int a, int b) {
    a = getSet(a);
    b = getSet(b);
    if (a == b) {
        return false;
    }
    if (sz[a] > sz[b]) {
        swap(a, b);
    }
    p[b] = a;
    sz[a] += sz[b];
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    used.resize(n + 1);
    vector<array<int, 3>> edge(m);
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        edge[i] = {w, a, b};
    }
    sort(edge.rbegin(), edge.rend());
    int optw = (int) 1e7;
    for (int i = 0; i < m; ++i) {
        if (getSet(edge[i][1]) == getSet(edge[i][2])) {
            optw = edge[i][0];
        }
        unite(edge[i][1], edge[i][2]);
    }
    cout << optw << "\n";
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