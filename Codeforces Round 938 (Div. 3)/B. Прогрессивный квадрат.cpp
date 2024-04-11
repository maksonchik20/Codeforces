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
    int n, c, d;
    cin >> n >> c >> d;
    vector<vector<int>> a(n, vector<int>(n));
    vector<int> b(n * n);
    for (int i = 0; i < n * n; ++i) {
        cin >> b[i];
    }
    int mins = *min_element(b.begin(), b.end());
    a[0][0] = mins;
    unordered_map<int, int> cnts;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = mins + i * c + j * d;
            cnts[a[i][j]]++;
        }
    }
    for (int i = 0; i < n * n; ++i) {
        cnts[b[i]]--;
        if (cnts[b[i]] < 0) {
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