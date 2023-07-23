#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> times(n);
    vector<int> works(n);
    vector<int> invites(n);
    for (int i = 0; i < n; ++i) {
        cin >> times[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> works[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> invites[i];
    }
    unordered_map<int, int> cnts;
    vector<int> result;
    for (int i = 0; i < n; ++i) {
        if (invites[i] == 0) {
            continue;
        }
        if (times[i] > times[invites[i] - 1] && works[i] != 0) {
            cnts[invites[i]]++;
            if (cnts[invites[i]] == 2) {
                result.push_back(invites[i]);
            }
        }
    }
    cout << result.size() << endl;;
    sort(result.begin(), result.end());
    if (cnts.size() != 0) {
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << " ";
        }
    }

    return 0;
}
