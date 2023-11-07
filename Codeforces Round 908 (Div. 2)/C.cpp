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
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    ll cnt = n - 1;
    ll flag = true;
    multiset<ll> st;
    for (int i = 0; i < k; ++i) {
        if (st.count(cnt) != 0) {
            break;
        }
        if (arr[cnt] > n) {
            flag = false;
            break;
        }
        st.insert(cnt);
        cnt = (n + cnt - arr[cnt]);
        cnt %= n;
    }
    if (flag) {
        cout << "YES";
    } else {
        cout << "NO";
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
