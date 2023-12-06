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

int main(int argv, char** argc) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s = argc[1];
    vector<int> a;
    string ok;
    cin >> ok;
    for (int i = 2; i < argv; ++i) {
        a.push_back(stoi(argc[i]));
    }
    vector<int> b(a.size());
    for (int i = 0; i < a.size(); ++i) {
        cin >> b[i];
    }
    for (auto el : b) {
        cout << el << " ";
    }
    if (ok == "NO") {
        std::sort(b.begin(), b.end());
        do {
            for (auto el : b) {
                cout << el << " ";
            }
            cout << endl;
        } while(std::next_permutation(b.begin(), b.end()));
        // return 0;
    }
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] > b[i]) {
            cnt++;
        }
    }
    if (cnt != stoi(argc[1])) {
        cout << "ERROR" << endl;
        cout << "x=" << argc[1] << endl;;
        for (int i = 0; i < a.size(); ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}