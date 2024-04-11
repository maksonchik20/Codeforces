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

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<int, map<int, int>> cnts;
    for (int i = 0; i < n; ++i) {
        ++cnts[a[i] % x][a[i] % y];
    }
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        // cout << comp(a[i]) << endl;
        res += cnts[((x - (a[i] % x)) % x + x) % x][a[i] % y];
        if (((x - (a[i] % x)) % x + x) % x == a[i] % x) {
            res--;
        }
    }
    cout << res / 2 << '\n';
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