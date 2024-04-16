/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
#include <unordered_set>
#include <vector>
#include <utility>
#include <map>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashset; 
        // map<int, pair<int, int> > hashmap;

        for (int i = 0; i < nums.size(); ++i) {
            hashset.insert(nums[i]);
        }

        int longestConsecutive = 0;

        for (int num : hashset) {
            if (!hashset.count(num - 1)) {
                int curConsecutive = 1;
                int curNum = num;

                while (hashset.count(curNum + 1)) {
                    curConsecutive++;
                    curNum++;
                }

                longestConsecutive = max(curConsecutive, longestConsecutive);
            }
        }

        return longestConsecutive;
    }
};
// @lc code=end

