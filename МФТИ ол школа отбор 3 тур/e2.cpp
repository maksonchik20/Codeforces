#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<ll>> generateTriangles(ll limit) {
    vector<vector<ll>> triangles;
    for (ll m = 2; m * m <= limit; ++m) {
        for (ll n = 1; n < m; ++n) {
            if (__gcd(m, n) == 1 && (m - n) % 2 == 1) {
                ll a = m * m - n * n;
                ll b = 2 * m * n;
                ll c = m * m + n * n;
                if (c > limit) break;
                for (ll k = 1; ; ++k) {
                    ll a_scaled = k * a, b_scaled = k * b, c_scaled = k * c;
                    // if (a == 5 && b == 12 && c == 13 && k == 10) {
                    //     cout << "FIND!!! " << a_scaled << " " << b_scaled << endl;
                    // }
                    if (c_scaled > limit) break;
                    vector<ll> triangle = {a_scaled, b_scaled, c_scaled};
                    sort(triangle.begin(), triangle.end());
                    reverse(triangle.begin(), triangle.end());
                    triangles.push_back(triangle);
                }
            }
        }
    }
    sort(triangles.begin(), triangles.end());
    return triangles;
}

bool cmp(vector<ll>& fi, vector<ll>& se) {
    if (fi[2] != se[2]) {
        return fi[2] < se[2];
    } else {
        return fi[1] < se[1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll limit = 1e6;
    vector<vector<ll>> triangles = generateTriangles(limit);
    sort(triangles.begin(), triangles.end());
    string type;
    cin >> type;
    int n;
    cin >> n;
    if (type == "encode") {
        for (int i = 0; i < n; ++i) {
            vector<ll> tri(3);
            cin >> tri[0] >> tri[1] >> tri[2];
            sort(tri.begin(), tri.end());
            reverse(tri.begin(), tri.end());
            int ind = lower_bound(triangles.begin(), triangles.end(), tri) - triangles.begin();
            cout << ind + 1 << "\n";
        }
    } else {
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            vector<ll> tri = triangles[x - 1];
            cout << tri[0] << " " << tri[1] << " " << tri[2] << "\n";
        }
    }
    return 0;
}
