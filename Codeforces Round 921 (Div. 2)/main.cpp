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
vector<ll> mass;
vector<ll> nums;
void req(ll num) {
    if (num > 1000000000) {
        return;
    }
    nums.push_back(num);
    for (auto el : mass) {
        req(num * el);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll now = 1;
    for (int i = 2; i <= 12; ++i) {
        now *= i;
        mass.push_back(now);
    }
    for (auto el : mass) {
        cout << el << " ";
    }
    cout << endl;
    req(1);
    cout << nums.size() << endl;
    return 0;
}