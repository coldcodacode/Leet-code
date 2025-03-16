/*
 * @lc app=leetcode.cn id=136 lang=cpp
 * @lcpr version=30204
 *
 * [136] 只出现一次的数字
 */

// @lcpr-template-start
using namespace std;
#include <bits/stdc++.h>
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
// 排序+一遍遍历 O(nlogn) + O(n)
// class Solution
// {
// public:
//     int singleNumber(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end());
//         int tmp = 0;
//         auto it = nums.begin();
//         for ( ; it != nums.end() - 1; it = it + 2) {
//             if (*it != *(it+1)) {
//                 return *it;
//             }
//         }
//         return *it;
//     }
// };
// 异或运算
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int res = 0;
        for (auto item : nums) {
            res = res ^ item;
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,1,2,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
