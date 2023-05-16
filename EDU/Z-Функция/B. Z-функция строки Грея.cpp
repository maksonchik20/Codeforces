#include <iostream>
#include <vector>
#include <string>

using namespace std;

string stringGray() {
    const std::string c{"abcdefghijklmnopqrstuvwxyz"};
    string prev = "a";
    for (int i = 2; i < 27; ++i) {
        string a = prev + c[i-1] + prev;
        prev = a;
    }
    return prev;
}

vector<int> pref_func_str(string s) {
    vector<int> pref_func(s.size(), 0);
    pref_func[0] = 0;
    for (int i = 1; i < s.size(); ++i) {
        string check_s = s.substr(i, s.size()-i);
        for (int j = 0; j < check_s.size(); ++j) {
            if (check_s[j] == s[j]) {
                pref_func[i]++;
            } else {
                break;
            }
        }
    }
    return pref_func;
}

int main()
{
    int t;
    cin >> t;
    cout << t;
    string gray_str = stringGray();
    vector<int> pr = pref_func_str(gray_str);
    // for (const auto el : pr) {
    //     cout << el << " ";
    // }
    for (int i=0; i < t; ++i) {
        int k, j;
        cin >> k >> j;
        cout << pr[j] << endl;
    }
    
    return 0;
}
