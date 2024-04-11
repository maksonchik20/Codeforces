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

ll req(ll n) {
    if (n == 0) {
        return 0;
    }
    ll minres = 100000;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 5; ++k) {
                for (int p = 0; p < 5; ++p) {
                    for (int lst = 0; lst < 5; ++lst) {
                        if (15 * i + 10 * j + 6 * k + 3 * p + 1 * lst == n) {
                            minres = min(minres, (ll) i + j + k + p + lst);
                        } 
                    }
                }
            }
        }
    }
    return minres;
}

void solve() {
    // 15 10 6 3 1
    ll n;
    cin >> n;
    ll copyn1 = n, copyn2 = n;
    if (n <= 40) {
        ll minres = 1000;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                for (int k = 0; k < 5; ++k) {
                    for (int p = 0; p < 5; ++p) {
                        for (int lst = 0; lst < 5; ++lst) {
                            if (15 * i + 10 * j + 6 * k + 3 * p + 1 * lst == n) {
                                minres = min(minres, (ll) i + j + k + p + lst);
                            } 
                        }
                    }
                }
            }
        }
        cout << minres << "\n";
        return;
    }
    ll res = INF;
    ll cnt1 = n / 15 + req(n % 15);
    ll cnt2 = n / 15 - 1 + req(n % 15 + 15);
    ll cnt3 = INF;
    if (n % 15 + 30 <= n) {
        cnt3 = n / 15 - 2 + req(n % 15 + 30);
    }
    cout << cnt1 << " " << cnt2 << " " << cnt3 << endl;
    res = min({cnt1, cnt2, cnt3});
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