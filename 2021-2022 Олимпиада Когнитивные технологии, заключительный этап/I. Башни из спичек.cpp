#include <bits/stdc++.h>

using namespace std;

long long good_for_1(long long cnt) {
    if (cnt < 4) {
        return 0;
    }
    long long res = 0;
    long long left = 0;
    long long right = cnt;
    while (left + 1 != right) {
        long long mid = (left + right) / 2;
        if (mid * 2 + mid + 1 > cnt) {
            right = mid;
        } else {
            left = mid;
            if (left > res) {
                res = left;
            }
        }
    }
    return res;
}

long long good_for_2(long long height_cnt, long long width_cnt) {
    long long res = 0;
    long long left = 0;
    long long right = width_cnt + height_cnt;
    while (left + 1 != right) {
        long long mid = (left + right) / 2;
        if (height_cnt >= mid*2 && width_cnt >= mid + 1) {
            if (mid > res) {
                res = mid;
            }
            left = mid;
        } else {
            right = mid;
        }
    }
    return res;
}

int main()
{
    long long n;
    cin >> n;
    vector<long long> lenghts(n);
    unordered_map<long long, long long> cnts; // ключ - длина. значение - количество.
    for (long long i = 0; i < n; ++i) {
        cin >> lenghts[i];
        cnts[lenghts[i]]++;
    }
    vector<pair<long long, long long>> cnts_v;
    for (auto el : cnts) {
        cnts_v.push_back({el.second, el.first});
    }
    sort(cnts_v.begin(), cnts_v.end());
    if (cnts_v.size() == 1) {
        long long res = good_for_1(cnts_v[0].first);
        if (res == 0) {
            cout << "-1 -1 -1" << endl; 
        } else {
            cout << res << " " << cnts_v[0].second << " " << cnts_v[0].second << endl;
        }
        return 0;
    }
    long long max_cnt_w = cnts_v[cnts_v.size() - 1].first;
    long long len_max_cnt_w = cnts_v[cnts_v.size() - 1].second;
    long long two_max_cnt_w = cnts_v[cnts_v.size() - 2].first;
    long long len_two_max_cnt_w = cnts_v[cnts_v.size() - 2].second;
    long long ind_max_cnt_w = cnts_v.size() - 1;
    long long res = 0;
    long long res_w = 0;
    long long res_h = 0;
    long long max_res_h = 0;
    for (long long i = 0; i < cnts_v.size(); ++i) {
        long long res_cache = good_for_1(cnts_v[i].first);
        if (cnts_v[i].second * res_cache > max_res_h) {
            res = res_cache;
            res_w = cnts_v[i].second;
            res_h = cnts_v[i].second;
            max_res_h = cnts_v[i].second * res_cache;
        }
        if (i == ind_max_cnt_w) {
            res_cache = good_for_2(cnts_v[i].first, two_max_cnt_w);
            if (cnts_v[i].second * res_cache > max_res_h) {
                res = res_cache;
                res_w = len_two_max_cnt_w;
                res_h = cnts_v[i].second;
                max_res_h = cnts_v[i].second * res_cache;
            }
        } else {
            res_cache = good_for_2(cnts_v[i].first, max_cnt_w);
            if (cnts_v[i].second * res_cache > max_res_h) {
                res = res_cache;
                res_w = len_max_cnt_w;
                res_h = cnts_v[i].second;
                max_res_h = cnts_v[i].second * res_cache;
            }
        }
    }
    if (res != 0) {
        cout << res << " " << res_h << " " << res_w << endl;
    } else {
        cout << "-1 -1 -1" << endl;
    }
    return 0;
}
