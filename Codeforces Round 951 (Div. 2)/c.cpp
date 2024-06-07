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
    vector<ll> k(n);
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
    }
    ll x = 1;
    for (auto el : k) {
        x *= el / __gcd(x, el);
    }
    // cout << x << endl;
    ll sums = 0;
    vector<ll> res(n);
    for (int i = 0; i < n; ++i) {
        sums += x / k[i];
        res[i] = x / k[i];
    }
    if (sums >= x) {
        cout << -1 << "\n";
        return;
    }
    for (auto el : res) {
        cout << el << " ";
    }
    cout << "\n";
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