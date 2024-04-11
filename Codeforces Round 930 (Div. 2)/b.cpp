/* 
Code By maksonchik20
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ld EPS = 0.00000000001;
const ll INF = (ll) 1e18;
const ld PI = 3.141592653589793238462643383279502884;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// vector<ll> mods = {(ll) 1e9 + 7, (ll) 1e9 + 9};
ll MOD = (ll) 1e9 + 7;
ll MOD2 = (ll) 1e9 + 9;
ll p = rnd() % 2000;
ll q = rnd() % 2000;
vector<ll> pw(200000 + 200), pq(200000 + 200);
ll get_hash_substr(int l, int r, vector<ll>& pref_hash, bool flag) { // [l...r) - 0 индексация
    if (flag == false) {
        return ((pref_hash[r] - pref_hash[l] * pw[r - l]) % MOD + MOD) % MOD;
    } else {
        return ((pref_hash[r] - pref_hash[l] * pq[r - l]) % MOD2 + MOD2) % MOD2;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<string> a(2);
    for (int i = 0; i < 2; ++i) {
        cin >> a[i];
    }
    string opt = "";
    int now = 0;
    for (int j = 0; j < n; ++j) {
        opt += a[now][j];
        if (now == 1) {
            continue;
        }
        if (j == n - 1 && now == 0) {
            now++;
            // cout << 1 << " " << j << endl;
            opt += a[now][j];
            continue;
        }
        if (a[now][j + 1] == '0') {
            continue;
        }
        if (a[now + 1][j] == '0') {
            now++;
            // cout << 2 << " " << j << endl;
            j--;
        }
        // if (a[now][j + 1] == '1' && a[now + 1][j] == '1') {
        //     continue;
        // }
    }
    if (opt.size() != n + 1) {
        ll a = 0;
        while (true) {
            ++a;
        }
    }
    vector<ll> hashes(n + 2), hashes2(n + 2, 0);
    hashes[0] = 0;
    for (int i = 1; i < n + 2; ++i) {
        hashes[i] = (hashes[i-1] * p + opt[i-1]) % MOD;
        hashes2[i] = (hashes2[i-1] * q + opt[i-1]) % MOD2;
    }
    vector<ll> hashtop(n + 1, 0), hashbottom(n + 1, 0), hashtop2(n + 1, 0), hashbottom2(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        hashtop[i] = (hashtop[i-1] * p + a[0][i-1]) % MOD;
        hashbottom[i] = (hashbottom[i-1] * p + a[1][i-1]) % MOD;
        hashtop2[i] = (hashtop2[i-1] * q + a[0][i-1]) % MOD2;
        hashbottom2[i] = (hashbottom2[i-1] * q + a[1][i-1]) % MOD2;
    }
    cout << opt << "\n";
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        // cout << "i=" << i << ". " << get_hash_substr(0, i + 1, hashes) << " " << get_hash_substr(0, i + 1, hashtop) << "..." << get_hash_substr(i, n, hashbottom) << " " << get_hash_substr(i + 1, n + 1, hashes) << endl;
        if (get_hash_substr(0, i + 1, hashes, 0) == get_hash_substr(0, i + 1, hashtop, 0) && get_hash_substr(i, n, hashbottom, 0) == get_hash_substr(i + 1, n + 1, hashes, 0)) {
            if (get_hash_substr(0, i + 1, hashes2, 1) == get_hash_substr(0, i + 1, hashtop2, 1) && get_hash_substr(i, n, hashbottom2, 1) == get_hash_substr(i + 1, n + 1, hashes2, 1)) {
                cnt++;
            }
        }
    }
    // if (cnt == 0) {
    //     ll a = 0;
    //     while (true) {
    //         ++a;
    //     }
    // }
    // cout << opt << endl;
    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << p << " " << (int) '0' * p + '1' << " " << (int) '1' << endl;
    pw[0] = 1;
    for (int i = 1; i < (int) pw.size(); ++i) {
        pw[i] = (pw[i - 1] * p) % MOD;
    }
    pq[0] = 1;
    for (int i = 1; i < (int) pq.size(); ++i) {
        pq[i] = (pq[i - 1] * q) % MOD2;
    }
    int t;
    // t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}