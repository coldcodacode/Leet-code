#include <bits/stdc++.h>
using namespace std;

bool func(string& s, string& t, int size, int k) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        count += (t[i] - s[i] >= 0) ? (t[i] - s[i]) : (26 + t[i] - s[i]);
    }
    if (k < count) return false;
    return ((k - count) % 26 == 0);
}

int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int n, k;
        cin >> n >> k;
        string s, t;
        cin >> s >> t;

        if (func(s, t, n , k)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}