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
    ll a, b, c;
    cin >> a >> b >> c;
    ll get_min = min({a, b, c});
    ll get_max = max({a, b, c});
    ll z = a + b + c - get_min - get_max;
    if (get_min == z and get_max == 4 * get_min) {
        cout << "YES\n";
    } else if ((z == 2 * get_min || z == get_min) && (get_max == get_min || get_max == 2 * get_min || get_max == 3 * get_min)) {
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