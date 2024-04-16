/*
 * @lc app=leetcode.cn id=590 lang=c
 *
 * [590] N 叉树的后序遍历
 */

// @lc code=start
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#define MAX_NUM 10000
typedef struct{
    struct Node* knot;
    int flag;
}stack;
struct Node {
    int val;
    int numChildren;
    struct Node** children;
};

void LRD(int *res,struct Node* root,int *returnSize)
{
    stack s[MAX_NUM];//建立栈模拟非递归
    int top = -1;//栈顶位置
    int index = 0;//res数组的游标位置
    while (root != NULL || top != -1)
    {
        if (top == -1 || root != s[top].knot)
        {
            s[++top].knot = root;
        }
        s[top].flag++;
        if (s[top].flag <= root->numChildren)
        {
            int pos = s[top].flag - 1;
            root = root->children[pos];
        }
        else
        {
            res[index++] = s[top].knot->val;
            s[top--].flag = 0;//变量flag记录的值与树中每个结点相关,所以结点出栈,flag归零
            if (top != -1)
            {
                root = s[top].knot;
            }
            else
            {
                root = NULL;
            }
        }
    }
    *returnSize = index;
}

int* postorder(struct Node* root, int* returnSize) {
    int* res=(int *)malloc(sizeof(int) * MAX_NUM);
    LRD(res,root,returnSize);
    return res;
}
// @lc code=end

