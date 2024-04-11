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

const int SZ = 3;

struct Block {
    bool flag; // true - если все одинаковые элементы.
    vector<int> a;
    Block(vector<int> _a) {
        a = _a;
        int fi = a[0];
        flag = true;
        for (int i = 1; i < (int) a.size(); ++i) {
            if (a[i] != fi) {
                flag = false;
                break;
            }
        }
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<Block> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int now = 0;
    while (now < n) {
        vector<int> newBlock;
        int start = now;
        for (int i = start; i < start + SZ && now < n; ++i) {
            newBlock.push_back(a[now]);
            now++;
        }
        m.push_back(Block(newBlock));
    }
    // for (int i = 0;i < m.size(); ++i) {
    //     cout << "i: " << i << " flag: " << m[i].flag << "\n\t";
    //     for (int j = 0; j < m[i].a.size(); ++j) {
    //         cout << m[i].a[j] << " ";
    //     }
    //     cout << endl;
    // }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int fiBlock = (l - 1) / SZ;
        int seBlock = (r - 1) / SZ;
        for (int i = fiBlock + 1; i < seBlock; ++i) {
            if (m[i].flag == false) {
                int fi = m[i].a[0];
                for (int j = 0; j < m[i].a.size(); ++j) {
                    if (m[i].a[j] != fi) {
                        
                    }
                }
            }
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