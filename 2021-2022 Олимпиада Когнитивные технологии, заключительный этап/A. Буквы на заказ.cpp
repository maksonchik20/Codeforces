#include <bits/stdc++.h>

using namespace std;

int main()
{
    // A, B, C, D, E, F, G, H, I, J, K, L, M, 
    // N, O, P, Q, R, S, T, U, V, W, X, Y, Z.
    vector<char> arr_1 = {'A', 'D', 'O', 'P', 'Q', 'R'};
    char ch;
    cin >> ch;
    for (int i = 0; i < arr_1.size(); ++i) {
        if (arr_1[i] == ch) {
            cout << 1;
            return 0;
        }
    }
    if (ch == 'B') {
        cout << 2;
    } else {
        cout << 0;
    }

    return 0;
}
