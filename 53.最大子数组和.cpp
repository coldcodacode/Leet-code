/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
// typedef unsigned int size_t;
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        size_t l = 0, r = 0;
        size_t size_nums = nums.size();
        int cur = 0;
        int ret = nums[l];
        while(r < size_nums){
            
            if (nums[r] + cur < 0){
                // l = r + 1;
                cur = 0;
                ret = ret > nums[r] ? ret : nums[r];
            }else {
                cur += nums[r];
                ret = ret > cur ? ret : cur;
            }
            r++;
        } 
        return ret;     
    }
};
// @lc code=end

