#include <stack>
#include <queue>
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* dfs(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* p = root;
        TreeNode* pr = root->right;
        // TreeNode* pl = root->left;
        // p->left = nullptr;
        p->right = dfs(root->left);
        while(p->right) {
            p = p->right;
        }
        p->right = dfs(pr);
        return root;
    }
    void flatten(TreeNode* root) {
        dfs(root);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            root = q.front();
            q.pop();
            cout << root->val << ' ';
            if (root->left) q.push(root->left);
            if (root->right) q.push(root->right);
        }
    }
};

int main() {
    TreeNode* node_3 = new TreeNode(3);
    TreeNode* node_4 = new TreeNode(4);
    TreeNode* node_6 = new TreeNode(6);
    TreeNode* node_2 = new TreeNode(2, node_3, node_4);
    TreeNode* node_5 = new TreeNode(5, nullptr, node_6);
    TreeNode* node_1 = new TreeNode(1, node_2, node_5);
    Solution().flatten(node_1);
}