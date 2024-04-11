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
    string s1, s2;
    cin >> n >> s1 >> s2;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s2[i] == '0' && s1[i] == '1') {
            cnt++;
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (s2[i] == '1' && s1[i] == '0') {
            if (cnt > 0) {
                cnt--;
                res++;
            } else {
                res++;
            }
        }
    }
    res += cnt;
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