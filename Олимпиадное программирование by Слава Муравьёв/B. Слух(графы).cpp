#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

int dfs(std::map<int, vector<long long>>& graph, long long& start,std::vector<long long>& a,std::map <long long, bool>& visited, long long min_path = std::pow(10, 10)) {
    visited[start] = true;
    min_path = std::min(min_path, a[start-1]);
    for (const auto path : graph[start]) {
        long long p = path;
        if (visited[path] == false) {
            long long d = dfs(graph, p, a, visited, min_path);
            if (d < min_path) {
                min_path = d;
            }
        }
    }
    return min_path;
}
int main()
{
    std::map<int, vector<long long>> graph = {};
    long long n, m;
    vector <long long> a;
    cin >> n >> m;
    std::map <long long, bool> visited;
    for (int i=0;i<n;i++){
     long long c;
     cin >> c;
     a.push_back(c);
     visited[i+1] = false;
    }
    for (int i=0; i<m; ++i){
        long long x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    long long cnt = 0;
    for (long long i=1; i<=n; ++i){
        if (visited[i] == false) {
            long long df = dfs(graph, i, a, visited);
            cnt += df;
        }
    }
    cout << cnt;
}
