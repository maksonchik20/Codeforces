#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<stack<int>> arr(k);
    unordered_map<int, int> get_ind_stack;
    for (int i = 0; i < k; ++i) {
        int length;
        cin >> length;
        int num;
        for (int j = 0; j < length; ++j) {
            cin >> num;
            get_ind_stack[num] = i;
            arr[i].push(num);
        }
    }
    unordered_map<int, bool> closet;
    vector<pair<int, int>> queries(q);
    unordered_map<int, bool> gets_use;
    unordered_map<int, int> cnt_use_item;
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first;
        cin >> queries[i].second;
        if (queries[i].first == 1) {
            cnt_use_item[queries[i].second]++;
            gets_use[queries[i].second] = true;
        }
    }
    
    int res = 0;
    vector<pair<int, int>> doing;
    
    for (auto el : gets_use) {
        if (closet[el.first] == false) {
            while (arr[get_ind_stack[el.first]].size() > 0) {
                doing.push_back({3, get_ind_stack[el.first] + 1});
                res++;
                closet[arr[get_ind_stack[el.first]].top()] = true;
                bool flag = false;
                if (arr[get_ind_stack[el.first]].top() == el.first) {
                    flag = true;
                }
                arr[get_ind_stack[el.first]].pop();
                if (flag) {
                    break;
                }
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        if (queries[i].first == 1) {
            doing.push_back({1, -1});
            cnt_use_item[queries[i].second]--;
            closet[queries[i].second] = false;
        } else {
            doing.push_back({2, 1});
            if (cnt_use_item[queries[i].second] != 0) {
                doing.push_back({3, 1});
                res++;
                closet[queries[i].second] = true;
            }
        }
    }
    cout << res << "\n";
    for (int i = 0; i < doing.size(); ++i) {
        if (doing[i].second == -1) {
            cout << 1 << "\n";
        } else {
            cout << doing[i].first << " " << doing[i].second << "\n";
        }
    }
    
    return 0;
}
