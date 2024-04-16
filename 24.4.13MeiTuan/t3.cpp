#include <iostream>
#include <vector>
using namespace std;

struct node{
    int val;
    int num;
    vector<int> edges;
    node(int ch, int i) : val(ch), num(i) {}
};
typedef struct node* TreeNode;

void dfs(vector<TreeNode>& nodes, int i, int fa, int& res) {
    if (nodes[i]->edges.size() == 1 && nodes[i]->edges[0] == fa) {
        return;
    }
    
    for (auto v : nodes[i]->edges) {
        if (v == fa) continue;
        dfs(nodes, v, i, res);
        nodes[i]->val |= nodes[v]->val;
    }
    if (nodes[i]->val == 3) res++;
}

int main() {
    int n;
    cin >> n;
    vector<TreeNode> nodes(n);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'B') nodes[i] = new node(1, i);
        if (c == 'R') nodes[i] = new node(2, i);
    }
    for (int i = 0; i < n-1; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        nodes[n1-1]->edges.push_back(n2-1);
        nodes[n2-1]->edges.push_back(n1-1);
    }
    int res = 0;
    dfs(nodes, 0, -1, res);
    cout << res << endl;
}
// 64 位输出请用 printf("%lld")