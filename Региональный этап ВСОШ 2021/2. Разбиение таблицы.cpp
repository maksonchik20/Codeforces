#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long INF = 10e10;
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        long long n, m;
        cin >> n >> m;
        long long S_col = (2 + m*(n-1)) * n / 2;
        long long l = 0;
        long long r = m + 1;
        long long min_verical = INF;
        long long min_vertical_i = 0;
        while (l < r-1) {
            long long i = (l + r) / 2;
            long long S_all_left, S_col_right, S_all_right;
            S_all_left = (2 * S_col + n*(i-2)) * (i-1) / 2;
            S_col_right = ((2 * i) + m*(n-1))*n / 2;
            S_all_right = ((2*S_col_right) + n*(m-i)) * (m-i+1) / 2; 
            if (S_all_left - S_all_right > 0) {
                r = i;
            } else {
                l = i;
            }
            if (abs(S_all_left - S_all_right) < min_verical) {
                min_vertical_i = i;
                min_verical = abs(S_all_left - S_all_right);
            }
        }
        l = 0;
        r = n + 1;
        long long min_hor_i = 0;
        long long min_hor = INF;
        while (l < r-1) {
            long long i = (l + r) / 2;
            long long S_all_top, S_all_bottom;
            S_all_top = (1 + m*(i-1))*m*(i-1) / 2;
            S_all_bottom = ((m*(i-1) + 1) + m*n) * (n*m - (m*(i-1) + 1) + 1) / 2;
            if (S_all_top - S_all_bottom > 0) {
                r = i;
            } else {
                l = i;
            }
            if (abs(S_all_top - S_all_bottom) < min_hor) {
                min_hor_i = i;
                min_hor = abs(S_all_top - S_all_bottom);
            }
        }
        if (min_verical <= min_hor) {
            long long f_min_vert_minuse_1;
            long long i = min_vertical_i - 1;
            long long S_all_left = (2 * S_col + n*(i-2)) * (i-1) / 2;
            long long S_col_right = ((2 * i) + m*(n-1))*n / 2;
            long long S_all_right = ((2*S_col_right) + n*(m-i)) * (m-i+1) / 2;
            f_min_vert_minuse_1 = abs(S_all_left - S_all_right);
            if (min_vertical_i >= 3 and min_verical == f_min_vert_minuse_1){
                cout << "V " << min_vertical_i - 1 << "\n";
            } else {
                cout << "V " << min_vertical_i << "\n";
            }
        } else {
            long long f_min_hor_minuse_1;
            long long i = min_hor_i - 1;
            long long S_all_top = (1 + m*(i-1))*m*(i-1) / 2;
            long long S_all_bottom = ((m*(i-1) + 1) + m*n) * (n*m - (m*(i-1) + 1) + 1) / 2;
            f_min_hor_minuse_1 = abs(S_all_top - S_all_bottom);
            if (min_hor_i >= 3 and min_hor == f_min_hor_minuse_1) {
                cout << "H " << min_hor_i - 1 << "\n";
            } else {
                cout << "H " << min_hor_i << "\n";
            }
        }
    }
}
