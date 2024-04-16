/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
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
#include <stack>
#include <algorithm>
#include <iostream>

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
    int branchLongestPath(TreeNode *root)
    {
        stack<struct TreeNode *> s;
        stack<bool> s_flag;
        int max = 0;
        int temp_max = 0; // the temporary longest path length
        s.push(root);
        s_flag.push(true);
        while (!s.empty())
        { // postorder
            while (s.top()->left && s.top()->val == s.top()->left->val)
            {
                s.push(s.top()->left);
                s_flag.push(true);
                temp_max++;
            }
            // the left child of node which is at top cant be added
            while (!s_flag.empty())
            {
                if (s.top()->right && s.top()->val == s.top()->right->val)
                { // the right child of node which is at top can be added
                    s.push(s.top()->right);

                    s_flag.pop();
                    s_flag.push(false);
                    s_flag.push(true);
                    temp_max++;
                    break;
                }
                else
                { // right child of the node which is at top cant be added
                    s_flag.pop();
                    s_flag.push(false);
                    if (temp_max > max)
                    {
                        max = temp_max;
                    }
                    while (!s_flag.empty() && !s_flag.top())
                    {
                        s.pop();
                        s_flag.pop();
                    }
                    temp_max = s.size() - 1;
                }
            }
        }
        return max;
    }
    int longestUnivaluePath(TreeNode *root)
    {
        int root_max = 0;  // including the root, the longest path length
        int left_max = 0;  // including the root, the longest left branch length
        int right_max = 0; // including the root, the longest right branch length
        if (!root)
        {
            return 0;
        }
        stack<struct TreeNode *> s;
        if (root->left && root->val == root->left->val)
        {
            left_max = branchLongestPath(root->left) + 1;
        }
        if (root->right && root->right->val == root->val)
        {
            right_max = branchLongestPath(root->right) + 1;
        }
        root_max = left_max + right_max;
        cout << root_max << endl;
        int left = longestUnivaluePath(root->left);
        int right = longestUnivaluePath(root->right);
        return max({root_max, left, right});
    }
};
// @lc code=end