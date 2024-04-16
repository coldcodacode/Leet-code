/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
// };
#include <unordered_map>
#include <utility>
using namespace std;
class Solution {
public:
    unordered_map<TreeNode*, pair<int, int>> dp;
    void dfs(TreeNode* root) {
        if (!root->left && !root->right) {
            dp[root] = make_pair(0, root->val);
            return;
        }
        if (root) {
            int first = 0;
            int second = root->val;
            if (root->left) {
                dfs(root->left);
                first += max(dp[root->left].first, dp[root->left].second);
                second += dp[root->left].first;
            }
            if (root->right) {
                dfs(root->right);
                first += max(dp[root->right].first, dp[root->right].second);
                second += dp[root->right].first;
            }
            dp[root] = make_pair(first, second);
        }
    }
    int rob(TreeNode* root) {
        if (!root) return 0;
        dfs(root);
        return max(dp[root].first, dp[root].second);
    }
};
// @lc code=end

