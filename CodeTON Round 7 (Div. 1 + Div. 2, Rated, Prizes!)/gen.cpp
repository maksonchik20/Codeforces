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
int cnt = 0;
int cnt_nums = 26;
string gen_string(int seed) {
    mt19937 rnd(seed + cnt);
    string s = "";
    int n = rnd() % 100 + 1;
    for (int i = 0; i < n; ++i) {
        int num = rnd() % cnt_nums;
        s += (char) ('A' + num);
    }
    cnt++;
    cout << n << endl;
    return s;
}

const int MAXN = 20;
const int MAXI = 1000000001;
int main(int argv, char** argc) {
    mt19937_64 rnd(stoi(argc[1]));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n = rnd() % 4 + 1;
    int x = rnd() % n;
    cout << n << " " << x << "\n";
    for (int i = 0; i < n; ++i) {
        cout << rnd() % (2 * n) + 1 << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; ++i) {
        cout << rnd() % (2 * n) + 1 << " ";
    }
    return 0;
}