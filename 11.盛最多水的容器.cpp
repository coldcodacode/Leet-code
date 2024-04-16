/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include <vector>
using namespace std;
// 双指针
// maxarea[i][j] = max( min(height[i], height[j]) * (j - i), maxarea[i+1][j], maxarea[i][j-1] )
// 根据上式复杂度是n方，相当于所有情况全计算一遍
// if (height[i] < height[j]) 以i为左边界的所有容器的最大容量当且仅当右边界为j时取到。
// 这时可以缩减问题规模（即可以i++）
// 初始状态是指针指向两侧
class Solution {
public:
    int getArea(vector<int>& height, vector<int>::iterator l, vector<int>::iterator r){
        if (*l < *r){
            return *l * (int)(r - l);
        }else{
            return *r * (int)(r - l);
        }
    }
    int maxArea(vector<int>& height) {
        vector<int>::iterator l;
        vector<int>::iterator r;
        l = height.begin();
        r = height.end();
        --r;
        int max = 0;
        int tmp;
        while(l != r){
            tmp = getArea(height, l , r);
            max = max > tmp ? max : tmp; 
            if (*l < *r){
                l++;
            }else{
                r--;
            }
        }
        return max;
    }
};
// @lc code=end

