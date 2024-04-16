/*
 * @lc app=leetcode.cn id=1382 lang=cpp
 *
 * [1382] 将二叉搜索树变平衡
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     int height;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <vector>
#include <cmath>
#include <stack>
#include <iostream>
using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
class Solution {
public:

    TreeNode* balanceBST(TreeNode* root) {
        if (!root){
            return root;
        }
        root->left = balanceBST(root->left);
        root->right = balanceBST(root->right);

        int balance = getHeight(root->left) - getHeight(root->right);
        if (balance > 1){
            if (getHeight(root->left->left) < getHeight(root->left->right))
                root->left = leftRotate(root->left);
            root = rightRotate(root);

            root->right = balanceBST(root->right);
        }else if (balance < -1){
            if (getHeight(root->right->right) < getHeight(root->right->left))
                root->right = rightRotate(root->right);
            root = leftRotate(root);

            root->left = balanceBST(root->left);
        }

        return root;
    }

    TreeNode* leftRotate(TreeNode* root){
        if (root == nullptr || root->right == nullptr){
            return root;
        }
        TreeNode* right = root->right;
        root->right = right->left;
        right->left = root;
        return right;
    }

    TreeNode* rightRotate(TreeNode* root){
        if (root == nullptr || root->left == nullptr){
            return root;
        }
        TreeNode* left = root->left;
        root->left = left->right;
        left->right = root;
        return left;
    }

    int getHeight(TreeNode* root){
        if (!root) return 0;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }
};
// @lc code=end

