/*
 * @lc app=leetcode.cn id=56 lang=cpp
 * @lcpr version=30204
 *
 * [56] 合并区间
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
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> result;
        ranges::sort(intervals, [](const vector<int> &x, const vector<int> &y)->bool {
            return x[0] < y[0];
        });
        
        int index = 0;
        while (index < intervals.size()) {
            int partial_min = intervals[index][0];
            int partial_max = intervals[index][1];
            index++;
            while (index < intervals.size() && intervals[index][0] <= partial_max) {
                partial_max = max(partial_max, intervals[index][1]);
                index++;
            }
            result.push_back({partial_min, partial_max});
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,3],[2,6],[8,10],[15,18]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[4,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,7],[1,4]]\n
// @lcpr case=end

 */
