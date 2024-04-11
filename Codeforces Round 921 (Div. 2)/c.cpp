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
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    string res = "";
    vector<bool> used(k, false);
    int cnt2 = 0;
    int cnt = k;
    for (auto el : s) {
        if (!used[el - 'a']) {
            used[el - 'a'] = true;
            cnt--;
        }
        if (cnt == 0) {
            res.push_back(el);
            used.assign(k, false);
            cnt = k;
            cnt2++;
        }
    }
    if (cnt2 >= n) {
        cout << "YES\n";
        return;
    } else {
        cout << "NO\n";
        if (cnt == k) {
            while (res.size() < n) {
                res.push_back(s[(int) s.size() - 1]);
            }
            cout << res <<"\n";
            return;
        }
        for (int i = 0; i < k; ++i) {
            if (used[i] == false) {
                while (res.size() < n) {
                    res.push_back('a' + i);
                }
                break;
            }
        }
        cout << res << "\n";
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