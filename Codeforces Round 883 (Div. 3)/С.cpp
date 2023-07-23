#include <bits/stdc++.h>
using namespace std;


bool comp (pair <long long, long long> a, pair <long long, long long> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}
// bool comp2 (pair <long long, long long> a, pair <long long, long long> b) {
//     if (a.first == b.first) {
//         return a.second < b.second;
//     }
//     return a.first > b.first;
// }

int main()
{
    long long t;
    cin >> t;
    while (t--) {
        long long n, m, h;
        cin >> n >> m >> h;
        vector<pair<long long, long long>> arr(n);
        pair<long long, long long> first;
        bool flag = false;
        for (long long i = 0; i < n; ++i) {
            vector<long long> lst(m, 1);
            long long schtraf, now_time, cnt;
            schtraf = 0;
            now_time = 0;
            cnt = 0;
            for (auto& i : lst) {
                cin >> i;
            }
            sort(lst.begin(), lst.end());
            for (auto el : lst) {
                if (now_time + el <= h) {
                    cnt++;
                    now_time += el;
                    schtraf += now_time;
                } else {
                    break;
                }
            }
            if (flag == false) {
                first = {cnt, schtraf};
                flag = true;
            }
            arr[i] = {cnt, schtraf};
        }
        sort(arr.begin(), arr.end(), comp);
        for (long long i = 0; i < n; ++i) {
            if (first.first == arr[i].first and first.second == arr[i].second) {
                cout << i + 1 << endl;
                break;
            }
            // cout << el.first << " " << el.second << endl;
        }
    }

    return 0;
}
