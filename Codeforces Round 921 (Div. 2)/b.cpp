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
    ll x, n;
    cin >> x >> n;
    ll res = 1;
    vector<int> dels;
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            dels.push_back(i);
            dels.push_back(x / i);
        }
    }
    for (auto el : dels) {
        // cout << el << " ";
        if (x % el == 0 && x / el >= n && n * el <= x) {
            res = el;
        }
    }
    if (n == 1) {
        res = x;
    }
    cout << res << "\n";
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