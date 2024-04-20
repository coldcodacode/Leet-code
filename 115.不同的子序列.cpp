/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
class Solution {
public:
    int numDistinct(string s, string t) {
        int t_size = t.size();
        vector<int> dp(t_size+1, 0);
        dp[0] = 1;

        for (auto ch : s) {
            for (int i = t_size; i >= 1; i--) {
                if (ch == t[i-1]) dp[i] = (dp[i] + dp[i-1]) % mod;
            }
        }
        return dp[t_size];
    }
};
// @lc code=end

