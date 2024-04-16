/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stack>
using namespace std;
// struct TreeNode{
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x): val(x), left(NULL), right(NULL){}
// };
class Solution {

public:
    bool dfs(TreeNode* root, TreeNode* target, stack<TreeNode*>& s){
        if (!root){
            return false;
        }
        s.push(root);
        if (root->val != target->val){
            if (dfs(root->left, target, s)) return true;
            if (dfs(root->right, target, s)) return true;
            s.pop();
            return false;
        }else {
            return true;
        }
    }
    TreeNode* findLowest(stack<TreeNode*>& sp, stack<TreeNode*>& sq){
        int spNum = sp.size();
        int sqNum = sq.size();
        while(!sp.empty() && !sq.empty()){
            if (spNum > sqNum){
                sp.pop();
                spNum--;
            }else if (spNum < sqNum){
                sq.pop();
                sqNum--;
            }else{
                if (sp.top() != sq.top()){
                    sp.pop();
                    sq.pop();
                    spNum--;
                    sqNum--;
                }else{
                    break;
                }
            }
        }
        return sp.top();
    }
    TreeNode* solution1(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> sp;
        stack<TreeNode*> sq;
        dfs(root, p, sp);
        dfs(root, q, sq);
        return findLowest(sp, sq);
    }


    /**
     * @brief return the lca of p and q
     * 
     * @param root 
     * @param p 
     * @param q 
     * @return TreeNode* 
     */
    TreeNode* solution2(TreeNode* root, TreeNode* p, TreeNode* q){
        if (root == nullptr){
            return root;
        }
        if (root == p){
            return root;
        }
        if (root == q){
            return root;
        }

        TreeNode* flag_left = solution2(root->left, p, q);
        TreeNode* flag_right = solution2(root->right, p, q);
        if (! flag_left && !flag_right){
            return nullptr;
        }else if (flag_left && flag_right){
            return root;
        }else if (flag_right){
            return flag_right;
        }else{
            return flag_left;
        }
    }

    TreeNode *lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        return solution2(root, p, q);
    }
};
// @lc code=end

