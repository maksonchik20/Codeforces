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
    ll n, f, a, b;
    cin >> n >> f >> a >> b;
    vector<ll> t(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }
    vector<ll> dp(n + 1, -INF);
    dp[0] = f;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] - min(b, (t[i] - t[i - 1]) * a);
        if (dp[i] <= 0) {
            cout << "NO\n";
            return;
        }
        // cout << dp[i - 1] << " " << b << " " << t[i] << " " << t[i - 1] << " stalo: " << dp[i] << endl;
    }
    cout << "YES\n";
    return;
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