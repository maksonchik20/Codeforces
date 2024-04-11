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

int n, m;
vector<int> a, b;
ll ans;
ll check(int mid) {
    ll res = 0;
    for (int i = 0; i < mid; ++i) {
        // cout << a[i] << " " << b[m - 1 - i] << endl;
        res += abs(a[i] - b[m - 1 - i]);
    }
    for (int i = 0; i < n - mid; ++i) {
        // cout << a[mid + i] << " " << b[m - 1 - i] << endl;
        res += abs(a[mid + i] - b[i]);
    }
    ans = max(ans, res);
    return res;
}
void solve() {
    cin >> n >> m;
    a.assign(n, 0);
    b.assign(m, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    // ll res = -INF;
    // for (int i = 0; i <= n; ++i) {
    //     // cout << "i=" << i << " check=" << check(i) << endl;
    //     res = max(res, check(i));
    // // cout << check(n) << endl;
    // }
    // cout << res << "\n";
    int left = -1;
    int right = n + 1;
    ans = -INF;
    while (left + 1 != right) {
        int mid = (left + right) / 2;
        if (mid >= 1 && check(mid) < check(mid - 1)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    cout << check(left) << "\n";
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