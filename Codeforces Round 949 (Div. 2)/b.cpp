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

ll MSBPosition(ll N)
{
    ll msb_p = -1;
    while (N) {
        N = N >> 1;
        msb_p++;
    }
    return msb_p;
}
ll findBitwiseOR(ll L,
                            ll R)
{
    ll res = 0;
 
    ll msb_p1 = MSBPosition(L);
 
    ll msb_p2 = MSBPosition(R);
 
    while (msb_p1 == msb_p2) {
        ll res_val = (1 << msb_p1);
 
        res += res_val;
 
        L -= res_val;
        R -= res_val;
 
        msb_p1 = MSBPosition(L);
        msb_p2 = MSBPosition(R);
    }
    msb_p1 = max(msb_p1, msb_p2);
 
    for (ll i = msb_p1; i >= 0; i--) {
        ll res_val = (1 << i);
        res += res_val;
    }
    return res;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    if (m == 0) {
        cout << n << "\n";
        return;
    }
    cout << findBitwiseOR(max(n - m, (ll)0), n + m) << "\n";   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    // t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}