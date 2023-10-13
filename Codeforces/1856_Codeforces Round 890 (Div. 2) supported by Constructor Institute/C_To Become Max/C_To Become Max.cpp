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
 
template <typename T>
void read(T &p)
{
    cin >> p;
}
 
template <typename T, typename T1>
void read(pair<T, T1> &p)
{
    read(p.ff);
    read(p.ss);
}
 
template <typename T>
void read(T arr[], ll n)
{
    for (ll i = 0; i < n; i++)
    {
        read(arr[i]);
    }
}
 
template <typename T>
void read(vector<T> &arr)
{
    for (ll i = 0; i < arr.size(); i++)
    {
        read(arr[i]);
    }
}
 
 
////////////////#####################OUPUT###############///////////////////////
 
template <typename T, typename T1>
void out(pair<T, T1> &p)
{
    cout << "(";
    out(p.ff);
    cout << ",";
    out(p.ss);
    cout << ")";
}
 
template <typename T>
void out(T arr[], ll n)
{
    for (ll i = 0; i < n; i++)
    {
        out(arr[i]);
        cout << " ";
    }
}
 
template <typename T>
void out(vector<T> &arr)
{
 
    cout << "[ ";
    for (ll i = 0; i < arr.size(); i++)
    {
        out(arr[i]);
        if (i!=arr.size()-1)
            cout << ", ";
    }
    cout << " ]";
 
}
 
 
 
template <typename T>
void out(set<T> &arr)
{
    for (auto i:arr)
    {
        out(i);
        cout << " ";
    }
}

template <typename T>
void out(multiset<T> &arr)
{
    for (auto i:arr)
    {
        out(i);
        cout << " ";
    }
}
 
template <typename T, typename T1>
void out(map<T,T1> &m)
{
    for (auto i:m)
    {
        out(i.first);
        cout<<" -> ";
        out(i.second);
        cout<<", ";
    }
}

////////////////////////////////////END TEMPLATE//////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


bool check(int mid, vector<int>& arr2, vector<int>& arr1, int n, int k) {
    int result = INT_MAX;
    for (int i = 0; i < n - 1; ++i) {
        int req = mid;
        int cnts = 0;
        for (int j = i; j < n; ++j) {
            if (arr2[j] >= req && arr1[j] < req) {
                cnts += abs(arr1[j] - req);
                req--;
            } else if (arr1[j] >= req) {
                break;
            } else if (arr2[j] < req) {
                cnts = INT_MAX;
                break;
            }
        }
        result = min(result, cnts);
    }
    return result <= k;
}


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr1(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }
    vector<int> arr2 = arr1;
    for (int i = n - 2; i >= 0; --i) {
        if (arr2[i] <= arr2[i + 1]) {
            arr2[i] = arr2[i+1] + 1;
        }
    }
    int left = *max_element(arr1.begin(), arr1.end());
    int right = *max_element(arr2.begin(), arr2.end());
    int result = *max_element(arr1.begin(), arr1.end());
    while (left <= right) {
        int mid = left + (right - left) / 2; 
        if (check(mid, arr2, arr1, n, k)) {
            left = mid + 1;
            result = max(result, mid);
        } else {
            right = mid - 1;
        }
    }
    cout << result << "\n";
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