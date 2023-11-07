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

string get_substr(string &s, int l, int r) {
    return s.substr(l, r - l + 1);
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int right = n - 1;
    int cnt = 0;
    vector<int> res;
    for (int i = 0; i <= right; ++i) {
        if (cnt > 300) {
            cout << -1 << "\n";
            return;
        }
        // cout << s << " right=" << right << " i=" << i << endl;
        if (s[i] == s[right]) {
            res.push_back((int) s.size() - i);
            // cout << "iiii===" << i << endl;
            // cout << s.substr(0, (int) s.size() - i) << " " << "01" << " " << s.substr((int) s.size() - i, (int) s.size()) << endl;
            // s = s.substr(0, i) + s.substr(i, right - i + 1) + "01";
            s = s.substr(0, s.size() - i) + "01" + get_substr(s, (int) s.size() - i, (int) s.size() - 1);
            // s = s.substr(0, (int) s.size() - i) + "01" + s.substr((int) s.size() - i, (int) s.size());
            right += 2;
            n += 2;
            i -= 1;
            cnt++;
            continue;
        } else {
            right--;
        }
    }
    if (cnt > 300) {
        cout << -1 << "\n";
        return;
    }
    cout << cnt << "\n";
    for (auto el : res) {
        cout << el << " ";
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