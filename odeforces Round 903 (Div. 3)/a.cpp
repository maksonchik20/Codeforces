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
    int n, m;
    cin >> n >> m;
    string x, s;
    cin >> x >> s;
    int cnt = 0;
    while (n < m) {
        x = x + x;
        n *= 2;
        cnt++;
    }
    // cout << x << " " << s << endl;
    for (int i = 0; i < n - m + 1; ++i) {
        bool ok = true;
        for (int j = 0; j < m; ++j) {
            if (s[j] != x[i + j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << cnt << "\n";
            return;
        }
    }
    x = x + x;
    n *= 2;
    cnt++;
    for (int i = 0; i < n - m + 1; ++i) {
        bool ok = true;
        for (int j = 0; j < m; ++j) {
            if (s[j] != x[i + j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << cnt << "\n";
            return;
        }
    }
    cout << "-1\n";
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