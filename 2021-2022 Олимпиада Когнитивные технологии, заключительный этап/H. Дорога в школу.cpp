#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << "? 1" << endl;
    int a;
    cin >> a;
    cout << "? " << n / 2 + 1 << endl;
    int b;
    cin >> b;
    cout << "! " << min(a, b) << endl;
    return 0;
}
