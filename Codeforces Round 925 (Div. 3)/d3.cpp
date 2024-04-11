#include <bits/stdc++.h> 
 
using namespace std; 
 
#define int long long 
#ifdef LOCAL 
#include "algo/debug.h" 
#else 
#define debug(...) 42 
#endif 
 
signed main() { 
  ios::sync_with_stdio(false); 
  cin.tie(0); 
  int tt = 1;; 
  cin >> tt;; 
  while (tt--) { 
    int n, x, y; 
    cin >> n >> x >> y; 
    vector<int> a(n); 
    map<int, map<int, int>> g; 
    for (int i = 0; i < n; i++) { 
      cin >> a[i]; 
      ++g[a[i] % x][a[i] % y]; 
    } 
    auto complement = [&] (int p) { 
      return (x - (p % x)) % x; 
    }; 
    int tot = 0; 
    for (int &i : a) { 
        cout << complement(i) << endl;
      tot += g[complement(i)][i % y] - (i % x == complement(i)); 
    } 
    // cout << (tot >> 1) << '\n'; 
  } 
  return 0; 
}