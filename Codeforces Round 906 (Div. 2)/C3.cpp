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
    if (n % 2 == 1) {
        cout << -1 << "\n";
        return;
    }
    deque<char> a;
    for (int i = 0; i < n; ++i) {
        a.push_back(s[i]);
    }
    int i = -1;
    int r = n - 1;
    int cnt = 0;
    vector<int> res;
    while (cnt <= 300) {
        if (a.size() < 2) {
            cout << cnt << "\n";
            for (auto el : res) {
                cout << el << " ";
            }
            cout << "\n";
            return;
        }
        if (a.front() != a.back()) {
            ++i;
            --r;
            a.pop_back();
            a.pop_front();
        } else if (a.front() == 1) {
            a.push_front('1');
            a.push_front('0');
            r += 2;
            res.push_back(i + 1);
            cnt++;
        } else {
            a.push_back('0');
            a.push_back('1');
            res.push_back(r + 1);
            r += 2;
            cnt++;
        }
    }
    if (cnt >= 300) {
        cout << -1 << "\n";
        return;
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