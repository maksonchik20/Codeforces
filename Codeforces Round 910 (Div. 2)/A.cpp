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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'B') {
            cnt++;
        }
    }
    if (cnt == k) {
        cout << 0 << "\n";
    } else if (cnt < k) {
        int cnt2 = 0;
        for (int i = 0; i < n; ++i) {
            if (cnt2 + cnt == k) {
                cout << 1 << "\n";
                cout << i + 1 << " " << "B\n";
                break;
            }
            if (s[i] == 'A') {
                cnt2++;
            }
            if (cnt2 + cnt == k) {
                cout << 1 << "\n";
                cout << i + 1 << " " << "B\n";
                break;
            }
        }
    } else {
        int cnt2 = 0;
        for (int i = 0; i < n; ++i) {
            if (cnt2 + cnt == k) {
                cout << 1 << "\n";
                cout << i + 1 << " " << "A\n";
                break;
            }
            if (s[i] == 'B') {
                cnt2++;
            }
            if (cnt - cnt2 == k) {
                cout << 1 << "\n";
                cout << i + 1 << " " << "A\n";
                break;
            }
        }
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
