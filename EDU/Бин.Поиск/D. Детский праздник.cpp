#include <iostream>
#include <vector>
#include <tuple>
using namespace std;


bool f(vector<tuple<int, int, int>>& users, int& m, long long t) {
    long long cnt = 0;
    for (auto el : users) {
        if (get<0>(el) > t){
            continue;
        }
        int cnt_with_rest = (t / (get<0>(el) * get<1>(el) + get<2>(el))) * get<1>(el);
        int a = (t % (get<0>(el) * get<1>(el) + get<2>(el)) / get<0>(el));
        int b = get<1>(el);
        int cnt_by_time = min(a, b);
        cnt += cnt_with_rest + cnt_by_time;
    }
    if (cnt >= m) {
        return true;
    }
    return false;
}


int main() {
    int m, n;
    cin >> m >> n;
    vector<tuple<int, int, int>> users(n);
    for (int i=0; i < n; ++i) {
        int t, z, y;
        cin >> t >> z >> y;
        tuple <int, int, int> for_users(t, z, y);
        users[i] = for_users;
    }
    // cout << f(users, m, 10);
    long long left = 0;
    long long right = 1e9;
    while (left + 1 != right) {
        long long t = (left + right) / 2;
        if (f(users, m, t)) {
            right = t;
        } else {
            left = t;
        }
    }
    cout << right << endl;
    int t = right;
    for (auto el : users) {
        int cnt_with_rest = (t / (get<0>(el) * get<1>(el) + get<2>(el))) * get<1>(el);
        int a = (t % (get<0>(el) * get<1>(el) + get<2>(el)) / get<0>(el));
        int b = get<1>(el);
        int cnt_by_time = min(a, b);
        int cnt = cnt_with_rest + cnt_by_time;
        cnt = min(cnt, m);
        cout << max(cnt, 0) << " ";
        m -= cnt;
    }   
    return 0;
}