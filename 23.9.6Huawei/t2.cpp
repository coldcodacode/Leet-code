#include <vector>
#include <iostream>

using namespace std;
vector<vector<int>> matrix;
int m, n;

int dfs(int i, int j, vector<vector<int>>& visited, int state) {
    visited[i][j] = 1;
    int res = 0;

    if (i + 1 < m && visited[i+1][j] != 1) {
        if (state == 0 && matrix[i+1][j] < matrix[i][j]) {
            res = max(res, 1 + dfs(i+1, j, visited, state^1));
        }else if (state == 1 && matrix[i+1][j] > matrix[i][j]) {
            res = max(res, 1 + dfs(i+1, j, visited, state^1));
        }
    } 
    if (i - 1 > -1 && visited[i-1][j] != 1) {
        if (state == 0 && matrix[i-1][j] < matrix[i][j]) {
            res = max(res, 1 + dfs(i-1, j, visited, state^1));
        }else if (state == 1 && matrix[i-1][j] > matrix[i][j]) {
            res = max(res, 1 + dfs(i-1, j, visited, state^1));
        }
    } 
    if (j + 1 < n && visited[i][j+1] != 1) {
        if (state == 0 && matrix[i][j+1] < matrix[i][j]) {
            res = max(res, 1 + dfs(i, j+1, visited, state^1));
        }else if (state == 1 && matrix[i][j+1] > matrix[i][j]) {
            res = max(res, 1 + dfs(i, j+1, visited, state^1));
        }
    }  
    if (j - 1 > -1 && visited[i][j-1] != 1) {
        if (state == 0 && matrix[i][j-1] < matrix[i][j]) {
            res = max(res, 1 + dfs(i, j-1, visited, state^1));
        }else if (state == 1 && matrix[i][j-1] > matrix[i][j]) {
            res = max(res, 1 + dfs(i, j-1, visited, state^1));
        }
    }

    return res;
}

int main() {
    cin  >> m >> n;
    matrix.resize(m);
    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            vector<vector<int>> visited1(m, vector<int>(n,0));
            vector<vector<int>> visited2(m, vector<int>(n,0));
            res = max(dfs(i, j, visited1, 0), dfs(i, j, visited2, 1));
        }
    }
    cout << res << endl;
    return res;
}