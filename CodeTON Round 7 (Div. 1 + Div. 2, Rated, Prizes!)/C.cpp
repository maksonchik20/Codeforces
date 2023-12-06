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

int n, x;
vector<int> one, two;
vector<int> solve() {
    cin >> n >> x;
    int copy_x = x;
    vector<pair<int, int>> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        int num = one[i];
        a[i] = {num, i};
    }
    for (int i = 0; i < n; ++i) {
        // cin >> two[i];
        b[i] = two[i];
    }
    sort(b.begin(), b.end());
    sort(a.begin(), a.end());
    int now = 0;
    vector<int> ans;
    for (int i = n - 1; i >= 0; --i) {
        if (x == 0) {
            break;
        }
        ans.push_back(b[now]);
        now++;
        x--;
    }
    for (int i = n - 1; i >= now; --i) {
        ans.push_back(b[i]);
    }
    reverse(ans.begin(), ans.end());
    vector<int> ans2(n);
    for (int i = 0; i < n; ++i) {
        ans2[a[i].second] = ans[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i].first > ans2[i]) {
            cnt++;
        }
    }
    if (cnt == copy_x) {
        return ans2;
        // cout << "YES\n";
        // for (int i = 0; i < n; ++i) {
        //     cout << ans2[i] << " ";
        // }
        // cout << "\n";
    } else{
        return {};
        // cout << "NO\n";
    }
}

vector<int> slow() {
    int n, x;
    cin >> n >> x;
    int copy_x = x;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        int num = one[i];
        a[i] = num;
    }
    for (int i = 0; i < n; ++i) {
        // cin >> b[i];
        b[i] = two[i];
    }
    sort(b.begin(), b.end());
    do {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i]) {
                cnt++;
            }
        }
        if (cnt == x) {
            return b;
        }
        } while(std::next_permutation(b.begin(), b.end()));
    return {};
}

void inp() {
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        one.push_back(num);
    }
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        two.push_back(num);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    // cin >> t;
    while (t--) {
        vector<int> res = slow();
        vector<int> res2 = solve();
        if (res2.size() == 0 && res.size() != 0) {
            cout << "ERROR\n";
            for (auto it : one) {
                cout << it << " ";
            }
        }
        // if (res.size() == 0) {
        //     cout << "NO\n";
        // } else {
        //     cout << "YES\n";
        // }
        // for (int i = 0; i < (int) res.size(); ++i) {
        //     cout << res[i] << " ";
        // }
    }
    return 0;
}