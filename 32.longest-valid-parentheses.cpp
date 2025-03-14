/*
 * @lc app=leetcode.cn id=32 lang=cpp
 * @lcpr version=30202
 *
 * [32] 最长有效括号
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
#include <cstring>
// @lcpr-template-end
// @lc code=start
// dp O(n) O(n)
class Solution
{
public:
//     // dp[i] = 0 if s[i] == '('
//     // dp[i] = dp[i-2]+2 if s[i]=')' and s[i-1]='('
//     // dp[i] = dp[i-1]+dp[i-dp[i-1]-2]+2 if s[i]=')' and s[i-1]=')' and s[i-dp[i-1]-1]='('
//     // dp[i] = 0 if s[i]=')' and s[i-1]=')' and s[i-dp[i-1]-1]=')'
    int longestValidParentheses(string s)
    {

        int n = s.size();
        if (n == 0)
            return 0;
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
                } else {
                    if (i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(') {
                        dp[i] = dp[i-1] + (i-dp[i-1] >= 2 ? dp[i-dp[i-1]-2] : 0) + 2;
                    }
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
// stack O(n) O(n)
// #include <bits/stdc++.h>
// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         int max_len = 0;
//         stack<int> st;
//         int base = -1;
//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] == '(') {
//                 st.push(i);
//             } else {
//                 if (st.empty()) {
//                     base = i;
//                 } else {
//                     st.pop();
//                     if (st.empty()) {
//                         max_len = max(max_len, i - base);
//                     } else {
//                         max_len = max(max_len, i - st.top());
//                     }
//                 }
//             }
//         }
//         return max_len;
//     }
// };
// @lc code=end

/*
// @lcpr case=start
// "(()"\n
// @lcpr case=end

// @lcpr case=start
// ")()())"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

 */
