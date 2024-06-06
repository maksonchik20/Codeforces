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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int k = 0; k < t; ++k) {

        int n;
        cin >> n;
        vector<int> arr(n);
        map<int, set<int>> pos;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            pos[arr[i]].insert(i);
        }
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            // сначало хочу убить 3 бит с конца, если он 1, затем 2, 1
            vector<int> finds;
            for (int j = 1; j < 4; ++j) {
                if ((arr[i] ^ j) < arr[i]) {
                    finds.push_back(arr[i] ^ j);
                    // cout << arr[i] << " XOR: " << (arr[i] ^ j) << endl;
                }
            }
            sort(finds.begin(), finds.end());
            bool flag = false;
            for (auto el : finds) {
                // cout << i << " " << arr[i] << " find: " << el << " szFind: " << pos[el].size() << endl;
                if ((int) pos[el].size() != 0) {
                    res[i] = el;
                    int x = *pos[el].begin();
                    int y = i;
                    pos[arr[i]].erase(i);
                    pos[arr[i]].insert(*(pos[el].begin()));
                    pos[el].erase(pos[el].begin());
                    swap(arr[x], arr[y]);
                    flag = true;
                    break;
                }
            }
            if (flag) {
                continue;
            }
            res[i] = arr[i];
            pos[arr[i]].erase(i);
        }
        for (auto el : res) {
            cout << el << " ";
        }
        cout << "\n";
    }
    return 0;
}