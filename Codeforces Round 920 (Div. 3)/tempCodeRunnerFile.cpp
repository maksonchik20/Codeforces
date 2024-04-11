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
    int h, w, xa, ya, xb, yb;
    cin >> h >> w >> xa >> ya >> xb >> yb;
    if (xb - xa <= 0) {
        cout << "Draw\n";
        return;
    } else if ((xb - xa) % 2 == 1) { // Draw or Alice
        if (ya == yb) {
            cout << "Alice\n";
            return;
        }
        if (ya < yb) {
            vector<pair<int, int>> pathBob, pathAlice;
            while (xb >= 1) {
                // cout << xb << " " << yb << endl;
                pathBob.push_back({xb, yb});
                if (yb + 1 <= w) {
                    yb++;
                }
                xb--;
            }
            while (xa <= h) {
                // cout << xb << " " << yb << endl;
                pathAlice.push_back({xa, ya});
                if (ya + 1 <= w) {
                    ya++;
                }
                xa++;
            }
            map<pair<int, int>, bool> check;
            int ind = 0;
            for (int i = 1; i < min(pathAlice.size(), pathBob.size()); ++i) {
                auto [x, y] = pathAlice[i];
                check[{x, y}] = true;
                auto [x2, y2] = pathBob[i];
                if (check[{x2, y2}] || (pathBob[i - 1].first == x && pathBob[i - 1].second == y)) {
                    cout << "Alice\n";
                    return;
                }
            }
            cout << "Draw\n";
        } else {
            vector<pair<int, int>> pathBob, pathAlice;
            while (xb >= 1) {
                // cout << xb << " " << yb << endl;
                pathBob.push_back({xb, yb});
                if (yb - 1 >= 1) {
                    yb--;
                }
                xb--;
            }
            while (xa <= h) {
                // cout << xb << " " << yb << endl;
                pathAlice.push_back({xa, ya});
                if (ya - 1 >= 0) {
                    ya--;
                }
                xa++;
            }
            map<pair<int, int>, bool> check;
            int ind = 0;
            for (int i = 0; i < min(pathAlice.size(), pathBob.size()); ++i) {
                auto [x, y] = pathAlice[i];
                // cout << x << " " << y << endl;
                check[{x, y}] = true;
                auto [x2, y2] = pathBob[i];
                if (check[{x2, y2}] == true || (pathBob[i - 1].first == x && pathBob[i - 1].second == y)) {
                    cout << "Alice\n";
                    return;
                }
            }
            cout << "Draw\n";
        }
    } else { // Draw or Bob
        if (ya == yb) {
            cout << "Bob\n";
            return;
        }
        if (ya < yb) {
            vector<pair<int, int>> pathBob, pathAlice;
            while (xb >= 1) {
                pathBob.push_back({xb, yb});
                if (yb - 1 >= 1) {
                    yb--;
                }
                xb--;
            }
            while (xa <= h) {
                pathAlice.push_back({xa, ya});
                if (ya - 1 >= 1) {
                    ya--;
                }
                xa++;
            }
            map<pair<int, int>, bool> check;
            int ind = 0;
            for (int i = 1; i < min(pathAlice.size(), pathBob.size()); ++i) {
                auto [x, y] = pathBob[i];
                check[{x, y}] = true;
                auto [x2, y2] = pathAlice[i];
                if (check[{x2, y2}] || (pathAlice[i - 1].first == x && pathAlice[i - 1].second == y)) {
                    cout << "Bob\n";
                    return;
                }
            }
            cout << "Draw\n";
        } else {
            vector<pair<int, int>> pathBob, pathAlice;
            while (xb >= 1) {
                // cout << xb << " " << yb << endl;
                pathBob.push_back({xb, yb});
                if (yb + 1 <= w) {
                    yb++;
                }
                xb--;
            }
            while (xa <= h) {
                // cout << xb << " " << yb << endl;
                pathAlice.push_back({xa, ya});
                if (ya + 1 <= w) {
                    ya--;
                }
                xa++;
            }
            map<pair<int, int>, bool> check;
            int ind = 0;
            for (int i = 0; i < min(pathAlice.size(), pathBob.size()); ++i) {
                auto [x, y] = pathBob[i];
                // cout << x << " " << y << endl;
                check[{x, y}] = true;
                auto [x2, y2] = pathAlice[i];
                if (check[{x2, y2}] == true || (pathAlice[i - 1].first == x && pathAlice[i - 1].second == y)) {
                    cout << "Bob\n";
                    return;
                }
            }
            cout << "Draw\n";
        }
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