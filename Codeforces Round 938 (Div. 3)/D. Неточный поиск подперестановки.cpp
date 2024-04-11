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
    for (auto& it : a) {
        cin >> it;
    }
    for (auto& it : b) {
        cin >> it;
    }
    unordered_map<int, int> cnt;
    unordered_map<int, int> startCnt;
    for (auto el : b) {
        cnt[el]++;
        startCnt[el]++;
    }
    unordered_map<int, int> cnta;
    int nowf = 0;
    for (int i = 0; i < m; ++i) {
        cnta[a[i]]++;
        if (cnt[a[i]] != 0) {
            nowf++;
            cnt[a[i]]--;
        }
    }
    int ans = 0;
    if (nowf >= k) {
        ans++;
    }
    for (int i = m; i < n; ++i) {
        // del i - m
        int before = min(startCnt[a[i - m]], cnta[a[i - m]]);
        int after = min(startCnt[a[i - m]], cnta[a[i - m]] - 1);
        cnta[a[i - m]]--;
        nowf -= before - after;
        // add i
        before = min(startCnt[a[i]], cnta[a[i]]);
        after = min(startCnt[a[i]], cnta[a[i]] + 1);
        nowf += after - before;
        cnta[a[i]]++;
        if (nowf >= k) {
            ans++;
        }
    }
    cout << ans << "\n";
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