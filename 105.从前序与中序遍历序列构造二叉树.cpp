/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */
/*
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

 

示例 1:


输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
输出: [3,9,20,null,null,15,7]
示例 2:

输入: preorder = [-1], inorder = [-1]
输出: [-1]
 

提示:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder 和 inorder 均 无重复 元素
inorder 均出现在 preorder
preorder 保证 为二叉树的前序遍历序列
inorder 保证 为二叉树的中序遍历序列*/
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
class Solution {
public:
    // dfs
    // TreeNode* dfs(vector<int>& preorder, vector<int>&inorder, int pre_left, int pre_right, int in_left, int in_right) {
    //     if (pre_left > pre_right) return nullptr;
    //     TreeNode* root = new TreeNode(preorder[pre_left]);
    //     int count = 0;
    //     int i = in_left;
    //     for ( ; i <= in_right; i++, count++) {
    //         if (inorder[i] == preorder[pre_left]) break;
    //     }
    //     if (pre_left != pre_right) {
    //         root->left = dfs(preorder, inorder, pre_left+1, pre_left+count, in_left, i-1);
    //         root->right = dfs(preorder, inorder, pre_left+count+1, pre_right, i+1, in_right);
    //     }
    //     return root;
    // }
    // TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    //     int m = preorder.size();
    //     int n = inorder.size();

    //     return dfs(preorder, inorder, 0, m-1, 0, n-1);

    // }

    // 迭代
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        stack<TreeNode*> stk;
        TreeNode *root = new TreeNode(preorder[0]);
        stk.push(root);
        int inorderIndex = 0;
        for (int i = 1; i < preorder.size(); i++) {
            TreeNode* node = stk.top();
            int preorderVal = preorder[i];
            if (node->val != inorder[inorderIndex]) {
                node->left = new TreeNode(preorderVal);
                stk.push(node->left);
            } else {
                while (!stk.empty() && inorder[inorderIndex] == stk.top()->val) {
                    node = stk.top();
                    stk.pop();
                    inorderIndex++;
                }
                node->right = new TreeNode(preorderVal);
                stk.push(node->right);
            }
        }
        
        return root;
    }
};
// @lc code=end

