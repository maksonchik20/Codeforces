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
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool flag0 = true, flag1 = true;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            flag0 = false;
        }
        if (s[i] == '0') {
            flag1 = false;
        }
    }
    if ((!flag0 && !flag1) || (flag0)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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