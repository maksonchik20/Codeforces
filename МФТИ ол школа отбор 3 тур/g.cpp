#include <bits/stdc++.h>

using namespace std;

const int n = 31;
using ll = long long;
struct Node {
    int cnt;
    int link[2];
    int cnt_for_link[2];
    Node() {
        cnt = 0;
        for (int i = 0; i < 2; ++i) {
            link[i] = -1;
            cnt_for_link[i] = 0;
        }
    }
};

vector<Node> trie(1);

void add_num(const int& num) {
    string binary = bitset<n>(num).to_string();
    int v = 0;
    for (auto el : binary) {
        int now_n = int(el - '0');
        if (trie[v].link[now_n] == -1) {
            trie.push_back(Node());
            trie[v].link[now_n] = (int) trie.size() - 1;
        }
        trie[v].cnt_for_link[now_n]++;
        v = trie[v].link[now_n];
    }
    trie[v].cnt++;
}

void del_num(const int& num) {
    string binary = bitset<n>(num).to_string();
    int v = 0;
    for (auto el : binary) {
        int now_n = int(el - '0');
        if (trie[v].link[now_n] == -1) {
            trie.push_back(Node());
            trie[v].link[now_n] = (int) trie.size() - 1;
        }
        trie[v].cnt_for_link[now_n]--;
        v = trie[v].link[now_n];
    }
    trie[v].cnt--;
}
ll find(const int& num) {
    string binary = bitset<n>(num).to_string();
    ll res = 0;
    int v = 0;
    int i = 30;
    for (auto el : binary) {
        int now_n = int(el - '0');
        if (trie[v].cnt_for_link[now_n ^ 1] > 0 && trie[v].link[(now_n ^ 1)] != -1) {
            if ((now_n ^ 1) == 1) {
                res += (ll) pow(2, i);
            }
            v = trie[v].link[(now_n ^ 1)];
        } else {
            if (now_n == 1) {
                res += (ll) pow(2, i);
            }
            v = trie[v].link[now_n];
        }
        i--;
    }
    return res;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, n;
    cin >> k >> n;
    for (int i = 0; i < k; ++i) {
        string s;
        cin >> s;
        int res = 0;
    }
    // int q;
    // cin >> q;
    // add_num(0);
    // while (q--) {
    //     char ch; int x;
    //     cin >> ch >> x;
    //     if (ch == '+') {
    //         add_num(x);
    //     } else if (ch == '-') {
    //         del_num(x);
    //     } else if (ch == '?') {
    //         cout << (find(x) ^ x) << "\n";
    //     }
    // }
    return 0;
}
