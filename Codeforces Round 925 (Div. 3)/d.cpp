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
    vector<ll> a(n);
    unordered_map<ll, ll> cnts;
    ll res = 0;
    ll mods = x * y;
    for (int i = 0; i < n; ++i) {
        ll num;
        cin >> num;
        num *= num;
        res += cnts[((-num) % mods + mods) % mods];
        if (cnts[((-num) % mods + mods) % mods] != 0) {
            cout << "Find: " << num << endl;
        }
        cnts[num % mods]++;
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