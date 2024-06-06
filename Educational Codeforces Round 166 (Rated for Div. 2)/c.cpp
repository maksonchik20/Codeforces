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
    int n, m;
    cin >> n >> m;
    int alls = m + n + 1;
    vector<ll> a(n + m + 1), b(n + m + 1);
    for (int i = 0; i < alls; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < alls; ++i) {
        cin >> b[i];
    }
    multiset<ll> getN, getM;
    ll sums = 0;
    for (int i = 1; i < alls; ++i) {
        if ((a[i] > b[i] && (int) getN.size() != n) || getM.size() == m) {
            sums += a[i];
            // cout << "a: " <<  i << " " << a[i] << endl;
            getN.insert(i);
            continue;
        }
        // cout << "b: " <<  i << " " << b[i] << endl;
        sums += b[i];
        getM.insert(i);
    }
    cout << sums << " ";
    for (int i = 0; i < alls - 1; ++i) {
        if (i + 1 < alls) {
            if (getN.find(i + 1) != getN.end()) {
                getN.erase(i + 1);
                sums -= a[i + 1];
            } else {
                getM.erase(i + 1);
                sums -= b[i + 1];
            }
        }
        if (a[i] > b[i]) {
            if (getN.size() < n) {
                sums += a[i];
                getN.insert(i);
                cout << sums << " ";
                continue;
            } else {
                if (getN.lower_bound(i) != getN.end()) {
                    ll use = *getN.lower_bound(i); // use > i
                    getN.erase(use);
                    sums -= a[use];
                    sums += b[use];
                    getN.insert(i);
                    getM.insert(use);
                    sums += a[i];
                    cout << sums << " ";
                    continue;
                }
            }
        }
            // cout << "tut " << i << endl;
            if (getM.size() < m) {
                sums += b[i];
                getM.insert(i);
            } else {
                if (getM.lower_bound(i) != getM.end()) {
                    ll use = *getM.lower_bound(i); // use > i
                    getM.erase(use);
                    sums += b[i];
                    sums -= b[use];
                    sums += a[use];
                    getN.insert(use);
                } else {
                    sums += a[i];
                    getN.insert(i);
                }
            }
        
        cout << sums << " ";
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