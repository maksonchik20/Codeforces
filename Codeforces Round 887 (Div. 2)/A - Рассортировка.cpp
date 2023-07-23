#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> srt;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            srt.push_back(arr[i]);
        }
        sort(srt.begin(), srt.end());
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            if (srt[i] != arr[i]) {
                flag = false;
                cout << 0 << endl;
                break;
            }
        }
        if (flag) {
            long long res = 1000000005;
            long long ans = 1000000005;
            for (int i = 0; i < n - 1; ++i) {
                if (arr[i + 1] - arr[i] < res) {
                    res = arr[i + 1] - arr[i];
                    ans = (arr[i + 1] - arr[i]) / 2 + 1;
                }
            }
            cout << ans << endl;
        }
    }

    return 0;
}
