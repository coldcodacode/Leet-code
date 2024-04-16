/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
#include <utility>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector<int>> ans(2000, vector<int>(0));
        queue<pair<TreeNode*, int>> q;
        int stair = 0;
        TreeNode *ptr = root;
        q.push(make_pair(root, stair));
        while (!q.empty()) {
            pair<TreeNode*, int> top = q.front();
            q.pop();
            stair = top.second;
            ptr = top.first;
            ans[stair].push_back(ptr->val);
            if (ptr->left) {
                q.push(make_pair(ptr->left, stair + 1));
            }
            if (ptr->right) {
                q.push(make_pair(ptr->right, stair + 1));
            }
        }
        ans.resize(stair+1);
        return ans;
    }
};
// @lc code=end

