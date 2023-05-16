#include <iostream>
 
using namespace std;
 
bool good(long long w, long long h, long long n, long long x) {
    if ((x/w) * (x/h) >= n) {
        return 1;
    }
    return 0;
}
 
int main()
{
    long long w, h, n, l, r;
    cin >> w >> h >> n;
    l = 0;
    r = 1;
    while (good(w, h, n, r) == 0) {
        r *= 2;
    }
    while (r != l + 1) {
        long long m = (l + r) / 2;
        if (good(w, h, n, m) == 1) {
            r = m;
        } else {
            l = m;
        }
    } 
    cout << r << endl;
 
    return 0;
}