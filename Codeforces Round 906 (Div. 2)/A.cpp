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
    vector<int> arr(n);
    unordered_map<int, bool> cnts;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (!cnts[arr[i]]) {
            cnt++;
            cnts[arr[i]] = true;
        }
    }
    if (n == 2 || cnt == 1) {
        cout << "YES\n";
        return;
    }
    // cout << cnt << endl;
    if (cnt != 2 && cnt != 1) {
        cout << "NO\n";
        return;
    }
    int fi = 0, se = 0;
    sort(arr.begin(), arr.end());
    int search_fi = arr[0];
    int search_se = arr[n - 1];
    for (int i = 0; i < n; ++i) {
        if (arr[i] == search_fi) {
            fi++;
        } else {
            se++;
        }
    }
    if (fi == se || fi + 1 == se || fi - 1 == se) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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