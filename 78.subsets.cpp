/*
 * @lc app=leetcode.cn id=78 lang=cpp
 * @lcpr version=30204
 *
 * [78] 子集
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
class Solution
{
public:
    vector<vector<int>> func(vector<int> &nums, size_t left, size_t right) {
        vector<vector<int>> res;
        if (left > right) {
            return {{}};
        }
        auto sub_state = func(nums, left+1, right);
        for (auto item : sub_state) {
            // res.emplace_back(item.emplace_back(nums[left])); 错误，emplace_back返回void
            item.emplace_back(nums[left]);
            res.emplace_back(item);
        }
        for (auto item : sub_state) {
            res.emplace_back(item);
        }
        return res;
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        res = func(nums, 0, nums.size()-1);
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
