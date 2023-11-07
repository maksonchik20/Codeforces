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
    bool flag1 = false, flag2 = false;
    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= n; ++y) {
            int win_a = 0;
            int win_b = 0;
            int now_set_a = 0;
            int now_set_b = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] == 'A') {
                    now_set_a++;
                } else {
                    now_set_b++;
                }
                if (now_set_a == y) {
                    win_a++;
                    now_set_a = 0;
                    now_set_b = 0;
                } else if (now_set_b == y) {
                    win_b++;
                    now_set_a = 0;
                    now_set_b = 0;
                }
                if (win_a == x && i != n - 1) {
                    break;
                }
                if (win_b == x && i != n - 1) {
                    break;
                }
                if (win_a == x && i == n - 1 && win_b < x && now_set_a == 0 && now_set_b == 0) {
                    flag1 = true;
                    // cout << x << " " << y << " " << win_a << " " << win_b << endl;
                } else if (win_b == x && i == n - 1 && win_a < x && now_set_a == 0 && now_set_b == 0) {
                    flag2 = true;
                    // cout << x << " " << y << " " << win_a << " " << win_b << endl;
                }
            }
            // cout << win_a << " " << win_b << endl;
        }
    }
    // cout << flag1 << " " << flag2 << endl;
    if (flag1 == flag2) {
        cout << "?\n";
    } else if (flag1 == true) {
        cout << "A\n";
    } else {
        cout << "B\n";
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