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
    cout << setprecision(10) << fixed;
    ll n, c;
    cin >> n >> c;
    vector<ld> arr(n);
    set<pair<ld, ll>> srt;
    cin >> arr[0];
    arr[0] /= c;
    for (int i = 1; i < n; ++i) {
        cin >> arr[i];
        arr[i] /= c;
        srt.insert({(i + 1) - arr[i], arr[i]});
    }
    ld now_a0 = arr[0];
    for (auto it = srt.begin(); it != srt.end(); ++it) {
        cout << (*it).first << " ";
        if (now_a0 >= (*it).first) {
            now_a0 += (*it).second;
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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