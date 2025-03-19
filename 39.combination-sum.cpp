/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=30204
 *
 * [39] 组合总和
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
    vector<vector<int>> ans;
    vector<int> tmp;
    void dfs(vector<int> &candidates, int target, size_t left) {
        if (target == 0) {
            ans.push_back(tmp);
            return;
        } else if (target < 0) {
            return;
        }
        if (left >= candidates.size()) {
            return;
        }
        
        tmp.push_back(candidates[left]);
        dfs(candidates, target - candidates[left], left);
        tmp.pop_back();
        dfs(candidates, target, left + 1);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        dfs(candidates, target, 0);
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */
