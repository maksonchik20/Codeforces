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

ll ask(ll x, ll y) {
    cout << "? " << x << " " << y << endl;
    ll res;
    cin >> res;
    return res;
}

ll answer(ll x, ll y) {
    cout << "! " << x << " " << y << endl;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    ll a = ask(1, 1);
    ll b = ask(m, 1);
    ll c = ask(1, n);
    ll d = ask(m, n);
    vector<pair<pair<int, int>, pair<int, int>>> predict;
    // a, b
    ll x = (a - b + n + 1) / 2;
    ll y = a - x + 2;
    if ((a - b + n + 1) % 2 == 0 && x > 0 && y > 0) {
        predict.push_back({x, y});
    }
    // a, c
    
    // b, d
    // c, d
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