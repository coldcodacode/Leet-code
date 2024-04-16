/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// #include <iostream>
// #include <vector>
// #include <stack>
// #include <utility>
// using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// };

class Solution {
public:
    // 性质：从根出发，找到的深度最大的点，一定在最长链上。
    // 具体实现：两次dfs
    // int ans = 0;
    // vector<int> e[10010];
    // TreeNode* deepestNode(TreeNode* root) {
    //     stack<pair<TreeNode*, int>> s;
    //     int depth = 0;
    //     TreeNode* ptr = root;
    //     int maxDepth = 0;
    //     TreeNode *maxIndex = nullptr;

    //     while (ptr!= nullptr || !s.empty()) {
    //         while (ptr != nullptr) {
    //             depth++;
    //             s.push(make_pair(ptr, depth));
    //             ptr = ptr->left;
    //         }
    //         pair<TreeNode*, int>top = s.top();
    //         s.pop();
    //         ptr = top.first->right;
    //         depth = top.second;

    //         if (maxDepth < depth) {
    //             maxDepth = depth;
    //             maxIndex = top.first;
    //         }
    //     } 
    //     return maxIndex;
    // }

    // int dfs(int val, int fa){
    //     int length = 0;
    //     int chiLength = 0;
    //     for (auto v : e[val]) {
    //         if (v == fa) continue;
    //         chiLength = max(chiLength, dfs(v, val));
    //     }
    //     return chiLength + 1;
    // }

    // void addDirectEdge(int a, int b) {
    //     e[a].push_back(b);
    // }

    // void addUndirectEdge(int a, int b) {
    //     addDirectEdge(a, b);
    //     addDirectEdge(b, a);
    // }

    // void addEdge(TreeNode* root) {
    //     if (!root) return; 
    //     if (root->left) {
    //         addUndirectEdge(root->val, root->left->val);
    //         addEdge(root->left);
    //     }
    //     if (root->right) {
    //         addUndirectEdge(root->val, root->right->val);
    //         addEdge(root->right);
    //     }
    // }

    // int diameterOfBinaryTree(TreeNode* root) {
    //     TreeNode *deepest = deepestNode(root);
    //     addEdge(root);
    //     ans = dfs(deepest->val, -1) - 1;
    //     return ans;
    // }

    // 树型dp
    int dfs(TreeNode* root, int& height) {
        int leftHeight;
        int rightHeight;
        int leftAns;
        int rightAns;

        if (root->left) {
            leftAns = dfs(root->left, height);
            leftHeight = height;
        }else {
            leftHeight = -1;
            leftAns = 0;
        }

        if (root->right) {
            rightAns = dfs(root->right, height);
            rightHeight = height;
        }else {
            rightHeight = -1;
            rightAns = 0;
        }

        height = max(leftHeight, rightHeight) + 1;
        return max(max(leftAns, rightAns), leftHeight + rightHeight + 2); 
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int height;
        return dfs(root, height);
    }
};


// @lc code=end

