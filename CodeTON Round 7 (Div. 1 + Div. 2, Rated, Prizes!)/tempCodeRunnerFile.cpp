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
    int n,x; 
    cin >> n >> x; 
    vector<pair<int, int>> a(n); 
    vector<int> b(n); 
    for(int i=0;i<n;i++) { 
        cin >> a[i].first;
        a[i].second = i;
    } 
    for(int i=0;i<n;i++) { 
        cin >> b[i]; 
    } 
    sort(a.rbegin(),a.rend()); 
    sort(b.begin(),b.end()); 
    vector<int> ans(n); 
    int ind=0; 
    int check=0; 
    for(int i = x - 1;i >= 0;i--) { 
        if(a[i].first > b[ind]) { 
            ans[a[i].second] = b[ind]; 
            ind++; 
        } 
        else { 
            cout << "NO" << endl; 
            return; 
        } 
    } 
    ind = n - 1; 
    for(int i=x;i<n;i++) { 
        if(a[i].first>b[ind]) { 
            cout << "NO" << "\n"; 
            return; 
        } 
        else { 
            ans[a[i].second]=b[ind]; 
            ind--; 
        } 
    } 
    cout << "YES" << "\n"; 
    for(int i = 0; i < (int) ans.size(); ++i) { 
        cout << ans[i] << " "; 
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