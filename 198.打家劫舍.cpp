/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
// 最优子结构的性质：
// 最优序列本身的子序列也是子问题的最优解
// dp[i] = max( dp[i], max( dp[i - 2] + nums[i], dp[i - 1] ) )
// dp[i] 表示打劫前i个屋子的最高金额
// dp[0] = 0 dp[1] = nums[1]
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n + 5];
        memset(dp, 0, sizeof dp);
        dp[1] = nums[0];
        for (int i = 2; i <= n; ++i){
            dp[i] = max(dp[i], max(dp[i - 2] + nums[i - 1], dp[i - 1]));
        }
        return dp[n];
    }
};
// @lc code=end

