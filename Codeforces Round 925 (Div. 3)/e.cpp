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


int cnts(int num) {
    int now = 10;
    int cnt = 0;
    while (num % now == 0) {
        cnt++;
        now *= 10;
    }
    return cnt;
}

bool cmp(int fi, int se) {
    return cnts(fi) < cnts(se);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), cmp);
    int res = 0;
    int cnst = (n - 1) % 2;
    for (int i = n - 1; i >= 0; --i) {
        res += (int) log10(a[i]) + 1;
        if (i % 2 == cnst) {
            res -= cnts(a[i]);
        }
    }
    if (res <= m) {
        cout << "Anna\n";
    } else {
        cout << "Sasha\n";
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