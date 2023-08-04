#include <bits/stdc++.h>

using namespace std;

long long req(long long n, long long k) {
    vector<long long> fib(k, 0);
    long long result = 0;
    for (long long i = n - ((n + 1) / 2); i <= n; ++i) {
        fib[k - 1] = n;
        fib[k - 2] = i;
        fib[k - 3] = n - i;
        for (long long j = k - 4; j > -1; --j) {
            fib[j] = fib[j + 2] - fib[j + 1];
        }
        // cout << i << endl;
        // for (auto el : fib) {
        //     cout << el << " ";
        // }
        // cout << endl;
        bool flag = true;
        if (fib[0] < 0) {
            flag = false;
        }
        for (long long p = 1; p < k; ++p) {
            if (fib[p] < 0 || fib[p] < fib[p - 1]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            result++;
        }
    }
    return result;
}


int main()
{
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        if (k > 30) {
            cout << 0 << endl;
            continue;
        }
        
        cout << req(n, k) << endl;
    }
    return 0;
}
