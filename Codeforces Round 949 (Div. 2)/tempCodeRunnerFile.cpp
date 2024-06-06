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
    unordered_map<ll, bool> check;
    vector<ll> res = {1, 1};
    // check[1] = true;
    for (int i = 0; i < (n - 2) / 2; ++i) {
        res.push_back(res.back() + 1);
        res.push_back(res.back());
        // for (int j = 0; j < i; ++j) {
        //     if (!check[i * j]) {
        //         res.push_back(j);
        //         check[i * j] = true;
        //     }
        // }
    }
    if (n % 2 != 0) {
        res.push_back(res.back() + 1);
    }
    for (auto el : res) {
        cout << el << " ";
    }
    cout << '\n';
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