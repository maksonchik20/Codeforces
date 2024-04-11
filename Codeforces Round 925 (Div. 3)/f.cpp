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

bool dfs(int v, vector<int>& used, vector<vector<int>>& g) {
    used[v] = 1;
    for (auto to : g[v]) {
        if (used[to] == 1) {
            return true;
        }
        if (used[to] == 0) {
            if (dfs(to, used, g)) {
                return true;
            }
        }
    }
    used[v] = 2;
    return false;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n + 1);
    vector<int> used(n + 1, 0);
    bool good = true;
    map<pair<int, int>, bool> check;
    for (int i = 0; i < k; ++i) {
        vector<int> skr(n);
        for (int j = 0; j < n; ++j) {
            cin >> skr[j];
        }
        for (int j = 1; j < n - 1; ++j) {
            if (check[{skr[j], skr[j + 1]}] == true) {
                continue;
            }
            g[skr[j]].push_back(skr[j + 1]);
            check[{skr[j], skr[j + 1]}] = true;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) {
            bool cycle = dfs(i, used, g);
            if (cycle) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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