/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
using namespace std;
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        return helper(1, n);
    }

    vector<TreeNode *> helper(int h, int t)
    {
        vector<TreeNode *> v;
        if (h > t)
        {
            v.push_back(nullptr);
            return v;
        }
        for (int i = h; i <= t; ++i)
        {
            // vector<TreeNode *> myVector = helper(h, i - 1);
            // for (vector<TreeNode *>::iterator it = myVector.begin(); it != myVector.end(); ++it)
            // {
                
            // }
            for (const auto &ele : helper(h, i - 1))
            {
                for (const auto &ele1 : helper(i + 1, t))
                {
                    struct TreeNode* root = new TreeNode(i, ele, ele1);
                    v.push_back(root);
                }
            }
        }
        return v;
    }
};
// @lc code=end
