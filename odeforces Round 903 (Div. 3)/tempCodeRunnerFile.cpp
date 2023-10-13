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

vector<vector<char>> turn90(int n, vector<vector<char>>& matrix) {
 int i,j;
 vector<vector<char>> b(n, vector<char>(n));
 for (i=0; i<n; i++)
 for (j=0; j<n; j++) {
    b[j][n-i-1]=matrix[i][j];
 }
 return b;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> matrix;
    matrix.resize(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    vector<vector<char>> b = turn90(n, matrix);
    vector<vector<char>> c = turn90(n, b);
    vector<vector<char>> d = turn90(n, c);
    ll res = 0;
    for (int i = 0;i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char get_max = max({matrix[i][j], b[i][j], c[i][j], d[i][j]});
            // cout << i << ' ' << j << " " <<  get_max << " " << abs((int) b[i][j] - get_max) << " " <<  << endl;
            res += abs((int) matrix[i][j] - get_max);
            res += abs((int) b[i][j] - get_max);
            res += abs((int) c[i][j] - get_max);
            res += abs((int) d[i][j] - get_max);
        }
    }
    // cout << res << endl;
    cout << res / 4 << "\n";
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