#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1000000007
#define maxn 100000000000017    
#define endl "\n"
#define mk make_pair
#define pll pair<ll, ll>
#define vll vector<ll>
#define vld vector<ld>
#define vpll vector<ppl>
#define f first
#define s second
#define pb push_back
 
typedef long long ll;
typedef long double ld;
 
 
#define o(...) if(local=='L') {__f(#__VA_ARGS__, __VA_ARGS__); cout<<endl;}
 
#define Ns 1000007
 
char local = 'O';
 
////////////////#####################INPUT###############///////////////////////
 
////////////////////////////////////END TEcntsLATE//////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


void solve() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    s += '0';
    int start = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= '5') {
            s[i + 1]++;
            for (int k = i; k >= start; --k) {
                s[k] = '0';
            }
            start = i;
        }
    }
    reverse(s.begin(), s.end());
    start = 0;
    if (s[0] == '0') {
        start++;
    }
    for (int i = start; i < s.size(); i++) {
        cout << s[i];
    }
    cout << "\n";
}

// #define DEBUG

int main()
{
    #ifdef DEBUG
        local = 'L';
        time_t start, end;
        time(&start);
        freopen("input/input0.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
 
    ll t1;
    cin>>t1;
 
    while (t1--) {
        solve();
    }
 
    
 
    #ifdef DEBUG
    time(&end);
    double time_taken = double(end - start);
    cout << endl
        << endl
        << endl
        << "Time taken by program is : " << fixed
        << time_taken << setprecision(6);
    cout << " sec " << endl;
    #endif
}