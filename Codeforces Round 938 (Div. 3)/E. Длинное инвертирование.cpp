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
    string s;
    cin >> s;
    for (int i = n; i >= 1; --i) {
        vector<int> dels(n + 1, 0);
        int cnt = 0;
        bool ok = true;
        for (int j = 0; j < n; ++j) {
            cnt -= dels[j];
            if (j + i <= n) { // могу начать инверсию
                if (cnt % 2 == 0) {
                    if (s[j] == '0') {
                        cnt++;
                        dels[j + i]++;
                    }
                } else {
                    if (s[j] == '1') {
                        cnt++;
                        dels[j + i]++;
                    }
                }
            } else { // проверяю что все 1
                if (cnt % 2 == 0) {
                    if (s[j] == '0') {
                        ok = false;
                    }
                } else {
                    if (s[j] == '1') {
                        ok = false;
                    }
                }
            }
        }
        if (ok) {
            cout << i << "\n";
            return;
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