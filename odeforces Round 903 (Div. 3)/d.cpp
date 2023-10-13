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
vector<int> lp(1000000);
vector<int> pr;

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> cnts;
    vector<int> dels;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        while (a != 1) {
            if (cnts[lp[a]] == 0) {
                dels.push_back(lp[a]);
            }
            cnts[lp[a]]++;
            a /= lp[a];
        }
    }
    bool ok = true;
    for (int i = 0; i < (int) dels.size(); ++i) {
        if (cnts[dels[i]] != 0 && cnts[dels[i]] % n != 0) {
            ok = false;
            break;
        }
    }
    if (ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i=2; i<=1000000; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=1000000; ++j)
            lp[i * pr[j]] = pr[j];
    }
    int t;
    // t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}