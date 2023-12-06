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

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> otr(n);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        otr[i] = {l, r};
    }
    vector<pair<int, int>> dp(n); // min k, max x
    dp[0] = {otr[0].fi, otr[0].fi};
    for (int i = 1; i < n; ++i) {
        if (otr[i].se <= otr[i - 1].fi) { // мой отрезок слева. прыгаем с otr[i-1].fi
            dp[i] = {min(dp[i - 1].fi, otr[i - 1].fi - otr[i].se), otr[i].se};
        } else {

        }
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