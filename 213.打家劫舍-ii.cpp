/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    // 因为不构成父子问题结构，所以直接dp失效。
    // 通过转换成打家劫舍i问题，求解。
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> dp1(n-1);
        vector<int> dp2(n-1);

        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n-1; i++) {
            dp1[i] = max(dp1[i-1], dp1[i-2] + nums[i]);
        }

        dp2[0] = nums[1];
        dp2[1]= max(nums[2], nums[1]);
        for (int i = 3; i < n; i++) {
            dp2[i-1] = max(dp2[i-2], dp2[i-3] + nums[i]);
        }     

        return max(dp1[n-2], dp2[n-2]);
    }
};
// @lc code=end

