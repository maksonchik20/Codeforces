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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + m + 1), b(n + m + 1);
    for (int i = 0; i < n + m + 1; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n + m + 1; ++i) {
        cin >> b[i];
    }
    vector<ll> ac = a, bc = b;
    int ni = 0, mi = 0;
    int nextni, nextmi;
    n += 1;
    for (int i = 0; i < n + m + 1; ++i) {
        if (ni < n && (a[i] > b[i] || mi >= m)) {
            ni += 1;
            if (ni == n) {
                nextni = i;
            }
        } else {
            mi += 1;
        }
    }
    n -= 1;
    ni = 0;
    mi = 0;
    m++;
    for (int i = 0; i < n + m + 1; ++i) {
        if (ni < n && (a[i] > b[i] || mi >= m)) {
            ni += 1;
        } else {
            mi++;
            if (mi == m) {
                nextmi = i;
            }
        }
    }
    m--;
    ll ans = 0;
    ni = 0;
    mi = 0;
    for (int i = 0; i < n + m; ++i) {
        if (ni < n && (a[i] > b[i] || mi >= m)) {
            ni++;
            ans += a[i];
            bc[i] = 0;
        } else {
            mi++;
            ans += b[i];
            ac[i] = 0;
        }
    }
    for (int i = 0; i < n + m; ++i) {
        ll ansc = ans;
        if (ac[i] != 0) {
            ansc -= a[i];
            if (nextni == n + m) {
                ansc += a[nextni];
            } else {
                ansc -= b[nextni];
                ansc += a[nextni];
                ansc += b[b.size() - 1];
            }
        } else {
            ansc -= b[i];
            if (nextmi == n + m) {
                ansc += b[nextmi];
            } else {
                ansc -= a[nextmi];
                ansc += b[nextmi];
                ansc += a[a.size() - 1];
            }
        }
        cout << ansc << " ";
    }
    cout << ans << "\n";
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