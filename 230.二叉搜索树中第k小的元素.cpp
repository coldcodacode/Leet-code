/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 */
/*
给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。
输入：root = [3,1,4,null,2], k = 1
输出：1
输入：root = [5,3,6,2,4,null,null,1], k = 3
输出：3
提示：

树中的节点数为 n 。
1 <= k <= n <= 104
0 <= Node.val <= 104
 

进阶：如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化算法？*/


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
#include <vector>
#include <iostream>
#include <cstring>
#include <list>
#include <queue>

class Solution {
public:
    // 非递归中序遍历
    // int kthSmallest(TreeNode* root, int k) {
    //     std::stack<TreeNode*> stack;
    //     while (root || !stack.empty()) {
    //         if (root) {
    //             stack.push(root);
    //             root = root->left;
    //         } else {
    //             root = stack.top();
    //             stack.pop();
    //             if (!--k) return root->val;
    //             root = root->right;
    //         }
    //     }
    //     return -1;
    // }

    // 递归中序遍历
    // int ans = 0;
    // void inorder(TreeNode* root, int& k) {
    //     if (!root) return;
    //     inorder(root->left, k);
    //     if (!--k) ans = root->val;
    //     inorder(root->right, k);
    // }
    // int kthSmallest(TreeNode* root, int k) {
    //     // memset(nodes, 0, sizeof(int) * 105);
    //     inorder(root, k);
    //     return ans;
    // }

    // 堆
    void modifyHeap(std::vector<int>& heap, size_t& heap_size) {
        size_t cur = heap_size - 1;
        size_t fa = ((cur+1)>>1)-1;
        int tmp = heap[cur];
        while ( fa >= 0 ) {
            if (heap[fa] >= tmp) {
                break;
            } else {
                heap[cur] = heap[fa];
            }
            cur = fa;
            fa = ((cur+1)>>1)-1;
        }
        heap[cur] = tmp;
    }
    void popTop(std::vector<int>& heap, size_t& heap_size) {
        int tmp = heap[heap_size-1];
        heap_size--;
        size_t cur = 0;
        size_t lchild = ((cur+1)<<1) - 1;
        while ( lchild < heap_size ) {
            if (heap[lchild] > tmp) {
                heap[cur] = heap[lchild];
                cur = lchild;
                lchild = ((cur+1)<<1) - 1;
            } else if (lchild + 1 < heap_size) {
                if (heap[lchild+1] > tmp) {
                    heap[cur] = heap[lchild+1];
                    cur = lchild+1;
                    lchild = ((cur+1)<<1) - 1;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
        heap[cur] = tmp;
    }
    int kthSmallest(TreeNode* root, int k) {
        std::vector<int> heap(k);
        size_t heap_size = 0;
        // bfs
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (heap_size < k) {
                heap[heap_size++] = node->val;
                modifyHeap(heap, heap_size);
            } else {
                if (heap[0] > node->val){
                    popTop(heap, heap_size);
                    heap[heap_size++] = node->val;
                    modifyHeap(heap, heap_size);
                }
            }

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        return heap[0];
    }
};
// @lc code=end

/**
 * @brief 遍历一棵树的基本逻辑
 * flag用来标志第几次访问。第一次访问输出、第二次访问输出、第三次访问输出：对应前序、中序、后序;
 * 每次迭代都要更新下一次要检查哪个结点
 */
while (root) {
    if (root) {
        switch (root->flag)
        {
        case 0:
            root->flag = 1;
            if (root->left) root = root->left;
            break;
        case 1:
            root->flag = 2;
            if (root->right) root = root->right;
            break;
        case 2:
            root->flag = 0;
            cout << root->val;
            root = root->parent;
            break;

        default:
            break;
        }
    } else {
        root = root->parent;
    }
}

/**
 * @brief preorder
 * 栈中保存的节点，他们的右节点需要被检查
 */
/**
 * 入栈表示第一次遇到这个点
 * 出栈表示第二次遇到这个点
*/
while (!stack.empty() || root) {
    if (root) {
        cout << root->val;
        stack.push(root);
        root = root->left;
    } else {
        root = stack.top();
        stack.pop();
        root = root->right;
    } 
} 

while (root) {
    cout << root->val;
    if (!root->right) stack.push(root->right);
    if (!root->left) {
        root = root->left;
    } else {
        if (stack.empty()) break;
        root = stack.top();
        stack.pop();
    }
} 

/**
 * @brief inorder
 * preorder是进栈visit，inorder是出栈visit
 */
while (!stack.empty() || root) {
    if (root) {
        stack.push(root);
        root = root->left;
    } else {
        root = stack.top();
        stack.pop();
        cout << root->val;
        root = root->right;
    } 
} 

/**
 * @brief postorder
 * 三个状态表示了节点三次访问的时机：
 * 未进栈——第一次访问;
 * 已进栈 && hasBeenVisitedTwice==false——第二次访问;
 * 已进栈 && hasBeenVisitedTwice==true———第三次访问。
 * 
 * return nullptr的意义是 当前root指向的子树检查完毕
 * 
 * stack栈顶保存的是，如果当前root指向的子树检查完毕，下一个检查点
 */
while (!stack.empty() || root) {
    if (root) {
        stack.push(root);
        root->hasBeenVisitedTwice = false;
        root = root->left;
    } else {
        root = stack.top();
        if (root->hasBeenVisitedTwice) {
            cout << root->val;
            stack.pop();
            root = nullptr;
        } else {
            root->hasBeenVisitedTwice = true;
            root = root->right;
        }
    } 
} 

/**
 * @brief 只用一个变量一个栈实现后序遍历。
 * return nullptr的意义是 当前栈顶指向的子树检查完毕
 */
while (!stack.empty() || root) {
    if (root) {
        stack.push(root);
        pr = root->right;
        root = root->left;
        if (!root) root = pr;
    } else {
        root = stack.top();
        stack.pop();
        cout << root->val;

        if (stack.empty()) break;
        if (stack.top()->right == root) {
            root = nullptr;
        } else {
            root = stack.top()->right;
        }
    } 
}