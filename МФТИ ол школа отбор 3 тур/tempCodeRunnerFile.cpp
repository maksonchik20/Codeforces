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

void stop() {
    exit(0);
}
int r, b, c;
bool isBuyCar = false;
int sum = 0;

void bus() {
    sum += r;
    cout << "bus" << endl;
}

void car() {
    if (!isBuyCar) {
        sum += b + c;
        cout << "buy" << endl;
        isBuyCar = true;
    } else {
        sum += c;
        cout << "car" << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> b >> c;
    while (true) {
        string q;
        cin >> q;
        if (q == "stop") {
            stop();
        } else if (q == "go") {
            if (r <= c) {
                bus();
            } else if (sum + r >= b) {
                car();
            } else {
                bus();
            }
        }
    }
    return 0;
}