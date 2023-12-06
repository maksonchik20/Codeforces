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
ll n;
ll maxmax = -1;
ll indmax = 0;
bool check(ll mid) {
    bool flag = true;
    // cout << indmax << " " << maxmax << endl;
        for (int i = 0; i < n; ++i) {
            if (i == indmax) {
                continue;
            }
            if (i < indmax) {
                if (mid - (indmax - 1) < maxmax) {
                    flag = false;
                    break;
                }
            } else {
                // cout << mid - 
                if (mid - (n - indmax - 1) < maxmax) {
                    flag = false;
                    break;
                }
            }
        }
    return flag;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > maxmax) {
            maxmax = a[i];
            indmax = i;
        }
    }
    // cout << check(7) << endl;
    ll left = maxmax - 1;
    ll right = 1e17;
    while (right > left + 1) {
        ll mid = (left + right) / 2;
        // cout << left << " " << right << endl;
        if (check(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    cout << right << endl;
    return 0;
}