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
    for (int i = 1; i <= 26; ++i) {
        for (int j = 1; j <= 26; ++j) {
            for (int k = 1; k <= 26; ++k) {
                if (i + j + k == n) {
                    char ch1 = (char) 'a' + (i - 1);
                    char ch2 = (char) 'a' + (j - 1);
                    char ch3 = (char) 'a' + (k - 1);
                    // string s = ch1 + ch2 + ch3;
                    cout << ch1 << ch2 << ch3 << "\n";
                    return;
                }
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