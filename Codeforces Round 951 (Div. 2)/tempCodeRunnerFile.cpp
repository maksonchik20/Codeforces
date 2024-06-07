/* 
Code By maksonchik20
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
const ll MOD = (ll) 1e9 + 7;
const ld EPS = 0.00000000001;
const ll INF = (ll) 1e18;
const ld PI = 3.141592653589793238462643383279502884;

ull gethash_mas(int l, int r, vector<ll>& hash_mas, vector<ll>& p) {
    if (l > r) {
        return 0;
    }
    return (hash_mas[r] - ((hash_mas[l - 1] * p[r - l + 1]) % MOD) + MOD) % MOD;
}

ull getrev_hash_mas(int l, int r, vector<ll>& rev_hash_mas, vector<ll>& p) {
    return (rev_hash_mas[l] - ((rev_hash_mas[r + 1] * p[r - l + 1]) % MOD) + MOD) % MOD;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = "#" + s;
    vector<ll> hash_mas(n + 1), rev_hash_mas(n + 2), p(n + 1);
    ll h1 = 0, h2 = 0;
    ll q = 17;
    for (int i = 1; i <= n; ++i) {
        hash_mas[i] = (q * hash_mas[i - 1] + (s[i] - '0')) % MOD;
    }
    for (int i = n; i >= 1; --i) {
        rev_hash_mas[i] = (q * rev_hash_mas[i + 1] + (s[i] - '0')) % MOD;
    }
    p[0] = 1;
    for (int i = 1; i <= n; ++i) {
        p[i] = (q * p[i - 1]) % MOD;
    }
    for (int i = 0; i < n; ++i) {
        int pl = ((i / k) & 1);
        h1 = (h1 * q + pl + MOD) % MOD;
    }
    for (int i = 0; i < n; ++i) {
        int pl = (!((i / k) & 1));
        h2 = (h2 * q + pl + MOD) % MOD;
    }
    for (int i = 1; i <= n; ++i) {
        ll h = ((gethash_mas(i + 1, n, hash_mas, p) * p[i] + MOD) % MOD + getrev_hash_mas(1, i, rev_hash_mas, p) + MOD) % MOD;
        if (h == h1 || h == h2) {
            cout << i << "\n";
            return;
        }
    }
    cout << -1 << "\n";
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