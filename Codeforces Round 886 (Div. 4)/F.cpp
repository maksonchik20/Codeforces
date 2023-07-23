#include <bits/stdc++.h>

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long t, n, elem;
    vector<long long> array;
    map<long long,long long> mp;
    cin>>t;
    while (t--)
    {
        cin>>n;
        mp.clear();
        array=vector<long long>(n+1,0);
        for (long long i = 0; i < n; i++) {
            cin>>elem;
            if (elem<=n) {
                mp[elem]++;
            }
        }
        for (long long i = 1; i <= n; i++) {
            if (mp[i]==0) continue;
            for (long long j = i; j <= n; j+=i) {
                array[j]+=mp[i];
            }
            
        }
        int res = *max_element(array.begin(), array.end());
        cout<<res<<'\n';
    }
    
    return 0;
}