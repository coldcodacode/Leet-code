#include <iostream>
#include <vector>
using namespace std;

bool check(vector<vector<int>>& v, int i ,int j, int k) {
    for (int p = 0; p < 9; p++) {
        if (v[i][p] == k) return false;
    }
    for (int q = 0; q < 9; q++) {
        if (v[q][j] == k) return false;
    }
    int base_i = i / 3 * 3;
    int base_j = j / 3 * 3;
    for (int p = base_i; p < base_i + 3; p++) {
        for (int q = base_j; q < base_j + 3; q++) {
            if (v[p][q] == k) return false;
        }
    }
    return true;
}

bool dfs(vector<vector<int>>& v, int i, int j) {
    if (i == 9) return true;
    if (j == 9) return dfs(v, i + 1, 0);
    if (v[i][j] != 0) return dfs(v, i, j+1);

    for (int k = 1; k <= 9; k++) {
        if (!check(v, i, j, k)) {
            continue;
        }
        v[i][j] = k;
        if (!dfs(v, i, j+1)) {
            v[i][j] = 0;
            continue;
        }
        return true;
    }

    return false;
}

int main() {
    vector<vector<int>> v(9, vector<int>(9, 0));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> v[i][j];
        }
    }

    dfs(v, 0, 0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
}
// 64 位输出请用 printf("%lld")