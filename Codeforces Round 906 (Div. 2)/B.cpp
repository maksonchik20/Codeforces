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
    string s, t;
    cin >> s >> t;
    bool okS = true;
    bool okT = true;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            okS = false;
            break;
        }
    }
    for (int i = 0; i < m - 1; ++i) {
        if (t[i] == t[i + 1]) {
            okT = false;
            break;
        }
    }
    if (okS) {
        cout << "YES\n";
        return;
    }
    if ((!okT) || (t[0] != t[m - 1])) {
        cout << "NO\n";
        return;
    }
    bool bad_0 = false, bad_1 = false;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1] && s[i] == '0') {
            bad_0 = true;
        }
        if (s[i] == s[i + 1] && s[i] == '1') {
            bad_1 = true;
        }
    }
    if (bad_0 && bad_1) {
        cout << "NO\n";
        return;
    }
    if (bad_0 && t[0] == '1') {
        cout << "YES\n";
        return;
    }
    if (bad_1 && t[0] == '0') {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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