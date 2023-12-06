/* 
Code By maksonchik20
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
#define fi first
#define se second
const ll MOD = (ll) 1e9 + 7;
const ld EPS = 0.00000000001;
const ll INF = (ll) 1e18;
const ld PI = 3.141592653589793238462643383279502884;
ll n;
vector<pair<ll, ll>> otr;
bool check(int m) {
    ll mn = 0, mx = 0;
    for (int i = 0; i < n; ++i) {
        ll x = otr[i].fi;
        ll y = otr[i].se;
        cout << i << " " << x << " " << y << endl;
        // cout << x << " " << y << endl;
        mn = max(mn, x);
        mx = min(y, mx);
        if (mn > mx) {
            return false;
        }
        mn = max(mn - m, (ll) 0);
    }
    return true;
}


void solve() {
    cin >> n;
    otr.resize(n);
    for (int i = 0; i < n; ++i) {
        ll l, r;
        cin >> l >> r;
        otr[i] = {l, r};
    }
    cout << check(7) << endl;
    // ll left = -1, right = 5000000000;
    // while (left + 1 != right) {
    //     int mid = (left + right) / 2;
    //     if (check(mid)) {
    //         right = mid;
    //     } else {
    //         left = mid;
    //     }
    // }
    // cout << right << "\n";
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