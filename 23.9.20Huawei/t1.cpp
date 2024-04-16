#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int m;
    cin >> m;
    vector<int> v(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i] ;
    }

    int target;
    cin >> target;

    int i = 0;
    for ( ; i < m - 1; i++) {
        if (v[i] > v[i+1]) {
            break;
        }
    }
    int start;
    if (i == m-1) start = 0;
    else start = i+1;

    bool flag = false;
    int res1 = -1, res2 = -1;
    for (int j = start, count = 0; count < m; count++, j = (j+1)%m) {
        if (!flag && v[j] == target) {
            res1 = j;
            res2 = res1;
            flag = true;
        }
        if (flag && v[j] == target) res2 = j;
    }

    cout << res1 << " " << res2;
}