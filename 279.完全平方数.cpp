/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
#include <limits.h>
#include <iostream>
#include <string.h>
using namespace std;
class Solution {
public:
    
    int numSquares(int n) {
        // greedy category doesnt work: each time we choose the largest squared number possible.
        // There is an instance. 48 = 25 + 16 + 4 + 2 + 1(greedy category)
        // 48 = 16 + 16 + 16

        // dp  dp[n] = max(dp[k] + 1) k is chose from squard numbers possible.
        int* dp = new int[n+1];
        // cout << sizeof(*dp);
        memset(dp, 0x3f, 4*(n+1));
        dp[0] = 0;
        dp[1] = 1;
        // int max = 0;
        int k = 1;
        for (int i = 2; i <= n; i++) {
            while (k * k <= i) {
                dp[i] = (dp[i] > 1 + dp[i-k*k]) ? 1 + dp[i-k*k] : dp[i];
                k++;
            }
            // max = 0;
            k = 1;
        }

        return dp[n];
    }
};

// int main () {
//     Solution* s = new Solution();
//     cout << s->numSquares(12);
// }
// @lc code=end

