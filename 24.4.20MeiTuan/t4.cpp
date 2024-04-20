#include <bits/stdc++.h>
using namespace std;
//3
//1 2 2
//1 2
//2 3
struct Node{
    bool val;
    vector<int> edges;
    Node() : val(false) {}
};

pair<int, int> dfs(vector<Node>& nodes, int& ans, int cur, int fa) {
    pair<int, int> ret = make_pair(0, 0);
    if (nodes[cur].val) { // 1
        if (nodes[cur].edges.size() == 1 && nodes[cur].edges[0] == fa) return make_pair(0, 1); 
        for (int i : nodes[cur].edges) {
            if (i == fa) continue;
            pair<int, int> ret_temp;
            ret_temp = dfs(nodes, ans, i, cur);
            ret.first += (ret_temp.first);
            ret.second += ret_temp.second;
        }
    } else { // 2
        if (nodes[cur].edges.size() == 1 && nodes[cur].edges[0] == fa) return make_pair(1, 0); 
        for (int i : nodes[cur].edges) {
            if (i == fa) continue;
            pair<int, int> ret_temp;
            ret_temp = dfs(nodes, ans, i, cur);
            ret.first += (ret_temp.second);
            ret.second += ret_temp.first;
        }
    }
    ans += ret.first*(ret.first-1)/2;
    ans += (ret.first+1)*ret.second;
    cout << ans << ' ';

    return ret;
}

int main() {
    int ans = 0;
    int n;
    cin >> n;
    vector<Node> nodes(n);
    int val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        if (val == 1) {
            nodes[i].val = true;
        }
    }
    int e1, e2;
    for (int i = 0; i < n-1; i++) {
        cin >> e1 >> e2;
        nodes[e1-1].edges.push_back(e2-1);
        nodes[e2-1].edges.push_back(e1-1);
    }

    dfs(nodes, ans, 0, -1);
    // cout << ans;
}