#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> findNext(vector<int>& v, int size) {
    vector<int> res(size);
    stack<int> s;
    // s.push(0);
    for (int i = 0; i < size; i++) {
        // if (v[i] <= v[s.top()]) {
        //     s.push(i);
        // }
        while (!s.empty() && v[i] > v[s.top()] ) {
            res[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);

    }

    while (!s.empty()) {
        res[s.top()] = 0;
        s.pop();
    }

    return res;
}

int main() {
    int m;
    cin >> m;
    vector<int> stock;
    cout << stock.size() << " " << stock.max_size();
    vector<int> stockPrice(m);
    cout << stockPrice.size() << " " << stockPrice.max_size();
    for (int i = 0; i < m; i++) {
        cin >> stockPrice[i];
    }
    vector<int> res = findNext(stockPrice, m);

    for (auto item : res) {
        cout << item << " ";
    }
}