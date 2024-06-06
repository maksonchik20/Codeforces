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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll maxi = 1000000;
    ll res = 0;
    for (ll a = 1; a < maxi; ++a) {
        for (ll b = a + 1; b < maxi; ++b) {
            if (a * a + b * b > maxi * maxi) {
                break;
            }
            ll c = sqrtl(a * a + b * b);
            if (c * c == a * a + b * b) {
                res++;
            }
        }
        if (a % 1000 == 0) {
            cout << a << " " << res << endl;
        }
    }
    cout << res << endl;
    return 0;
}