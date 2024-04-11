/* 
Code By maksonchik20
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ld EPS = 0.00000000001;
const ll INF = (ll) 1e18;
const ld PI = 3.141592653589793238462643383279502884;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n;
    cin >> n;
    vector<string> a(2);
    for (int i = 0; i < 2; ++i) {
        cin >> a[i];
    }
    string opt = "";
    int now = 0;
    int end = 0;
    for (int j = 0; j < n; ++j) {
        opt += a[now][j];
        if (now == 1) {
            continue;
        }
        if (j == n - 1 && now == 0) {
            now++;
            end = j;
            opt += a[now][j];
            continue;
        }
        if (a[now][j + 1] == '1' && a[now + 1][j] == '1') {
            continue;
        }
        if (a[now][j + 1] == '0') {
            continue;
        }
        if (a[now + 1][j + 1] == '0') {
            now++;
            end = j;
            cout << opt << endl;
            j--;
        }
    }
    cout << opt << "\n";
    int cnt = 0;
    cout << end << "\n";
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