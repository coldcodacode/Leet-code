/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
#include <iostream>
using namespace std;
// struct TreeNode{
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
class Solution {
public:
    TreeNode* cutLowerLeft(TreeNode *root, int left){
        if (!root) return nullptr;
        if (root->val > left){
            root->left = cutLowerLeft(root->left, left);
            return root;
        }else if (root->val < left){
            return cutLowerLeft(root->right, left);
        }else{
            root->left = nullptr;
            return root;
        }
    }
    TreeNode* cutHigherRight(TreeNode *root, int right){
        if (!root) return nullptr;
        if (root->val < right){
            root->right = cutHigherRight(root->right, right);
            return root;
        }else if (root->val > right){
            return cutHigherRight(root->left, right);
        }else{
            root->right = nullptr;
            return root;
        }
    }
    void printTree(TreeNode *root){
        if(root){
            cout << root->val << " ";
            printTree(root->left);
            printTree(root->right);
        }else{
            cout << "null ";
        }
        
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        root = cutLowerLeft(root, low);
        // printTree(root);
        // cout << endl;
        root = cutHigherRight(root, high);
        // printTree(root);
        // cout << endl;
        return root;
    }
};
// @lc code=end

