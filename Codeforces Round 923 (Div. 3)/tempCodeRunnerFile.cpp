/* 
Code By maksonchik20
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll MOD = (ll) 1e9 + 7;
const ld EPS = 0.00000000001;
const ll INF = (ll) 1e18;
const ld PI = 3.141592653589793238462643383279502884;

vector<vector<pair<int, int>>> g;

vector<char> cl;
vector<int> p;
int cycle_st, cycle_end;

bool dfs(int v, int pred) {
    cout << "v: " <<  v << " " << pred << endl;
	cl[v] = 1;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i].first;
        cout << "v: " << v << " -> " << to << endl;
		if (cl[to] == 0 && to != pred) {
			p[to] = v;
			if (dfs(to, v))  return true;
		} else if (cl[to] == 1 && to != pred) {
			cycle_end = v;
			cycle_st = to;
			return true;
		}
	}
	cl[v] = 2;
	return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    p.assign (n + 1, -1);
	cl.assign (n + 1, 0);
	cycle_st = -1;
	for (int i=1; i<=n; ++i)
		if (cl[i] == 0 && dfs(i, -1))
			break;
	if (cycle_st == -1)
		puts ("Acyclic");
	else {
		puts ("Cyclic");
		vector<int> cycle;
		cycle.push_back (cycle_st);
		for (int v=cycle_end; v!=cycle_st; v=p[v])
			cycle.push_back (v);
		cycle.push_back (cycle_st);
		reverse (cycle.begin(), cycle.end());
		for (size_t i=0; i<cycle.size(); ++i)
			printf ("%d ", cycle[i]+1);
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    // t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}