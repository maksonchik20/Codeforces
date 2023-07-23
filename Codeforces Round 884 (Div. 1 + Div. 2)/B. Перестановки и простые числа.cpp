#include <bits/stdc++.h>

#define ll long long

using namespace std;
  



int main()
{


    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        vector < ll > a(n);
        a[0] = 2;
        a[n - 1] = 3;
        a[n / 2] = 1;
        ll counter = 4;
        for(int i = 1; i < n - 1; i++)
        {
            if(i == n / 2) continue;
            a[i] = counter++;
        }
        for(int i = 0; i < n; i++)
        {
            cout << a[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}