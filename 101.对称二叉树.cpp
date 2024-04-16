/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};
class Solution {
public:
    // 迭代
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> ql;
        queue<TreeNode*> qr;
        if (!root->left && !root->right) {return true;}
        if (!root->left || !root->right) {return false;}
        // if (root->left->val != root->right->val) return false;
        ql.push(root->left);
        qr.push(root->right);

        while (!ql.empty()) {
            TreeNode* l = ql.front();
            ql.pop();
            TreeNode* r = qr.front();
            qr.pop();
            if (l->val != r->val) return false;

            if (!l->left && !r->right) ;
            else if (!l->left || !r->right) return false;
            else {
                ql.push(l->left);
                qr.push(r->right);
            }

            if (!l->right && !r->left) ;
            else if (!l->right || !r->left) return false;
            else {
                ql.push(l->right);
                qr.push(r->left);
            }
        }
        return true;
    }
};
// @lc code=end

