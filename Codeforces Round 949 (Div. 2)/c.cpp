#include<bits/stdc++.h>
using namespace std;

int t;
int main() {
    cin >> t;
    for(int test = 0; test < t; ++test) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int& v : a) cin >> v;
        a.push_back(-1);
        int l = -1;
        int r = 0;
        vector<int> cnt(30);
        for(int i = 0; i <= n; ++i) {
            if(a[i] != -1) {
                if(l != -1 && !(l/2 <= a[i] && a[i] <= l+l%2)) {
                    cout << "-1n";
                    goto nxt;
                }
                for(int k = 0; k < 30; ++k) if(cnt[k]) {
                    if((1 << k) > a[i]) {
                        cout << "-1n";
                        goto nxt;
                    }
                    r = max(r, 1 << k);
                }
                l = a[i];
                fill(begin(cnt), end(cnt), 0);
            }
            else {
                int pre = (i > 0 ? max(a[i-1], r) : 0);
                ++cnt[31-__builtin_clz(pre+pre%2)];
            }
        }
        a.pop_back();
        for(int i = 0; i < n; ++i) if(a[i] == -1) {
            a[i] = (i > 0 ? max(a[i-1], r) : r);
        }
        for(int v : a) cout << v << " ";
        cout << "n";
        nxt:;
    }
    return 0;
}