/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
#include <vector>
using namespace std;

// greedy strategy: each time we jump to the point which has the longest jumping capability
class Solution {
public:
    int counter = 0;
    int jump(vector<int>& nums) {
        int pos = 0;
        int capability = nums[pos];

        int nextPos = 1;
        int nextCap = nums[nextPos];
        int cursor = 1;
        while (pos != nums.size() - 1) {
            nextPos = pos;
            nextCap = 0;
            cursor = 1;
            while (capability--) {
                if (pos + cursor == nums.size() - 1) return ++counter;
                if (nums[pos + cursor] + cursor > nextCap + nextPos - pos) {
                    nextPos = pos + cursor;
                    nextCap = nums[nextPos];
                }
                cursor++;
            }
            pos = nextPos;
            capability = nums[pos];
            counter++;
        }

        return counter;
    }
};
// @lc code=end

