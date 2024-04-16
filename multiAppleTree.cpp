#include <queue>
#include <list>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <cstring>
using namespace std;

int n, q;
vector<pair<int, int>> e[101];

void addEdge(int n1, int n2, int apple) {
    e[n1].push_back(make_pair(n2, apple));
}

void addEdges(int n1, int n2, int apple) {
    addEdge(n1, n2, apple);
    addEdge(n2, n1, apple);
}

void dfs(vector<vector<int>>& dp, int i, int fa, int branch) {
    if (branch <= 0) {
        return;
    }
    if (e[i].size() <= 1) return;
    int left = -1, right;
    int leftApple, rightApple;
    for (auto v : e[i]) {
        if (v.first == fa) continue;
        if (left == -1) { 
            left = v.first;
            leftApple = v.second;
        }
        right = v.first;
        rightApple = v.second;
        dfs(dp, v.first, i, branch-1);

        // dp[i][branch] = max(dp[i][branch], dp[v.first][branch-1] + v.second);
        if (branch > 0 && dp[i][branch] < dp[v.first][branch-1] + v.second) {
            dp[i][branch] = dp[v.first][branch-1] + v.second;
            branch--;
        } 
    }
    // dfs(dp, left, i, branch-2);
    // dfs(dp, right, i, branch-2);
    // if (branch > 1) 
    //     dp[i][branch] = max(dp[i][branch], dp[left][branch-2] + dp[right][branch-2] + leftApple + rightApple);
}

int main () {
    cin >> n >> q;
    int n1, n2, apple;
    for (int i = 0; i < n-1; i++) {
        cin >> n1 >> n2 >> apple;
        addEdges(n1, n2, apple);
    }

    vector<vector<int>> dp(n+1, vector<int>(q+1, 0));

    dfs(dp, 1, -1, q);

    cout << dp[1][q] << endl;
}