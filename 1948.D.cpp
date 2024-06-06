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

bool check(string& s, int i, int gr) {
    if (s[i] == '?' || s[i + gr] == '?' || s[i] == s[i + gr]) {
        return true;
    }
    return false;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = n - n % 2; i >= 2; i -= 2) {
        int cnt = 0;
        int gr = i / 2;
        bool good = false;
        int l = 0;
        int r = l + i - 1;
        for (int i = l; i < gr; ++i) {
            cnt += check(s, i, gr);
        }
        if (cnt == gr) {
            good = true;
        }
        while (r + 1 < n) {
            cnt -= check(s, l, gr);
            cnt += check(s, l + gr, gr);
            l++;
            r++;
            if (cnt == gr) {
                good = true;
            }
        }
        if (good) {
            cout << 2 * gr << "\n";
            return;
        }
    }
    cout << 0 << "\n";
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