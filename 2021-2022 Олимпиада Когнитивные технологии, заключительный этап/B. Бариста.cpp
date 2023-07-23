#include <bits/stdc++.h>

using namespace std;

int main()
{
    long double a, b;
    cin >> a >> b;
    if (a / b > 5) {
        cout << "latte";
    } else if (a / b < 3) {
        cout << "macchiato";
    } else {
        cout << "cappuccino";
    }
    return 0;
}
