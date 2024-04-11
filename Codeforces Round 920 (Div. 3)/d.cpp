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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll cnt = 0;
    ll left = 0;
    ll right = n - 1;
    ll left2 = 0;
    ll right2 = m - 1;
    while (left <= right) {
        if (abs(a[left] - b[right2]) > abs(a[right] - b[left2])) {
            cnt += abs(a[left] - b[right2]);
            left++;
            right2--;
        } else {
            cnt += abs(a[right] - b[left2]);
            right--;
            left2++;
        }
    }
    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    // t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}