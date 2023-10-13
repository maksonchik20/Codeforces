#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
ll n, k;
ll k_2;
ll MOD = 1000000007;
vector<ll> arr;
void change_next_dp(vector<vector<vector<ll>>>& dp, ll i, ll mask, ll flag) {
    if (i >= n - 1) {
        return;
    }
    if (arr[i + 1] == 2) {
        if (mask == k_2 / 2 - 1) { 
            dp[i + 1][0][1] += dp[i][mask][flag];
            dp[i + 1][0][1] %= MOD;
        } else {
            dp[i + 1][mask + 1][flag] += dp[i][mask][flag] % MOD;
            dp[i + 1][mask + 1][flag] % MOD;
        }
    } else if (arr[i + 1] == 4) {
        if (mask == k_2 / 2 - 2) {
            dp[i+1][0][1] += dp[i][mask][flag] % MOD;
            dp[i+1][0][1] %= MOD;
        } else if (mask % 2 != 0) {
            dp[i + 1][2][flag] += dp[i][mask][flag] % MOD;
            dp[i + 1][2][flag] %= MOD;
        } else {
            dp[i + 1][mask+2][flag] += dp[i][mask][flag] % MOD;
            dp[i + 1][mask+2][flag] %= MOD;
        }
    } else {
        if (mask == k_2 / 2 - 1) {
            dp[i + 1][0][1] += dp[i][mask][flag] % MOD;
            dp[i + 1][0][1] %= MOD;
        } else {
            dp[i + 1][mask + 1][flag] += dp[i][mask][flag] % MOD;
            dp[i + 1][mask + 1][flag] %= MOD;
        }
        if (mask == k_2 / 2 - 2) {
            dp[i+1][0][1] += dp[i][mask][flag] % MOD;
            dp[i+1][0][1] %= MOD;
        } else if (mask % 2 != 0) {
            dp[i + 1][2][flag] += dp[i][mask][flag] % MOD;
            dp[i + 1][2][flag] %= MOD;
        } else {
            dp[i + 1][mask+2][flag] += dp[i][mask][flag] % MOD;
            dp[i + 1][mask+2][flag] %= MOD;
        }
    }
}
 
 
int main() {
    cin >> n >> k;
    k_2 = pow(2, k);
    arr.resize(n);
    for (auto & it : arr) {
        cin >> it;
    }
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(k_2, vector<ll>(2, 0)));
    if (arr[0] == 2) {
        dp[0][1][0] = 1;
    } else if (arr[0] == 4) {
        dp[0][2][0] = 1;
    } else {
        dp[0][1][0] = 1;
        dp[0][2][0] = 1;
    }
    for (ll i = 0; i < n; ++i) {
        for (ll mask = 0; mask < k_2; ++mask) {
            if (dp[i][mask][0] != 0) {
                change_next_dp(dp, i, mask, 0);
            }
            if (dp[i][mask][1] != 0) {
                change_next_dp(dp, i, mask, 1);
            }
        }
    }
    ll res = 0;
    for (ll mask = 0; mask < k_2; ++mask) {
        if (dp[n - 1][mask][1] != 0) {
            res += dp[n - 1][mask][1];
            res %= MOD;
        }
    }
    cout << res;
    
    return 0;
}