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
    map<int, vector<char>> cnt;
    for (int i = 25; i >= 0; --i) {
        cnt[0].push_back('a' + i);
    }
    string res = "";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        char add = cnt[a[i]].back();
        cnt[a[i]].pop_back();
        cnt[a[i] + 1].push_back(add);
        res.push_back(add);
    }
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