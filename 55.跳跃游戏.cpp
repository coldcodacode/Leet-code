/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int minDistance = 0;
        for (auto it = nums.rbegin(); it != nums.rend(); it++){
            if (*it >= minDistance){
                minDistance = 0;
            }
            minDistance++;
        }
        if (minDistance == 1){
            return true;
        }else {
            return false;
        }
    }
};
// @lc code=end

