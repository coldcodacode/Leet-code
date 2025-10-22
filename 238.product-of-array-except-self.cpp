/*
 * @lc app=leetcode.cn id=238 lang=cpp
 * @lcpr version=30204
 *
 * [238] 除自身以外数组的乘积
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            int lastMultiVal = i == 0 ? 1 : prefix[i-1];
            prefix[i] = lastMultiVal * nums[i];
        }

        vector<int> suffix(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            int lastMultiVal = i == nums.size() - 1 ? 1 : suffix[i+1];
            suffix[i] = lastMultiVal * nums[i];
        }

        vector<int> res(nums.size());
        for (int i = 0 ; i < nums.size() ; i++) {
            if (i == 0) {
                res[i] = suffix[i+1];
                continue;
            }
            if (i == nums.size() - 1) {
                res[i] = prefix[i-1];
                continue;
            }
            res[i] = prefix[i-1] * suffix[i+1];
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [-1,1,0,-3,3]\n
// @lcpr case=end

 */

