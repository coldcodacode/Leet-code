/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */

// @lc code=start
#include <stack>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     int visit;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// struct TreeNode {
//     int val;
//     int visit;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr){
            return true;
        }else if(p == nullptr || q == nullptr){
            return false;
        }
        stack<struct TreeNode*> sp;
        stack<struct TreeNode*> sq;
        struct TreeNode* temp1 = nullptr;
        struct TreeNode* temp2 = nullptr;
        sp.push(p);
        sq.push(q);
        while(!sp.empty()){
            if (sp.top() == nullptr && sq.top() == nullptr){
                sp.pop();
                sq.pop();
                if (!sp.empty() ){
                    temp1 = sp.top()->right;
                    temp2 = sq.top()->right;
                    sp.pop();
                    sq.pop();
                    sp.push(temp1);
                    sq.push(temp2);
                }
            }else if (sp.top() == nullptr || sq.top() == nullptr){
                return false;
            }else if (sp.top()->val == sq.top()->val){
                sp.push(sp.top()->left);
                sq.push(sq.top()->left);
            }else {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

