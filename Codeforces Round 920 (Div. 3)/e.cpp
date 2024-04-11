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
int h, w;
// Who = 0 (Alice). Who = 1 (Bob)
int req(int x1, int y1, int x2, int y2, int who) { // возвращает кто победил. 1 - Alice, 2 - Bob, 0 - Draw
    if (x1 > x2) {
        return 0;
    }
    if (who == 0) {
        if (x1 + 1 == x2 && y1 == y2) {
            return 1;
        }
        if (y1 >= 1 && y1 <= w && x1 + 1 >= h) {
            int who1 = req(x1 + 1, y1, x2, y2, 1);
        }
        if (y1 + 1 >= 1 && y1 + 1 <= w && x1 + 1 >= h) {
            int who2 = req(x1 + 1, y1 + 1, x2, y2 , 1);
        }
        if (y1 - 1 >= 1 && y1 + 1 <= w && x1 + 1 >= h) {
            int who3 = req(x1 + 1, y1 - 1, x2, y2, 1);
        }
    } else {

    }
    return 0;
}

void solve() {
    cin >> h >> w;
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