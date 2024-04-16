/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    // target < nums[mid]: 
    //      nums[l] < nums[mid] && nums[l] <= target 
    //      nums[l] > nums[mid]
    // target > nums[mid]:
    //      nums[l] > nums[mid] && target >= nums[l]
    // lo = l. hi = mid - 1;

    // in other words,
    //                        target < nums[mid] < nums[l]
    //             nums[l] <= target < nums[mid]
    // nums[mid] < nums[l] <= target
    // in these situation, check the left block,
    // otherwise, check the right block
    static int search(const vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (target == nums[mid]) return mid;
            if (target < nums[mid] ^ nums[mid] < nums[lo] ^ nums[lo] <= target) {
                lo = mid + 1;
                hi = hi;
            }else {
                lo = lo;
                hi = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end

