/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0; 
        int right = 0;

        int accumulate = 0;
        int stake = 0;

        while (right != height.size()) {
            while(right != height.size() && height[right] <= height[left]) {
                right++;
            }
            stake = height[left];
            if (right != height.size()) {
                while(left != right) {
                    accumulate += (stake - height[left]);
                    left++;
                }
            }
        }

        int mid = left;
        right--;
        left = right - 1;

        while (right != mid) {
            while(height[left] < height[right]) {
                left--;
            }
            stake = height[right];
            while(left != right) {
                accumulate += (stake - height[right]);
                right--;
            }
            left--;
        }

        return accumulate;
    }
};
// @lc code=end

