#include <bits/stdc++.h>

using namespace std;

long long solve(vector<long long>& charges) {
    int n = charges.size();
    long long result = charges[n - 1];
    for (int i = 0; i < n - 1; i++) {
        if (charges[i] < 0 && charges[i + 1] > 0) {
            result += charges[i];
            charges[i + 1] += charges[i];
        }
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> charges(n);
        for (int i = 0; i < n; i++) {
            cin >> charges[i];
        }
        long long result = solve(charges);
        cout << result << "\n";
    }
    return 0;
}