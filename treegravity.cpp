#include <vector>
#include <iostream>
#include <cstring>
#define N 200100
using namespace std;

vector<int> e[N];
int ans = 10000, idx, f[N];
int n;

void dfs(int u, int fa) {
    f[u] = 1;
    int mx = 0;
    for (int v : e[u]) {
        if (v == fa) continue;
        dfs(v, u);
        f[u] += f[v];
        mx = max(mx, f[v]);
    }
    mx = max(mx, n - f[u]);

    if (mx < ans) { ans = mx; idx = u; }
}

void addEdges(int a, int b) {
    e[a].push_back(b);
}

void addUndirectEdges(int a, int b) {
    addEdges(a, b);
    addEdges(b, a);
}

int main () {
    int a, b;
    
    memset(f, 0x1111, sizeof f);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        e[i].clear();
    }
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        addUndirectEdges(a, b);
    }

    dfs(1, -1);
    cout << "ans" << ans << "idx" << idx;
    return 0;
}
