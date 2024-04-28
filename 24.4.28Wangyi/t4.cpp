#include <bits/stdc++.h>
using namespace std;

struct Node {
    vector<pair<int, int>> edges;
    Node() : edges() {}
};

class Solution{
public:
    void dfs(int cur, int fa, int cost) {
        if (visited.find(cur) != visited.end()) {
            return;
        }
        visited.insert(cur);
        tempCost += cost;
        bool record = hasE;
        if (cur == e) {
            hasE = true;
        }
        if (cur == t) {
            if (hasE) minCost = min(minCost, tempCost);
            visited.erase(cur);
            tempCost -= cost;
            hasE = record;
            return;
        }
        for (auto& edge : nodes[cur]->edges) {
            if (edge.first == fa) {
                continue;
            }
            dfs(edge.first, cur, edge.second);
        }
        
        visited.erase(cur);
        tempCost -= cost;
        hasE = record;
        return;
    }
    int getMinCost() {
        return minCost;
    }
public:
    void addEdge(int n1, int n2, int weight) {
        nodes[n1]->edges.push_back(make_pair(n2, weight));
        nodes[n2]->edges.push_back(make_pair(n1, weight));
    }
    Solution() : nodes() {}
    Solution(int n, int e, int t) : visited(), hasE(false), tempCost(0), minCost(INT_MAX) {
        this->e = e;
        this->t = t;
        for (int i = 0; i < n; i++) {
            nodes.push_back(new Node());
        }
    } 
private:
    vector<Node*> nodes;
    unordered_set<int> visited;
    bool hasE;
    int tempCost;
    int minCost;
    int e, t;
};

int main () {
    int n, m, s, e, t;
    cin >> n >> m >> s >> e >> t;
    Solution sol(n, e-1, t-1);
    
    for (int i = 0; i < m; i++) {
        int n1, n2, weight;
        cin >> n1 >> n2 >> weight;
        sol.addEdge(n1-1, n2-1, weight);
    }

    sol.dfs(s-1, -1, 0);
    cout << sol.getMinCost() << endl;
}