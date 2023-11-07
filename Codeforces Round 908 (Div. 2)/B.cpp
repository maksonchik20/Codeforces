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
    vector<int> arr(n);
    map<int, vector<int>> m;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        m[arr[i]].push_back(i);
    }
    vector<int> ans(n);
    int cnt = 0;
    for (auto&& i : m) {
        int sz = i.second.size();
        int fi = i.second[0];
        if (sz >= 2) {
            if (cnt == 0) {
                ans[fi] = 1;
                for (int j = 1; j < (int) sz; ++j) {
                    ans[i.second[j]] = 3;
                }
            } else {
                ans[fi] = 1;
                for (int j = 1; j < (int) sz; ++j) {
                    ans[i.second[j]] = 2;
                }
            }
            cnt++;
        } else {
            ans[fi] = 1;
        }
    }
    if (cnt <= 1) {
        cout << "-1";
    } else {
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
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
