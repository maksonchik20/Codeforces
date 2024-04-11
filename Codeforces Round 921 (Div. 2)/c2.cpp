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
    int n, k, m;
    cin >> n >> k >> m;
    string s, res, tmp;
    cin >> n >> k >> m >> tmp;
    for (auto el : tmp) {
        if (k > (int) el - 97) {
            s.push_back(el);
        }
    }
    if (s.empty()) {
        cout << "NO\n";
        for (int i = 0; i < n; ++i) {
            cout << 'a';
        }
        cout << "\n";
        return;
    }
    map<char, int> mp;
    int c = 0;
    for (auto el : s) {
        mp[el]++;
        if (mp.size() == k) {
            res.push_back(el);
            c++;
            mp.clear();
        }
    }
    if (c >= n) {
        cout << "YES\n";
        return;
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