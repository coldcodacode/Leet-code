#include <vector>
#include <iostream>

using namespace std;
int m, n;

int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& visited) {
    if (j == 0) return -1;

    if (j == n-1) return 0;
    visited[i][j] = 1;
    int res = 0;
    int ret = 0x7fffffff;

    if (j+1 < n && visited[i][j+1] != 1) {
        if (matrix[i][j+1] == 1) {
            res = dfs(i, j+1, matrix, visited);
            if (res != -1) {
                ret = min(ret, res+1);
                visited[i][j] = 0;
                return ret;
            }
        }
    }

    if (i+1 < m && visited[i+1][j] != 1) {
        if (matrix[i+1][j] == 1) {
            res = dfs(i+1, j, matrix, visited);
            if (res != -1) ret = min(ret, res+1);
        }
    }
    if (i-1 > -1 && visited[i-1][j] != 1) {
        if (matrix[i-1][j] == 1) {
            res = dfs(i-1, j, matrix, visited);
            if (res != -1) ret = min(ret, res+1);
        }
    }
    
    if (j-1 > -1 && visited[i][j-1] != 1) {
        if (matrix[i][j-1] == 1) {
            res = dfs(i, j-1, matrix, visited);
            if (res != -1) ret = min(ret, res+1);
        }
    }

    visited[i][j] = 0;
    if (ret != 0x7fffffff) return ret;
    else return -1;
}

int main() {
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    if (n == 1) {
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] != 0) { cout << 0 << endl; return 0;}
        }
        cout << -1 << endl;
        return -1;
    }

    int res = 0;
    int ret = 0x7fffffff;
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) continue;
        if (matrix[i][1] == 0) continue;

        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[i][0] = 1;
        res = dfs(i, 1, matrix, visited);
        if (res != -1) ret = min(res+1, ret);
        // cout << "echo" << res << '\n';
    }

    if (ret == 0x7fffffff) { cout << -1 << endl; }
    else { cout << ret << endl; }


}