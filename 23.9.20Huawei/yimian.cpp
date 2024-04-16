#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i]; 
    }

    unordered_map<int, int> m;
    for (auto item : v) {
        m[item]++;
    }

    for (auto item : m) {
        if (item.second == 1) 
            cout << item.first;
    }
}