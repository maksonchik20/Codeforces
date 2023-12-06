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
    string s;
    cin >> s;
    char ch = s[0];
    int num = s[1] - '0';
    for (int i = 0; i < 8; ++i) {
        if ('a' + i == ch) {
            continue;
        }
        char ch2 = 'a' + i;
        cout << ch2 << num << "\n";
    }
    for (int i = 1; i <= 8; ++i) {
        if (i == num) {
            continue;
        }
        cout << ch << i << "\n";
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
