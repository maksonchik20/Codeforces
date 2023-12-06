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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (a[0] != 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
    // for (int i = 1; i < n - 1; ++i) {
    //     for (int j = 0; j < n - 1; ++j) {
    //         // if (a[j] < a[j + 1]) {
    //         //     break;
    //         // }
    //         if (a[j] > a[j + 1] && a[j] > a[j - 1]) {
    //             swap(a[j], a[j + 1]);
    //         }
    //     }
    // }
    // for (int i = 0; i < n; ++i) {
    //     cout << a[i] << " ";
    //     // if (a[i] != i + 1) {
    //     //     cout << "NO\n";
    //     //     return;
    //     // }
    // }
    // cout << "YES\n";
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