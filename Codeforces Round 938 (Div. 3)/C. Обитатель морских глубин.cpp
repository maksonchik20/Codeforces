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
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    ll s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s += a[i];
    }
    if (s <= k) {
        cout << n << "\n";
        return;
    }
    int start = 0;
    int last = n - 1;
    bool isStart = true;
    int cnt = 0;
    while (true) {
        if (start <= last && k > 0) {
            ll fi = (k + 1) / 2;
            ll se = k / 2;
            if (a[start] == a[last] && a[start] <= fi && a[last] <= se) {
                cnt += 2;
                k -= a[start];
                k -= a[last];
                start++;
                last--;
            } else if (a[start] <= a[last] && a[start] <= fi) {
                cnt++;
                k -= a[start];
                k -= a[start];
                a[last] -= a[start];
                start++;
            } else if (a[start] >= a[last] && a[last] <= se) {
                cnt++;
                k -= a[last];
                k -= a[last];
                a[start] -= a[last];
                last--;
            } else {
                break;
            }
        } else {
            break;
        }
    }
    cout << cnt << "\n";
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