#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        vector<vector<long long>> dist(n+1);
        vector<long long> prev(n+1, 0);
        vector<long long> arr(n+1, 0);
        for (long long i = 0; i < n; ++i) {
            long long ind = i + 1;
            prev[ind] = 0;
            dist[ind] = vector<long long>();
        }
        for (long long i = 0; i < n; ++i) {
            long long ind = i + 1;
            cin >> arr[ind];
        }
        for (long long i = 0; i < n; ++i) {
            long long ind = i + 1;
            dist[arr[ind]].push_back(ind - prev[arr[ind]] - 1);
            prev[arr[ind]] = ind;
        }
        long long mn = (long long) 1000000000000000000;
        const int diap = 2;
        for (long long i = 0; i < k; ++i) {
            long long ind = i + 1;
            dist[ind].push_back(n - prev[ind]);
            sort(dist[ind].rbegin(), dist[ind].rend());
            long long res = dist[ind][0] / diap;
            if (dist[ind].size() >= diap) {
                res = max(res, dist[ind][1]);
            }
            mn = min(mn, res);
        }
        cout << mn << endl;
    }
    return 0;
}