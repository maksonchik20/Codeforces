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
    int cnt = 0;
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < 0) {
            cnt++;
        }
        if (a[i] == 0) {
            flag = true;
        }
    }
    if (flag) {
        cout << 0 << "\n";
        return;
    }
    if (cnt % 2 == 0) {
        cout << 1 << "\n";
        cout << 1 << " " << 0 << "\n";
    } else {
        cout << 0 << "\n";
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