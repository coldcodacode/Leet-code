/*
 * @lc app=leetcode.cn id=169 lang=cpp
 * @lcpr version=30204
 *
 * [169] 多数元素
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
// 哈希，时间O(n), 空间O(n)
// class Solution
// {
// public:
//     int majorityElement(vector<int> &nums)
//     {
//         unordered_map<int, int> um;
//         for (auto item : nums) {
//             um[item]++;
//         }
//         int max = INT32_MIN;
//         int res = 0;
//         for (auto item : um) {
//             if (item.second > max) {
//                 max = item.second;
//                 res = item.first;
//             }
//         }
//         return res;
//     }
// };
// 只需要找到第n/2+1的元素是哪个就行了
class Solution
{
public:
    int majorityElement(vector<int> &nums) {
        int cnt = 0;
        int majority = 0;
        for (auto item : nums) {
            if (cnt) {
                cnt += (item == majority) ? 1 : -1;
            } else {
                majority = item;
                cnt++;
            }
        }
        return majority;
    } 
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,1,1,1,2,2]\n
// @lcpr case=end

 */
