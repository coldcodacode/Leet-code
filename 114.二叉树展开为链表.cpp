/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */
/*
给你二叉树的根结点 root ，请你将它展开为一个单链表：

展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
展开后的单链表应该与二叉树 先序遍历 顺序相同。
 

示例 1：


输入：root = [1,2,5,3,4,null,6]
输出：[1,null,2,null,3,null,4,null,5,null,6]
示例 2：

输入：root = []
输出：[]
示例 3：

输入：root = [0]
输出：[0]
 

提示：

树中结点数在范围 [0, 2000] 内
-100 <= Node.val <= 100
 

进阶：你可以使用原地算法（O(1) 额外空间）展开这棵树吗？*/
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
using namespace std;

class Solution {
public:
    // dfs
    // TreeNode* dfs(TreeNode* root) {
    //     if (!root) return nullptr;
    //     TreeNode* p = root;
    //     TreeNode* pr = root->right;
    //     TreeNode* pl = root->left;
    //     p->left = nullptr;
    //     p->right = dfs(root->left);
    //     while(p->right) {
    //         p = p->right;
    //     }
    //     p->right = dfs(pr);
    //     return root;
    // }
    // void flatten(TreeNode* root) {
    //     dfs(root);
    // }

    // 迭代：这道题从dfs解决办法入手，再转为迭代法，
    // 实现了用栈模拟递归过程。每当递归root->left，
    // 都需要用栈记录root->right。当root->left递归
    // 返回时，从栈中弹出root->right，递归root->right。
    void flatten(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(!s.empty() || root) {
            if (root) {
                s.push(root->right);
                root->right = root->left;
                root->left = nullptr;
                root = root->right;
            } else {
                root = s.top();
                s.pop();
                while (p->right) {
                    p = p->right;
                }
                p->right = root;
            }
        }
    }
};
// @lc code=end

