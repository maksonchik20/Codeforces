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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int cntFreeA = k / 2, cntFreeB = k / 2;
    vector<vector<int>> cnts(k + 1); // 1 - A. 2 - B
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] <= k) {
            cnts[a[i]].push_back(1);
        }
    }
    for (int i = 0; i < b.size(); ++i) {
        if (b[i] <= k) {
            cnts[b[i]].push_back(2);
        }
    }
    for (int i = 1; i <= k; ++i) {
        // cout << "i=" << i << endl;
        // cout << "\t";
        // for (auto el : cnts[i]) {
        //     cout << el << " ";
        // }
        // cout << endl;
        if ((int) cnts[i].size() == 1) {
            if (cnts[i][0] == 1) {
                cntFreeA--;
            } else {
                cntFreeB--;
            }
        } else if ((int) cnts[i].size() == 0) {
            cntFreeA = -1;
        }
    }
    // cout << cntFreeA << " " << cntFreeB << endl;
    if (cntFreeA < 0 || cntFreeB < 0) {
        cout << "NO\n";
        return;
    }
    int sum = cntFreeA + cntFreeB;
    for (int i = 1; i <= k; ++i) {
        if ((int) cnts[i].size() == 2) {
            sum--;
        }
    }
    if (sum >= 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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