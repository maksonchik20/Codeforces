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
    string s;
    cin >> s;
    vector<int> cnts(26, 0);
    for (int i = 0; i < n; ++i) {
        cnts[s[i] - 'a']++;
    }
    multiset<int> cnt;
    for (int i = 0; i < 26; ++i) {
        if (cnts[i] != 0) {
            cnt.insert(-cnts[i]);
        }
    }
    while (cnt.size() > 1) {
        int fi = abs(*cnt.begin());
        int se = abs(*(next(cnt.begin())));
        // cout << fi << " " << se << endl;
        if (true) {
            auto it = cnt.find(-fi);
            cnt.erase(it);
            auto it2 = cnt.find(-se);
            cnt.erase(it2);
            if (-fi + 1 != 0) {
                cnt.insert(-fi+1);
            }
            if (-se + 1 != 0) {
                cnt.insert(-se+1);
            }
            continue;
        }
        // } else {
        //     auto it = cnt.find(-se);
        //     cnt.erase(it);
        //     auto it2 = cnt.find(-fi);
        //     cnt.erase(it2);
        //     cnt.insert(-fi+se);
        // }
    }
    if (cnt.size() == 1) {
        cout << -*cnt.begin() << "\n";
    } else {
        cout << 0 << "\n";
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