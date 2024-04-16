/*
 * @lc app=leetcode.cn id=440 lang=cpp
 *
 * [440] 字典序的第K小数字
 */

// @lc code=start

#include <math.h>
using namespace std;
class Solution {
public:
    int findKthNumber(int n, int k) {
        // 心中有树
        // 完全二叉树前序的另一种做法
        int cur = 1;
        
        while (k > 0)
        {
            long long left = cur;
            long long right = cur + 1;
            int node_num = 0;
            
            while (left <= n) // 统计树中每一层的节点个数
            {
                node_num += min(right, (long long)(n+1)) - left;
                left *= 10;
                right *= 10;
            }
            
            if (node_num < k) // 向后查找
            {
                k -= node_num;
                cur++;
            }
            else // 进入子树查找
            {
                k--;
                if (k == 0){
                    return cur;
                }
                cur *= 10;
            }
        }
        
        return 1;       
    }
};

// @lc code=end

