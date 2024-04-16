/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    // wrong answer: integer might be negative
    // int subarraySum(vector<int>& nums, int k) {
    //     int size = nums.size();
    //     int left = 0, right = 0;
    //     int count = 0;
    //     int curSum = 0;
    //     while (right < size) {
    //         while (curSum < k && right < size) {
    //             curSum += nums[right];
    //             right++;
    //         }
            
    //         while (curSum >= k && left <= right) {
    //             if (curSum == k) ++count;
    //             curSum -= nums[left];
    //             left++;
    //         }
    //     }
    //     return count;
    // }

    // prefix sum: O(n^2)
    // int subarraySum(vector<int>& nums, int k) {
    //     int size = nums.size();
    //     int count = 0;
    //     vector<int> preSum(size+1, 0);
    //     for (int i = 0; i < size; i++) {
    //         preSum[i+1] = preSum[i] + nums[i];
    //     }
    //     for (int i = 0; i < size; i++) {
    //         for (int j = i+1; j <= size; j++) {
    //             if (preSum[j] - preSum[i] == k) {
    //                 ++count;
    //             }
    //         }
    //     }
    //     return count;
    // }

    // hash map: O(n)
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        int count = 0;
        unordered_map<int, int> hash_preSum;
        hash_preSum[0] = 1;
        vector<int> preSum(size+1, 0);
        for (int i = 0; i < size; i++) {
            preSum[i+1] = preSum[i] + nums[i];
            if (hash_preSum.find(preSum[i+1] - k) != hash_preSum.end()) {
                count += hash_preSum[preSum[i+1] - k];
            }
            
            if (hash_preSum.find(preSum[i+1]) != hash_preSum.end()) {
                hash_preSum[preSum[i+1]]++;
            } else {
                hash_preSum[preSum[i+1]] = 1;
            }
        }
        
        return count;
    }
};
// @lc code=end

