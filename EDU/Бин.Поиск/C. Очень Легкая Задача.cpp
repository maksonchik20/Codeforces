#include <iostream>

using namespace std;
long long null = 0;
bool good(long long n, long long x, long long y, long long t) {
    if (n == 1) {
        return (t/min(x, y) >= n);
    }
    if (x < y) {
        return (((t/x) + (max((t-x), null) / y)) >= n);
    }
    return (((t/y) + (max((t-y), null) / x)) >= n);
}

int main()
{
    long long n, x, y;
    cin >> n >> x >> y;
    
    long long l, r;
    l = -1;
    r = 1;
    while (not good(n, x, y, r)) {
        r *= 2;
    }
    ++r;
    while (l + 1 != r) {
        long long m = (l + r) / 2;
        if (good(n, x, y, m)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r;
        

    return 0;
}
