#include <iostream>
#include <vector>
#include <utility>
#include <map>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> products;
    for (int i=0; i < n; ++i) {
        int p, e;
        cin >> p >> e;
        products.push_back({p, e});
    }
    vector<pair<int, map<int, bool>>> dp(k+1, {0, {}});
    for (int i=1; i < k+1; ++i) {
        for (int j=0; j<n; ++j) {
            int p, e;
            p = products[j].first;
            e = products[j].second;
            if (p <= i) {
                map<int, bool> sl;
                sl = dp[i-1].second;
                if (dp[i-1].first > dp[i].first) {
                    dp[i] = {dp[i-1].first, sl};
                }
            if (p <= i and dp[i-p].second.find(j) == dp[i-p].second.end()) {
                map<int, bool> sl;
                sl = dp[i-p].second;
                if (dp[i-p].first + e > dp[i].first) {
                    sl[j] = true;
                    dp[i] = {dp[i-p].first + e, sl};
                }
            }
            }
        }
    }
    for (int i = 1; i < k+1; ++i) {
        cout << dp[i].first << " ";
    }

    return 0;
}
