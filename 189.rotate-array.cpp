/*
 * @lc app=leetcode.cn id=189 lang=cpp
 * @lcpr version=30204
 *
 * [189] 轮转数组
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
    void rotate(vector<int> &nums, int k)
    {   
        int length = nums.size();
        int targetIdx = 0;
        int curIdx = 0;
        int count = 0;
        for (int start = 0; count < length; start++) {
            curIdx = start;
            int tmp = nums[curIdx];
            do {
                targetIdx = (curIdx + k) % length;
                swap(tmp, nums[targetIdx]);
                count++;
                curIdx = targetIdx;
            } while (curIdx != start);
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [-1,-100,3,99]\n2\n
// @lcpr case=end

 */
