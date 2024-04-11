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
    int n, k;
    cin >> n >> k;
    vector<int> res(n + 1, -1);
    int nowMin = 1;
    int nowMax = n;
    bool flag = true; // true - ставлю min, затем min + 1..., false - ставлю max, затем max - 1...
    for (int i = 1; i <= n; ++i) {
        if (res[i] != -1) {
            continue;
        }
        if (flag) {
            for (int now = i; now <= n; now += k) {
                res[now] = nowMin;
                nowMin++;
            }
        } else {
            for (int now = i; now <= n; now += k) {
                res[now] = nowMax;
                nowMax--;
            }
        }
        flag ^= true;
    }
    for (int i = 1; i <= n; ++i) {
        cout << res[i] << " ";
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