/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */
/*给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

 

示例 1：

输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。
示例 2：

输入：nums = [1,2,3,5]
输出：false
解释：数组不能分割成两个元素和相等的子集。
 

提示：

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/
// @lc code=start
#include <vector>
using namespace std;
/**
 * @brief dp[i][j]: condition that target equals to j,
 * if we can choose some numbers which indice less than i, their sum equals to j, then dp[i][j] equals to true; 
 * otherwise false;
 * 0,1背包问题，找到递推表达式是关键
 * 引用评论区中的一段话，想来很有道理：
 * “一个写DP的经验，总结来说就是DFS->记忆化搜索->DP：
 * DP的题目没思路时，首先看能不能dfs写出来，此时大概率会超时，
 * 超时的原因就是重复搜索某些状态（子问题），
 * 此时观察dfs的参数以及dfs的调用方式，这俩一般都暗示出了子问题，
 * 因此可以推断出重复搜索了什么状态，可以利用它们改成记忆化搜索；
 * 最后，这些重复搜索的状态又是dp的状态，dfs的调用方式又表明了状态转移，
 * 再改成dp版本就可以了。”
 */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        int target = 0;
        for (auto it : nums) 
        {
            target += it;
        }
        if (target & 0x1) {
            return false;
        }
        target /= 2;
        vector<bool> dp(target+1, false);
        dp[0] = true;
        for (int i = 0; i < size; i++) {
            for (int j = target; j > -1; j--) {
                dp[j] = dp[j] || ((j -nums[i] < 0) ? false: (dp[j - nums[i]]));
            }
        }

        return dp[target];
    }
};
// @lc code=end

