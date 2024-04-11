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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int pref = 0;
    int i;
    for (i = 1; i < n; ++i) {
        if (a[i] != a[0]) {
            break;
        }
    }
    pref = i;
    int suff = 0;
    for (i = n - 2; i >= 0; --i) {
        if (a[i] != a[n - 1]) {
            break;
        }
    }
    if (i == -1) {
        cout << 0 << "\n";
        return;
    }
    suff = i;
    // cout << suff << " " << pref << endl;
    if (a[0] != a[n - 1]) {
        cout << min(suff + 1, n - pref) << "\n";
    } else {
        cout << suff - pref + 1 << "\n";
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