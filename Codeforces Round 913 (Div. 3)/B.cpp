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
    stack<pair<int, char>> lower, upper;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'b') {
            if (lower.size() > 0) {
                lower.pop();
            }
        } else if (s[i] == 'B') {
            if (upper.size() > 0) {
                upper.pop();
            }
        } else {
            if (islower(s[i]) == 0) {
                upper.push({i, s[i]});
            } else {
                lower.push({i, s[i]});
            }
        }
    }
    vector<pair<int, char>> result;
    while (!lower.empty()) {
        result.push_back(lower.top());
        lower.pop();
    }
    while (!upper.empty()) {
        result.push_back(upper.top());
        upper.pop();
    }
    sort(result.begin(), result.end());
    for (auto [l, r] : result) {
        cout << r;
    }
    cout << "\n";
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