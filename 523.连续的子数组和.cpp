/*
 * @lc app=leetcode.cn id=523 lang=cpp
 *
 * [523] 连续的子数组和
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> preSum(n+1, 0);
        for (int i = 0; i < n; i++) {
            preSum[i+1] = (preSum[i] + nums[i]) % k;

        }

        unordered_map<int, int> hashmap;
        for (int i = 0; i <= n; i++) {
            auto it = hashmap.find(preSum[i]);
            if (it != hashmap.end()) { // 哈希表不能同时存key值相同的两个pair
                if (i - it->second >= 2) 
                    return true;
            }
            else 
                hashmap[preSum[i]] = i;
        }
        return false;
    }
};
// @lc code=end

