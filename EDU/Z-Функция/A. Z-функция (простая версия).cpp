#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<int> pref_func(s.size());
    pref_func[0] = 0;
    for (int i = 1; i < s.size(); ++i) {
        string check_s = s.substr(i, s.size()-i);
        int cnt = 0;
        for (int j = 0; j < check_s.size(); ++j) {
            if (check_s[j] == s[j]) {
                cnt++;
            } else {
                break;
            }
        }
        pref_func[i] = cnt;
    }
    for (const auto el : pref_func) {
        cout << el << ' ';
    }
    return 0;
}
