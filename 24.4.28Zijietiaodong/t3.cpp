#include <bits/stdc++.h>
using namespace std;

// 并查集 --最后几秒提交，编译没过，原因是变量命名重复了 你妈的
class DSU {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;

public:
    int find(int x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
            rank[x] = 0;
            return x;
        }
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else {
            parent[py] = px;
            if (rank[px] == rank[py]) {
                rank[px]++;
            }
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};


int main() {
    int n, m;
    cin >> n >> m;
    
    DSU dsu;
    vector<vector<char>> matrix(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            matrix[i][j] = c;
            if (c == '.') {
                dsu.parent[i*m+j] = i*m+j;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '.') {
                if (i-1>=0 && matrix[i-1][j] == '.') dsu.unite(i*m+j, (i-1)*m+j);
                if (j-1>=0 && matrix[i][j-1] == '.') dsu.unite(i*m+j, (i)*m+j-1);
                if (i+1<n && matrix[i+1][j] == '.') dsu.unite(i*m+j, (i+1)*m+j);
                if (j+1<m && matrix[i][j+1] == '.') dsu.unite(i*m+j, (i)*m+j+1);
            }
        }
    }

    unordered_set<int> set;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '.') {
                set.insert(dsu.find(i*m+j));
            }
        }
    }

    cout << set.size() << endl;
    int minus = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '#') {
                int d1 = -1, d2 = -1, d3 = -1, d4 = -1;
                unordered_set<int> tool;
                if (i-1>=0 && matrix[i-1][j] == '.') {
                    tool.insert(dsu.find((i-1)*m+j));
                }
                if (j-1>=0 && matrix[i][j-1] == '.') {
                    tool.insert(dsu.find((i)*m+j-1));
                }
                if (i+1<n && matrix[i+1][j] == '.') {
                    tool.insert(dsu.find((i+1)*m+j));
                }
                if (j+1<m && matrix[i][j+1] == '.') {
                    tool.insert(dsu.find((i)*m+j+1));
                }
                minus = max(minus, (int)tool.size()-1);
            }
        }
    }
    
    cout << set.size()-minus << endl;
}