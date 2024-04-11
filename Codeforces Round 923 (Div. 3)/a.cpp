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
    int fi = -1;
    int se = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'B') {
            if (fi == -1) {
                fi = i;
            } else {
                se = i;
            }
        }
    }
    if (se == -1) {
        cout << 1 << "\n";
    } else {
        cout << se - fi + 1 << "\n";
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