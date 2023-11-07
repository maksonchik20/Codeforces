/* 
Code By maksonchik20
*/

#include <bits/stdc++.h>
using namespace std;
 
// Структура данных для хранения элемента и его индекса в массиве
struct Node
{
    int elem;
    int index;
};
 
// Перегружаем оператор сравнения для вставки в набор
inline bool operator<(const Node &lhs, const Node &rhs) {
    return lhs.elem < rhs.elem;
}
 
// Функция для печати LIS с использованием родительского массива
vector<int> print(vector<int> const &input, auto parent, set<Node> s) {
    // контейнер для хранения LIS в обратном порядке
    stack<int> lis;
 
    // начинаем с последнего элемента `s`
    int index = s.rbegin()->index;
 
    // получаем длину LIS
    int n = s.size();
 
    // получаем LIS из родительского массива
    while (n--)
    {
        lis.push(index);
        index = parent[index];
    }
    vector<int> res;
    while (!lis.empty())
    {
        res.push_back(lis.top());
        // cout << lis.top() << " ";
        lis.pop();
    }
    return res;
}
 
// Функция для поиска самой длинной возрастающей подпоследовательности в заданном массиве
vector<int> printLIS(vector<int> const &input)
{
    // базовый вариант
    if (input.size() == 0) {
        return {};
    }
 
    // создаем пустой упорядоченный набор `s` (i-й элемент в `s` определяется как
    // наименьшее целое число, которым заканчивается возрастающая последовательность длины `i`)
    set<Node> s;
 
    // `parent[i]` будет хранить предшественник элемента с индексом `i` в ЛИС,
    // заканчивается на элементе с индексом `i`.
    map<int, int> parent;
 
    // обрабатываем каждый элемент один за другим
    for (int i = 0; i < input.size(); i++)
    {
        // строим узел из текущего элемента и его индекса
        Node curr = {input[i], i};
 
        // игнорировать текущий элемент, если он уже присутствует в наборе
        if (s.find(curr) != s.end()) {
            continue;
        }
 
        // вставляем текущий узел в набор и получаем итератор к
        // вставленный узел
        auto it = s.insert(curr).first;
 
        // если узел не вставлен в конец, то удаляем следующий узел
        if (++it != s.end()) {
            s.erase(it);
        }
 
        // получаем итератор к текущему узлу и обновляем родителя
        it = s.find(curr);
        parent[i] = (--it)->index;
    }
 
    // распечатать LIS, используя родительскую карту
    vector<int> res = print(input, parent, s);
    return res;
}
 
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> two(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> two[i];
        two[i] *= -1;
    }
    sort(two.begin(), two.end());
    for (int i = 0; i < m; ++i) {
        two[i] *= -1;
    }
    vector<int> input = { 2, 6, 3, 4, 1, 2, 9, 5, 8 };
    vector<int> path = printLIS(input);
    int ind_sort_m = 0;
    int path_ind = 0;
    vector<int> res(n + m);
    int now = 0;
    for (int i = 0; i < n; ++i) {
        while (ind_sort_m < m && a[i] <= two[ind_sort_m]) {
            res[now] = (two[ind_sort_m]);
            now++;
            ind_sort_m++;
        }
        if (path_ind < (int) path.size() && a[i] == path[path_ind]) {
            res[now] = (a[i]);
            now++;
            path_ind++;
        } else {
            res[now] = (a[i]);
            now++;
        }
    }
    while (ind_sort_m < m) {
        res[now] = (two[ind_sort_m]);
        now++;
        ind_sort_m++;
    }
    for (auto el : res) {
        cout << el << " ";
    }
    cout << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
