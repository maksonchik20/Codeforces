#include <iostream>
#include <vector>

using namespace std;
bool good(long long n, long long t, vector<vector<long long>> & users){
    long long cnt = 0;
    if (t == 0) {
        return 0;
    }
    for (const auto el : users) {
        long long x = (t/el[0]) / el[1] * el[2];
        cnt += (t - x + el[2]) /el[0];
    }
    // cout << cnt;
    return cnt >= n;
}
int main()
{
    long long m, n;
    cin >> m >> n;
    vector<vector<long long>> users(n);
    for (int i = 0; i < n; ++i) {
        long long t, z, y;
        cin >> t >> z >> y;
        users[i].push_back(t);
        users[i].push_back(z);
        users[i].push_back(y);
    }
    long long l, r;
    l = -1;
    r = 1;
    while (not good(m, r, users)) {
        r *= 2;
    }
    ++r;
    while (r != l + 1){
        long long sr = (l + r) / 2;
        // cout << sr;
        if (good(m, sr, users)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << l;
    return 0;
}
