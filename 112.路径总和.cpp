/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <stack>
using namespace std;
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        stack<TreeNode*> s;
        TreeNode* pr = nullptr;
        while (root || !s.empty()) {
            if (root) {
                s.push(root);
                targetSum -= root->val;
                pr = root->right;
                root = root->left;
                
                if (!root) root = pr;
            } else {
                root = s.top();
                s.pop();
                targetSum += root->val;
                if (!root->left && !root->right) {
                    if  (targetSum == root->val) {
                        return true;
                    }
                }
                if (s.empty()) break;
                if (s.top()->left == root) {
                    root = s.top()->right;
                } else {
                    root = nullptr;
                }
            }
        }
        return false;
    }
};
// @lc code=end

